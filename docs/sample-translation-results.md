
# Other sample translation results

Basic structure hints:

* "The execution frame (IL2C_EXECUTION_FRAME)" is the method's local variable holder structure. It's required for IL2C because the garbage collector has to track the reference types (objref / 'O' type), it uses for the tether by these frame structure links.
* "IL2C_CONST_STRING" is the literal string declarator. The statically-defined strings don't (can't) change it from one to entire characters. IL2C places the strings into ".rdata" section on the native binary. It's helpful for the very tiny systems.

## Hello world

C# code:

```csharp
public static class HelloWorld
{
    public static void Main()
    {
        Console.WriteLine("Hello world with IL2C!");
    }
}
```

Results:

```c
//////////////////////////////////////////////////////////////////////////////////
// [9-1] Const strings:

IL2C_CONST_STRING(string0__, L"Hello world with IL2C!");

///////////////////////////////////////
// [3] HelloWorld.Main()

//-------------------
// [3-2] Function body:

void HelloWorld_Main()
{
    //-------------------
    // [3-5] Setup execution frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext__;
        uint16_t objRefCount__;
        uint16_t valueCount__;
        System_String* stack0_0__;
    } frame__ = { NULL, 1, 0 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldstr "Hello world with IL2C!" */
    frame__.stack0_0__ = string0__;
    /* IL_0006: call System.Console.WriteLine */
    System_Console_WriteLine_10(frame__.stack0_0__);
    /* IL_000b: nop  */
    /* IL_000c: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}
```

## The type detection

[From unit test for System.String (IL):](https://github.com/kekyo/IL2C/blob/4dbbd9cf62efb1c1fce6674db393611600d0ecdf/tests/IL2C.Core.Test.Target/BasicTypes/System_String/System_String.il#L3)

```csharp
.class public IL2C.BasicTypes.System_String
{
    .method public static bool IsValueType() cil managed
    {
        .maxstack 2
        ldstr "ABC"
        isinst [mscorlib]System.ValueType
        brfalse.s F1
        ldc.i4.1
        ret
    F1:
        ldc.i4.0
        ret
    }
}
```

Results:

```c
//////////////////////////////////////////////////////////////////////////////////
// [9-1] Const strings:

IL2C_CONST_STRING(string0__, L"ABC");

///////////////////////////////////////
// [3] IL2C.BasicTypes.System_String.IsValueType()

//-------------------
// [3-2] Function body:

bool IL2C_BasicTypes_System_String_IsValueType()
{
    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_2__;

    //-------------------
    // [3-5] Setup execution frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext__;
        uint16_t objRefCount__;
        uint16_t valueCount__;
        System_String* stack0_0__;
        System_ValueType* stack0_1__;
    } frame__ = { NULL, 2, 0 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldstr "ABC" */
    frame__.stack0_0__ = string0__;
    /* IL_0005: isinst System.ValueType */
    frame__.stack0_1__ = il2c_isinst(frame__.stack0_0__, System_ValueType);
    /* IL_000a: brfalse.s IL_000e */
    if (frame__.stack0_1__ == NULL) goto IL_000e;
    /* IL_000c: ldc.i4.1  */
    stack0_2__ = 1;
    /* IL_000d: ret  */
    il2c_unlink_execution_frame(&frame__);
    return (stack0_2__) ? true : false;
IL_000e:
    /* IL_000e: ldc.i4.0  */
    stack0_2__ = 0;
    /* IL_000f: ret  */
    il2c_unlink_execution_frame(&frame__);
    return (stack0_2__) ? true : false;
}
```

## Array initializer and accessor

[From unit test for ArrayTypes (C#):](https://github.com/kekyo/IL2C/blob/4dbbd9cf62efb1c1fce6674db393611600d0ecdf/tests/IL2C.Core.Test.Target/RuntimeSystems/ArrayTypes/ArrayTypes.cs#L79)

```csharp
public static int FromInt32Resource(int index)
{
    // This expression invokes to System.Runtime.CompilerServices.RuntimeHelpers::InitializeArray().
    var arr = new int[] { 1111111, -2222222, 3333333 };

    return arr[index];
}
```

Results:

```c
//////////////////////////////////////////////////////////////////////////////////
// [12-1] Declared values:

// .<PrivateImplementationDetails>.A2DA5F440229B0AE98EE7F86844A4AB5B0936C8E
static const int32_t declaredValue0__[] =
    { 1111111, -2222222, 3333333 };

///////////////////////////////////////
// [3] IL2C.RuntimeSystems.ArrayTypes.FromInt32Resource(System.Int32 index)

//-------------------
// [3-2] Function body:

int32_t IL2C_RuntimeSystems_ArrayTypes_FromInt32Resource(int32_t index)
{
    //-------------------
    // [3-3] Local variables (!objref):

    int32_t local1__;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_0__;
    int32_t stack1_1__;
    System_RuntimeFieldHandle stack2_0__;

    //-------------------
    // [3-5] Setup execution frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext__;
        uint16_t objRefCount__;
        uint16_t valueCount__;
        il2c_arraytype(System_Int32)* local0__;
        il2c_arraytype(System_Int32)* stack0_1__;
        il2c_arraytype(System_Int32)* stack1_0__;
    } frame__ = { NULL, 3, 0 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: ldc.i4.3  */
    stack0_0__ = 3;
    /* IL_0002: newarr System.Int32 */
    frame__.stack0_1__ = il2c_new_array(System_Int32, stack0_0__);
    /* IL_0007: dup  */
    frame__.stack1_0__ = frame__.stack0_1__;
    /* IL_0008: ldtoken .<PrivateImplementationDetails>.A2DA5F440229B0AE98EE7F86844A4AB5B0936C8E */
    stack2_0__.size__ = sizeof(declaredValue0__);
    stack2_0__.field__ = declaredValue0__;
    /* IL_000d: call System.Runtime.CompilerServices.RuntimeHelpers.InitializeArray */
    System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray((System_Array*)frame__.stack1_0__, stack2_0__);
    /* IL_0012: stloc.0  */
    frame__.local0__ = frame__.stack0_1__;
    /* IL_0013: ldloc.0  */
    frame__.stack0_1__ = frame__.local0__;
    /* IL_0014: ldarg.0  */
    stack1_1__ = index;
    /* IL_0015: ldelem.i4  */
    stack0_0__ = il2c_array_item(frame__.stack0_1__, int32_t, stack1_1__);
    /* IL_0016: stloc.1  */
    local1__ = stack0_0__;
    /* IL_0017: br.s IL_0019 */
    goto IL_0019;
IL_0019:
    /* IL_0019: ldloc.1  */
    stack0_0__ = local1__;
    /* IL_001a: ret  */
    il2c_unlink_execution_frame(&frame__);
    return stack0_0__;
}
```

## Null reference access

[From unit test for NullReferenceExceptions (C#):](https://github.com/kekyo/IL2C/blob/4dbbd9cf62efb1c1fce6674db393611600d0ecdf/tests/IL2C.Core.Test.Target/RuntimeSystems/ExceptionThrownByCLI/NullReferenceExceptions.cs#L15)


```csharp
public static bool NullReference(object v)
{
    try
    {
        var r = v.ToString();
    }
    catch (NullReferenceException ex)
    {
        return ex.Message == "Object reference not set to an instance of an object.";
    }
    return false;
}
```

Results:

```c
//////////////////////////////////////////////////////////////////////////////////
// [9-1] Const strings:

IL2C_CONST_STRING(string0__, L"Object reference not set to an instance of an object.");

///////////////////////////////////////
// [3] IL2C.RuntimeSystems.NullReferenceExceptions.NullReference(System.Object v)

//-------------------
// [3-1] Exception filters:

static int16_t __IL2C_RuntimeSystems_NullReferenceExceptions_NullReference_ExceptionFilter0__(System_Exception* ex)
{
    il2c_assert(ex != NULL);
    if (il2c_isinst_unsafe(ex, System_NullReferenceException)) return 1;
    return IL2C_FILTER_NOMATCH;  // Not matched
}

//-------------------
// [3-2] Function body:

bool IL2C_RuntimeSystems_NullReferenceExceptions_NullReference(System_Object* v)
{
    //-------------------
    // [3-3] Local variables (not objref):

    volatile bool local2__;

    //-------------------
    // [3-4] Evaluation stacks (not objref):

    bool stack0_3__;
    int32_t stack0_4__;

    //-------------------
    // [3-5] Setup execution frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext__;
        uint16_t objRefCount__;
        uint16_t valueCount__;
        System_String* local0__;
        System_NullReferenceException* local1__;
        System_NullReferenceException* stack0_0__;
        System_Object* stack0_1__;
        System_String* stack0_2__;
        System_String* stack1_0__;
    } frame__ = { NULL, 6, 0 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    il2c_try(nest0, __IL2C_RuntimeSystems_NullReferenceExceptions_NullReference_ExceptionFilter0__)
    {
        /* IL_0001: nop  */
        /* IL_0002: ldarg.0  */
        frame__.stack0_1__ = v;
        /* IL_0003: callvirt System.Object.ToString */
        frame__.stack0_2__ = frame__.stack0_1__->vptr0__->ToString((untyped_ptr)frame__.stack0_1__);
        /* IL_0008: stloc.0  */
        frame__.local0__ = frame__.stack0_2__;
        /* IL_0009: nop  */
        /* IL_000a: leave.s IL_0021 */
        il2c_leave(nest0, 0);
    }
    il2c_catch(nest0, 1, frame__.stack0_0__)  // catch (System_NullReferenceException)
    {
        /* IL_000c: stloc.1  */
        frame__.local1__ = frame__.stack0_0__;
        /* IL_000d: nop  */
        /* IL_000e: ldloc.1  */
        frame__.stack0_0__ = frame__.local1__;
        /* IL_000f: callvirt System.Exception.get_Message */
        frame__.stack0_2__ = frame__.stack0_0__->vptr0__->get_Message((untyped_ptr)frame__.stack0_0__);
        /* IL_0014: ldstr "Object reference not set to an instance of an object." */
        frame__.stack1_0__ = string0__;
        /* IL_0019: call System.String.op_Equality */
        stack0_3__ = System_String_op_Equality(frame__.stack0_2__, frame__.stack1_0__);
        /* IL_001e: stloc.2  */
        local2__ = stack0_3__;
        /* IL_001f: leave.s IL_0025 */
        il2c_leave(nest0, 1);
    }
    il2c_leave_to(nest0)
    {
        il2c_leave_bind(nest0, 0, IL_0021);
        il2c_leave_bind(nest0, 1, IL_0025);
    }
    il2c_end_try(nest0);
IL_0021:
    /* IL_0021: ldc.i4.0  */
    stack0_4__ = 0;
    /* IL_0022: stloc.2  */
    local2__ = (stack0_4__) ? true : false;
    /* IL_0023: br.s IL_0025 */
    goto IL_0025;
IL_0025:
    /* IL_0025: ldloc.2  */
    stack0_3__ = local2__;
    /* IL_0026: ret  */
    il2c_unlink_execution_frame(&frame__);
    return stack0_3__;
}
```

## Very complex nested and rethrowed exception handling

[From unit test for ExceptionHandling (C#):](https://github.com/kekyo/IL2C/blob/4dbbd9cf62efb1c1fce6674db393611600d0ecdf/tests/IL2C.Core.Test.Target/RuntimeSystems/ExceptionHandling/ExceptionHandling.cs#L442)

```csharp
public static bool RaiseCaughtAndRethrowOutsideLocal()
{
    var ex1 = new Exception();
    var ex2 = new Exception();
    Exception exi1_ = null;
    Exception exi2_ = null;
    try
    {
        throw ex1;
    }
    catch (Exception exo)
    {
        try
        {
            try
            {
                throw ex2;
            }
            catch (Exception exi2)
            {
                exi2_ = exi2;
            }

            // rethrow ex1
            throw;
        }
        catch (Exception exi1)
        {
            // ex1
            exi1_ = exi1;
        }

        return object.ReferenceEquals(ex1, exo) &&
            object.ReferenceEquals(ex1, exi1_) &&  // ex1
            object.ReferenceEquals(ex2, exi2_);
    }
}
```

Results:

```c
///////////////////////////////////////
// [3] IL2C.RuntimeSystems.ExceptionHandling.RaiseCaughtAndRethrowOutsideLocal()

//-------------------
// [3-1] Exception filters:

static int16_t __IL2C_RuntimeSystems_ExceptionHandling_RaiseCaughtAndRethrowOutsideLocal_ExceptionFilter0__(System_Exception* ex)
{
    il2c_assert(ex != NULL);
    if (il2c_isinst_unsafe(ex, System_Exception)) return 1;
    return IL2C_FILTER_NOMATCH;  // Not matched
}
static int16_t __IL2C_RuntimeSystems_ExceptionHandling_RaiseCaughtAndRethrowOutsideLocal_ExceptionFilter1__(System_Exception* ex)
{
    il2c_assert(ex != NULL);
    if (il2c_isinst_unsafe(ex, System_Exception)) return 1;
    return IL2C_FILTER_NOMATCH;  // Not matched
}
static int16_t __IL2C_RuntimeSystems_ExceptionHandling_RaiseCaughtAndRethrowOutsideLocal_ExceptionFilter2__(System_Exception* ex)
{
    il2c_assert(ex != NULL);
    if (il2c_isinst_unsafe(ex, System_Exception)) return 1;
    return IL2C_FILTER_NOMATCH;  // Not matched
}

//-------------------
// [3-2] Function body:

bool IL2C_RuntimeSystems_ExceptionHandling_RaiseCaughtAndRethrowOutsideLocal()
{
    //-------------------
    // [3-3] Local variables (not objref):

    volatile bool local7__;

    //-------------------
    // [3-4] Evaluation stacks (not objref):

    untyped_ptr stack0_1__;
    int32_t stack0_2__;
    bool stack0_3__;

    //-------------------
    // [3-5] Setup execution frame:

    struct /* IL2C_EXECUTION_FRAME */
    {
        IL2C_EXECUTION_FRAME* pNext__;
        uint16_t objRefCount__;
        uint16_t valueCount__;
        System_Exception* local0__;
        System_Exception* local1__;
        System_Exception* local2__;
        System_Exception* local3__;
        System_Exception* local4__;
        System_Exception* local5__;
        System_Exception* local6__;
        System_Exception* stack0_0__;
        System_Exception* stack1_0__;
    } frame__ = { NULL, 9, 0 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop  */
    /* IL_0001: newobj System.Exception..ctor */
    frame__.stack0_0__ = il2c_get_uninitialized_object(System_Exception);
    System_Exception__ctor(frame__.stack0_0__);
    /* IL_0006: stloc.0  */
    frame__.local0__ = frame__.stack0_0__;
    /* IL_0007: newobj System.Exception..ctor */
    frame__.stack0_0__ = il2c_get_uninitialized_object(System_Exception);
    System_Exception__ctor(frame__.stack0_0__);
    /* IL_000c: stloc.1  */
    frame__.local1__ = frame__.stack0_0__;
    /* IL_000d: ldnull  */
    stack0_1__ = NULL;
    /* IL_000e: stloc.2  */
    frame__.local2__ = (System_Exception*)stack0_1__;
    /* IL_000f: ldnull  */
    stack0_1__ = NULL;
    /* IL_0010: stloc.3  */
    frame__.local3__ = (System_Exception*)stack0_1__;
    il2c_try(nest0, __IL2C_RuntimeSystems_ExceptionHandling_RaiseCaughtAndRethrowOutsideLocal_ExceptionFilter0__)
    {
        /* IL_0011: nop  */
        /* IL_0012: ldloc.0  */
        frame__.stack0_0__ = frame__.local0__;
        /* IL_0013: throw  */
        il2c_throw(frame__.stack0_0__);
    }
    il2c_catch(nest0, 1, frame__.stack0_0__)  // catch (System_Exception)
    {
        /* IL_0014: stloc.s local4__ */
        frame__.local4__ = frame__.stack0_0__;
        /* IL_0016: nop  */
        il2c_try(nest1, __IL2C_RuntimeSystems_ExceptionHandling_RaiseCaughtAndRethrowOutsideLocal_ExceptionFilter1__)
        {
            /* IL_0017: nop  */
            il2c_try(nest2, __IL2C_RuntimeSystems_ExceptionHandling_RaiseCaughtAndRethrowOutsideLocal_ExceptionFilter2__)
            {
                /* IL_0018: nop  */
                /* IL_0019: ldloc.1  */
                frame__.stack0_0__ = frame__.local1__;
                /* IL_001a: throw  */
                il2c_throw(frame__.stack0_0__);
            }
            il2c_catch(nest2, 1, frame__.stack0_0__)  // catch (System_Exception)
            {
                /* IL_001b: stloc.s local5__ */
                frame__.local5__ = frame__.stack0_0__;
                /* IL_001d: nop  */
                /* IL_001e: ldloc.s local5__ */
                frame__.stack0_0__ = frame__.local5__;
                /* IL_0020: stloc.3  */
                frame__.local3__ = frame__.stack0_0__;
                /* IL_0021: nop  */
                /* IL_0022: leave.s IL_0024 */
                il2c_leave(nest2, 1);
            }
            il2c_leave_to(nest2)
            {
                il2c_leave_bind(nest2, 1, IL_0024);
            }
            il2c_end_try(nest2);
        IL_0024:
            /* IL_0024: rethrow  */
            il2c_rethrow();
        }
        il2c_catch(nest1, 1, frame__.stack0_0__)  // catch (System_Exception)
        {
            /* IL_0026: stloc.s local6__ */
            frame__.local6__ = frame__.stack0_0__;
            /* IL_0028: nop  */
            /* IL_0029: ldloc.s local6__ */
            frame__.stack0_0__ = frame__.local6__;
            /* IL_002b: stloc.2  */
            frame__.local2__ = frame__.stack0_0__;
            /* IL_002c: nop  */
            /* IL_002d: leave.s IL_002f */
            il2c_leave(nest1, 0);
        }
        il2c_leave_to(nest1)
        {
            il2c_leave_bind(nest1, 0, IL_002f);
            il2c_leave_bind(nest1, 1, IL_0024);
        }
        il2c_end_try(nest1);
    IL_002f:
        /* IL_002f: ldloc.0  */
        frame__.stack0_0__ = frame__.local0__;
        /* IL_0030: ldloc.s local4__ */
        frame__.stack1_0__ = frame__.local4__;
        /* IL_0032: bne.un.s IL_003e */
        if (frame__.stack0_0__ != frame__.stack1_0__) goto IL_003e;
        /* IL_0034: ldloc.0  */
        frame__.stack0_0__ = frame__.local0__;
        /* IL_0035: ldloc.2  */
        frame__.stack1_0__ = frame__.local2__;
        /* IL_0036: bne.un.s IL_003e */
        if (frame__.stack0_0__ != frame__.stack1_0__) goto IL_003e;
        /* IL_0038: ldloc.1  */
        frame__.stack0_0__ = frame__.local1__;
        /* IL_0039: ldloc.3  */
        frame__.stack1_0__ = frame__.local3__;
        /* IL_003a: ceq  */
        stack0_2__ = ((intptr_t)frame__.stack0_0__ == (intptr_t)frame__.stack1_0__) ? 1 : 0;
        /* IL_003c: br.s IL_003f */
        goto IL_003f;
    IL_003e:
        /* IL_003e: ldc.i4.0  */
        stack0_2__ = 0;
    IL_003f:
        /* IL_003f: stloc.s local7__ */
        local7__ = (stack0_2__) ? true : false;
        /* IL_0041: leave.s IL_0043 */
        il2c_leave(nest0, 2);
    }
    il2c_leave_to(nest0)
    {
        il2c_leave_bind(nest0, 0, IL_002f);
        il2c_leave_bind(nest0, 1, IL_0024);
        il2c_leave_bind(nest0, 2, IL_0043);
    }
    il2c_end_try(nest0);
IL_0043:
    /* IL_0043: ldloc.s local7__ */
    stack0_3__ = local7__;
    /* IL_0045: ret  */
    il2c_unlink_execution_frame(&frame__);
    return stack0_3__;
}
```
