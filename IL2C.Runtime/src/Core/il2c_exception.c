#include <il2c_private.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////

typedef void(*il2c_sighandler)(int sig);

#if defined(IL2C_USE_SIGNAL)
il2c_sighandler g_SIGSEGV_saved = SIG_DFL;
#endif

extern IL2C_TLS_INDEX g_TlsIndex__;

/////////////////////////////////////////////////
// Exception special functions

void il2c_link_unwind_target__(IL2C_EXCEPTION_FRAME* pUnwindTarget, IL2C_EXCEPTION_FILTER filter)
{
    il2c_assert(pUnwindTarget != NULL);
    il2c_assert(filter != NULL);

    // TODO: The tcb will always acquired?
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_get_tls_value(g_TlsIndex__);
    il2c_assert(pThreadContext != NULL);

    pUnwindTarget->pFrame = pThreadContext->pFrame;
    pUnwindTarget->ex = NULL;   // Current caught exception
    pUnwindTarget->filter = filter;
    pUnwindTarget->pNext = il2c_ixchgptr(&pThreadContext->pUnwindTarget, pUnwindTarget);
}

void il2c_unlink_unwind_target__(IL2C_EXCEPTION_FRAME* pUnwindTarget)
{
    il2c_assert(pUnwindTarget != NULL);

    IL2C_THREAD_CONTEXT* pThreadContext = il2c_get_tls_value(g_TlsIndex__);
    il2c_assert(pThreadContext != NULL);

    IL2C_EXCEPTION_FRAME* p = il2c_ixchgptr(&pThreadContext->pUnwindTarget, pUnwindTarget->pNext);
    il2c_assert(p == pUnwindTarget);
    (void)p;
}

static il2c_noreturn__ void il2c_do_throw__(
    System_Exception* ex, IL2C_EXCEPTION_FRAME* pTargetFrame, int16_t filterNumber, IL2C_THREAD_CONTEXT* pThreadContext)
{
    il2c_assert(ex != NULL);
    il2c_assert(pTargetFrame != NULL);
    il2c_assert(pThreadContext != NULL);

    // Update current exception frame.
    pTargetFrame->ex = ex;
    pThreadContext->pUnwindTarget = pTargetFrame;

    // Update execution frame.
    pThreadContext->pFrame = pTargetFrame->pFrame;

    // Transision to target handler.
    il2c_longjmp((void*)pTargetFrame->saved, filterNumber);
}

static il2c_noreturn__ void il2c_throw_internal__(
    System_Exception* ex, IL2C_EXCEPTION_FRAME* pTargetFrame, IL2C_THREAD_CONTEXT* pThreadContext)
{
    il2c_assert(ex != NULL);
    il2c_assert(pThreadContext != NULL);

    IL2C_EXCEPTION_FRAME* pFrame = pTargetFrame;
    IL2C_EXCEPTION_FRAME* pFinallyFrame = NULL;

    while (il2c_likely__(pFrame != NULL))
    {
        il2c_assert(pFrame->filter != NULL);
        il2c_assert(pFrame->pFrame != NULL);

        int16_t filterNumber = pFrame->filter(ex);

        // Found finally block
        if (il2c_unlikely__(filterNumber == IL2C_FILTER_FINALLY))
        {
            // Memoize finally frame
            if (pFinallyFrame == NULL)
            {
                pFinallyFrame = pFrame;
            }
        }
        else if (il2c_unlikely__(filterNumber != IL2C_FILTER_NOMATCH))
        {
            // Already found finally block
            if (il2c_likely__(pFinallyFrame != NULL))
            {
                // Send to finally
                il2c_do_throw__(ex, pFinallyFrame, IL2C_FILTER_FINALLY, pThreadContext);
            }
            else
            {
                // NOTE: This place is the first-chance.
                // Send to catch
                il2c_do_throw__(ex, pFrame, filterNumber, pThreadContext);
            }
        }

        // Not matched: next frame.
        pFrame = pFrame->pNext;
    }

    // Already found finally block
    if (il2c_likely__(pFinallyFrame != NULL))
    {
        // Send to finally
        il2c_do_throw__(ex, pFinallyFrame, IL2C_FILTER_FINALLY, pThreadContext);
    }

    // Unhandled exception
    il2c_runtime_debug_log_format(
        L"Throw unhandled exception: type={0:s}, Message=\"{1:S}\"",
        (il2c_get_header__(ex))->type->pTypeName,
        (ex->message__->string_body__ != NULL) ? ex->message__->string_body__ : L"");

    il2c_invoke_unhandled_exception_on_the_current_domain__((System_Object*)ex);

#if defined(IL2C_USE_LINE_INFORMATION)
    il2c_break__(__FILE__, __LINE__);
#else
    il2c_break__();
#endif

    il2c_assert(0);
}

il2c_noreturn__ void il2c_throw__(System_Exception* ex)
{
    il2c_assert(ex != NULL);

    IL2C_THREAD_CONTEXT* pThreadContext = il2c_get_tls_value(g_TlsIndex__);
    il2c_assert(pThreadContext != NULL);

    // If this state is inside for caught block, skip current frame.
    // (Throwing new exception instance)
    IL2C_EXCEPTION_FRAME* pFrame =
        (pThreadContext->pUnwindTarget != NULL) ?
            ((pThreadContext->pUnwindTarget->ex != NULL) ? pThreadContext->pUnwindTarget->pNext : pThreadContext->pUnwindTarget) :
        NULL;

    il2c_throw_internal__(ex, pFrame, pThreadContext);
}

il2c_noreturn__ void il2c_rethrow(void)
{
    IL2C_THREAD_CONTEXT* pThreadContext = il2c_get_tls_value(g_TlsIndex__);
    il2c_assert(pThreadContext != NULL);

    il2c_assert(pThreadContext->pUnwindTarget != NULL);

    // If this state is inside for caught block
    if (il2c_likely__(pThreadContext->pUnwindTarget->ex != NULL))
    {
        // Unwind one frame.
        System_Exception* ex = pThreadContext->pUnwindTarget->ex;
        (void)il2c_ixchgptr(&pThreadContext->pUnwindTarget, pThreadContext->pUnwindTarget->pNext);

        // Throw with this exception
        il2c_throw_internal__(ex, pThreadContext->pUnwindTarget, pThreadContext);
    }

    // Search nearest caught exception
    IL2C_EXCEPTION_FRAME* pFrame = pThreadContext->pUnwindTarget->pNext;
    while (il2c_likely__(pFrame != NULL))
    {
        // Found.
        System_Exception* ex = pFrame->ex;
        if (il2c_unlikely__(ex != NULL))
        {
            // Throw with this exception (at the current frame)
            il2c_throw_internal__(ex, pThreadContext->pUnwindTarget, pThreadContext);
        }
        pFrame = pFrame->pNext;
    }

#if defined(IL2C_USE_LINE_INFORMATION)
    il2c_break__(__FILE__, __LINE__);
#else
    il2c_break__();
#endif

    // InvalidProgramException
    il2c_assert(0);
}

#if defined(IL2C_USE_SIGNAL)
il2c_noreturn__ void il2c_SIGSEGV_handler(int sig)
{
    // NOTE 1:
    //   Run in windows, this handler called from SEH filter context from "_seh_filter_exe()".
    //   The SEH __try - __except() block contains at "__scrt_common_main_seh(),"
    //   the callgraph is:
    //     __scrt_common_main_seh() --> __try --> main() --> [SEGV] --> __except() --> _seh_filter_exe() --> handler()
    //   But the "__except(...)" expression has correct only EBP register except ESP register (!!)
    //   Therefore the "_seh_filter_exe()" called before NO any unroll stacks,
    //   the "handler()" function at deeper stack than "main(),"
    //   We can use the longjmp() and unwinding without any stack corruption.
    //   https://gist.github.com/kekyo/cc9bace942b8c2aa2484431e047d267d

    // NOTE 2:
    //   This handler allocate the NullReferenceException and finally unwind using the longjmp(),
    //   it's dangerous for some situations.
    //   For example, we'll call the "malloc()" function and if it causes SEGV (invalid pointer access) at inside malloc
    //   by the unknown issue, context is maybe unstable condition and will jump to this handler and
    //   the handler call malloc() function recursivity.
    //   It situation, all function will break and unstable our code.
    //   The IL2C currently NOT recovery it state, we'll approach for this problem:
    //     * We have to do not cause any SEGV issue at our using C runtime functions.
    //     * Unhook the handler before enter P/Invoke or external functions and
    //       rehook the handler after leave P/Invoke or external functions.
    //   These external functions may cause unknown problem and cause SEGV, we can't recover it state.
    //   https://wiki.sei.cmu.edu/confluence/display/c/SIG30-C.+Call+only+asynchronous-safe+functions+within+signal+handlers

    // Re-register
    signal(SIGSEGV, il2c_SIGSEGV_handler);

    il2c_throw_nullreferenceexception__();
}
#endif

///////////////////////////////////////////////////////
// Basis exceptions

IL2C_CONST_STRING(il2c_null_reference_message, L"Object reference not set to an instance of an object.");

il2c_noreturn__ void il2c_throw_nullreferenceexception__(void)
{
    // TODO: can turn to static allocate for NullReferenceException?
    System_NullReferenceException* ex = il2c_get_uninitialized_object(System_NullReferenceException);
    System_NullReferenceException__ctor__System_String(ex, il2c_null_reference_message);
    il2c_throw(ex);
}

// NOTE: Hmm, the unbox failed message different to the castclass opcode...
//   IL2C choices short sentence by unbox operator message because better footprint.
//   .NET 4 castclass message format: "Unable to cast object of type 'Foo.Bar' to type 'System.String'."
IL2C_CONST_STRING(il2c_invalid_cast_message, L"Specified cast is not valid.");

il2c_noreturn__ void il2c_throw_invalidcastexception__(void)
{
    System_InvalidCastException* ex = il2c_get_uninitialized_object(System_InvalidCastException);
    System_InvalidCastException__ctor__System_String(ex, il2c_invalid_cast_message);
    il2c_throw(ex);
}

IL2C_CONST_STRING(il2c_index_out_of_range_message, L"Index was outside the bounds of the array.");

il2c_noreturn__ void il2c_throw_indexoutofrangeexception__(void)
{
    System_IndexOutOfRangeException* ex = il2c_get_uninitialized_object(System_IndexOutOfRangeException);
    System_IndexOutOfRangeException__ctor__System_String(ex, il2c_index_out_of_range_message);
    il2c_throw(ex);
}

IL2C_CONST_STRING(il2c_format_message, L"Input string was not in a correct format.");

il2c_noreturn__ void il2c_throw_formatexception__(void)
{
    System_FormatException* ex = il2c_get_uninitialized_object(System_FormatException);
    System_FormatException__ctor__System_String(ex, il2c_format_message);
    il2c_throw(ex);
}
