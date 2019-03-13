//////////////////////////////////////////////////
// Visual C++

// UEFI
#if defined(_MSC_VER) && defined(UEFI)

#if defined(DEBUG)
#define EFI_DEBUG 1
#else
#undef EFI_DEBUG
#endif

#include <il2c_private.h>

#include <stdio.h>
#include <stdarg.h>
#include "debugbreak.h"

#include "efi/efi.h"

int _fltused = 1;

#if defined(NDEBUG)
// Can't enable intrinsic inlined memcpy/memset with VC++'s /GL and /LTCG options in release build.
// So these are simple implementations for thiers.
#pragma function(memcpy, memset)
void* memcpy(void* to, const void* from, size_t n)
{
    uint8_t* t = to;
    const uint8_t* f = from;
    n++;
    while (--n >= 1)
        *t++ = *f++;
    return to;
}

void* memset(void* target, int ch, size_t n)
{
    uint8_t* p = target;
    n++;
    while (--n >= 1)
        *p++ = (uint8_t)ch;
    return target;
}
#endif

bool il2c_twtoi(const wchar_t *_Str, int32_t* value)
{
    char sign = 0;

    for (;; _Str++)
    {
        wchar_t ch = *_Str;
        if ((ch == L' ') || (ch == L'\t'))
        {
            continue;
        }

        if (ch == L'-')
        {
            sign = -1;
            _Str++;
        }
        else if (ch == L'+')
        {
            sign = 1;
            _Str++;
        }
        else if ((*_Str < L'0') || (*_Str > L'9'))
        {
            return false;
        }

        break;
    }

    bool f = false;
    int32_t n = 0;
    while ((*_Str >= L'0') && (*_Str <= L'9'))
    {
        n = n * 10 + *_Str++ - L'0';
        f = true;
    }

    if (!f) return false;

    if (sign != 0) *value = sign * n;
    else *value = n;

    return true;
}

wchar_t* il2c_itow(int32_t value, wchar_t* d, int radix)
{
    // TODO: supported only 10 radix format.
    il2c_assert(radix == 10);

    wchar_t *p = d;
    wchar_t *j;
    wchar_t b[6];

    if (value < 0)
    {
        *p++ = L'-';
        value = -value;
    }

    j = &b[5];
    *j-- = 0;

    do
    {
        *j-- = value % 10 + L'0';
        value /= 10;
    } while (value);

    do
    {
        *p++ = *++j;
    } while (*j);

    return d;
}

int32_t* il2c_errno__(void)
{
    static int eno = 0;
    return &eno;
}

// From musl: http://git.musl-libc.org/cgit/musl/tree/src/math/fmod.c
double il2c_fmod(double x, double y)
{
    union { double f; uint64_t i; } ux, uy;
    ux.f = x;
    uy.f = y;
    int ex = ux.i >> 52 & 0x7ff;
    int ey = uy.i >> 52 & 0x7ff;
    int sx = ux.i >> 63;
    uint64_t i;

    /* in the followings uxi should be ux.i, but then gcc wrongly adds */
    /* float load/store to inner loops ruining performance and code size */
    uint64_t uxi = ux.i;

    if (uy.i << 1 == 0 || /* isnan(y) || */ ex == 0x7ff)
        return (x*y) / (x*y);
    if (uxi << 1 <= uy.i << 1) {
        if (uxi << 1 == uy.i << 1)
            return 0 * x;
        return x;
    }

    /* normalize x and y */
    if (!ex) {
        for (i = uxi << 12; i >> 63 == 0; ex--, i <<= 1);
        uxi <<= -ex + 1;
    }
    else {
        uxi &= -1ULL >> 12;
        uxi |= 1ULL << 52;
    }
    if (!ey) {
        for (i = uy.i << 12; i >> 63 == 0; ey--, i <<= 1);
        uy.i <<= -ey + 1;
    }
    else {
        uy.i &= -1ULL >> 12;
        uy.i |= 1ULL << 52;
    }

    /* x mod y */
    for (; ex > ey; ex--) {
        i = uxi - uy.i;
        if (i >> 63 == 0) {
            if (i == 0)
                return 0 * x;
            uxi = i;
        }
        uxi <<= 1;
    }
    i = uxi - uy.i;
    if (i >> 63 == 0) {
        if (i == 0)
            return 0 * x;
        uxi = i;
    }
    for (; uxi >> 52 == 0; uxi <<= 1, ex--);

    /* scale result */
    if (ex > 0) {
        uxi -= 1ULL << 52;
        uxi |= (uint64_t)ex << 52;
    }
    else {
        uxi >>= -ex + 1;
    }
    uxi |= (uint64_t)sx << 63;
    ux.i = uxi;
    return ux.f;
}

// From NetBSD: http://cvsweb.netbsd.org/bsdweb.cgi/src/lib/libc/locale/__wctoint.h?rev=1.1&content-type=text/x-cvsweb-markup&only_with_tag=MAIN
static int __wctoint(wchar_t wc)
{
    int n;

    /* XXX I expect compiler to optimize this. :D */
    switch (wc) {
    case L'0': n = 0; break;
    case L'1': n = 1; break;
    case L'2': n = 2; break;
    case L'3': n = 3; break;
    case L'4': n = 4; break;
    case L'5': n = 5; break;
    case L'6': n = 6; break;
    case L'7': n = 7; break;
    case L'8': n = 8; break;
    case L'9': n = 9; break;
    case L'A': case L'a': n = 10; break;
    case L'B': case L'b': n = 11; break;
    case L'C': case L'c': n = 12; break;
    case L'D': case L'd': n = 13; break;
    case L'E': case L'e': n = 14; break;
    case L'F': case L'f': n = 15; break;
    case L'G': case L'g': n = 16; break;
    case L'H': case L'h': n = 17; break;
    case L'I': case L'i': n = 18; break;
    case L'J': case L'j': n = 19; break;
    case L'K': case L'k': n = 20; break;
    case L'L': case L'l': n = 21; break;
    case L'M': case L'm': n = 22; break;
    case L'N': case L'n': n = 23; break;
    case L'O': case L'o': n = 24; break;
    case L'P': case L'p': n = 25; break;
    case L'Q': case L'q': n = 26; break;
    case L'R': case L'r': n = 27; break;
    case L'S': case L's': n = 28; break;
    case L'T': case L't': n = 29; break;
    case L'U': case L'u': n = 30; break;
    case L'V': case L'v': n = 31; break;
    case L'W': case L'w': n = 32; break;
    case L'X': case L'x': n = 33; break;
    case L'Y': case L'y': n = 34; break;
    case L'Z': case L'z': n = 35; break;
    default: n = -1; break; /* error */
    }

    return n;
}

// From NetBSD: http://cvsweb.netbsd.org/bsdweb.cgi/src/lib/libc/locale/_wcstol.h?rev=1.6&content-type=text/x-cvsweb-markup&only_with_tag=MAIN
#define il2c_iswspace(ch) (ch == 0x20)  // easy way
long il2c_wcstol(const wchar_t *nptr, wchar_t **endptr, int base)
{
    const wchar_t *s;
    long acc, cutoff;
    wint_t wc;
    int i;
    int neg, any, cutlim;

    il2c_assert(nptr != NULL);
    /* endptr may be NULL */

    il2c_errno = 0;

    /* check base value */
    if (base && (base < 2 || base > 36)) {
        il2c_errno = EINVAL;
        return 0;
    }

    /*
     * Skip white space and pick up leading +/- sign if any.
     * If base is 0, allow 0x for hex and 0 for octal, else
     * assume decimal; if base is already 16, allow 0x.
     */
    s = nptr;
    do {
        wc = (wchar_t)*s++;
    } while (il2c_iswspace(wc));
    if (wc == L'-') {
        neg = 1;
        wc = *s++;
    }
    else {
        neg = 0;
        if (wc == L'+')
            wc = *s++;
    }
    if ((base == 0 || base == 16) &&
        wc == L'0' && (*s == L'x' || *s == L'X')) {
        wc = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
        base = wc == L'0' ? 8 : 10;

    /*
     * See strtol for comments as to the logic used.
     */
    cutoff = neg ? LONG_MIN : LONG_MAX;
    cutlim = (int)(cutoff % base);
    cutoff /= base;
    if (neg) {
        if (cutlim > 0) {
            cutlim -= base;
            cutoff += 1;
        }
        cutlim = -cutlim;
    }
    for (acc = 0, any = 0;; wc = (wchar_t)*s++) {
        i = __wctoint(wc);
        if (i == -1)
            break;
        if (i >= base)
            break;
        if (any < 0)
            continue;
        if (neg) {
            if (acc < cutoff || (acc == cutoff && i > cutlim)) {
                any = -1;
                acc = LONG_MIN;
                il2c_errno = ERANGE;
            }
            else {
                any = 1;
                acc *= base;
                acc -= i;
            }
        }
        else {
            if (acc > cutoff || (acc == cutoff && i > cutlim)) {
                any = -1;
                acc = LONG_MAX;
                il2c_errno = ERANGE;
            }
            else {
                any = 1;
                acc *= base;
                acc += i;
            }
        }
    }
    if (endptr != 0)
        *endptr = (void*)(const void*)(any ? s - 1 : nptr);
    return (acc);
}

//////////////////////////////////////////////////////////
// These functions use the UEFI services.

static EFI_SYSTEM_TABLE* g_pSystemTable = NULL;

void* il2c_malloc(size_t _Size)
{
    il2c_assert(g_pSystemTable != NULL);

    void* ppAllocated = NULL;
    if (g_pSystemTable->BootServices->AllocatePool(
        EfiLoaderData, _Size, &ppAllocated) == EFI_SUCCESS)
    {
        return ppAllocated;
    }
    else
    {
        return NULL;
    }
}

void il2c_free(void* _Block)
{
    il2c_assert(g_pSystemTable != NULL);

    g_pSystemTable->BootServices->FreePool(_Block);
}

static EFI_EVENT g_TimerEvent = NULL;

void il2c_sleep(uint32_t milliseconds)
{
    il2c_assert(g_pSystemTable != NULL);

    UINTN index;

    // TODO: Will cause race condition if use multithreading environment.
    if (g_TimerEvent == NULL)
    {
        g_pSystemTable->BootServices->CreateEvent(
            EVT_TIMER, 0, NULL, NULL, &g_TimerEvent);
        il2c_assert(g_TimerEvent != NULL);
    }

    g_pSystemTable->BootServices->SetTimer(
        g_TimerEvent, TimerRelative, (uint64_t)milliseconds * 1000);
    g_pSystemTable->BootServices->WaitForEvent(1, &g_TimerEvent, &index);
}

void il2c_debug_write__(const wchar_t* message)
{
    g_pSystemTable->StdErr->OutputString(g_pSystemTable->StdErr, (CHAR16*)message);
}

#if defined(_DEBUG)
void il2c_assert__(const char* pFile, int line, const char* pExpr)
{
    if ((pFile != NULL) && (g_pSystemTable != NULL))
    {
        wchar_t buffer[12];
        il2c_itow(line, buffer, 10);

        int32_t length1 = il2c_get_utf8_length(pFile, false);
        int32_t length2 = (int32_t)il2c_wcslen(buffer);
        int32_t length3 = il2c_get_utf8_length(pExpr, false);
        wchar_t* il2c_mcalloc(pBuffer, (length1 + length2 + length3 + 7) * sizeof(wchar_t));
        wchar_t* pLast = il2c_utf16_from_utf8_and_get_last(pBuffer, pFile);
        *pLast++ = L'(';
        memcpy(pLast, buffer, length2 * sizeof(wchar_t));
        pLast += length2;
        *pLast++ = L')';
        *pLast++ = L':';
        *pLast++ = L' ';
        pLast = il2c_utf16_from_utf8_and_get_last(pLast, pExpr);
        *pLast++ = L'\r';
        *pLast++ = L'\n';
        *pLast = L'\0';

        g_pSystemTable->StdErr->OutputString(g_pSystemTable->StdErr, pBuffer);

        il2c_mcfree(pBuffer);
    }

    debug_break();
}
#endif

void il2c_write(const wchar_t* s)
{
    il2c_assert(s != NULL);
    il2c_assert(g_pSystemTable != NULL);

    g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, (CHAR16*)s);
}

void il2c_writeline(const wchar_t* s)
{
    il2c_assert(s != NULL);
    il2c_assert(g_pSystemTable != NULL);

    g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, (CHAR16*)s);
    g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, L"\r\n");
}

bool il2c_readline(wchar_t* buffer, int32_t length)
{
    il2c_assert(buffer != NULL);
    il2c_assert(length >= 1);
    il2c_assert(g_pSystemTable != NULL);

    wchar_t tempBuffer[4];

    int32_t index = 0;
    while ((index + 1) < length)
    {
        unsigned long long waitIndex;

        tempBuffer[0] = L'_';
        tempBuffer[1] = CHAR_NULL;
        g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, tempBuffer);

    loop:
        waitIndex = 0;
        g_pSystemTable->BootServices->WaitForEvent(
            1, &(g_pSystemTable->ConIn->WaitForKey), &waitIndex);

        EFI_INPUT_KEY efi_input_key;
        if (g_pSystemTable->ConIn->ReadKeyStroke(
            g_pSystemTable->ConIn, &efi_input_key) != 0)
        {
            goto loop;
        }

        if (efi_input_key.ScanCode != SCAN_NULL)
        {
            goto loop;
        }

        tempBuffer[0] = CHAR_BACKSPACE;
        tempBuffer[1] = L' ';
        tempBuffer[2] = CHAR_BACKSPACE;
        tempBuffer[3] = CHAR_NULL;
        g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, tempBuffer);

        if (efi_input_key.UnicodeChar < 0x20)
        {
            if (efi_input_key.UnicodeChar == CHAR_BACKSPACE)
            {
                if (index >= 1)
                {
                    index--;

                    tempBuffer[0] = CHAR_BACKSPACE;
                    tempBuffer[1] = CHAR_NULL;
                    g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, tempBuffer);
                }
            }
            else if (efi_input_key.UnicodeChar == CHAR_CARRIAGE_RETURN)
            {
                break;
            }

            continue;
        }

        buffer[index++] = efi_input_key.UnicodeChar;

        tempBuffer[0] = efi_input_key.UnicodeChar;
        tempBuffer[1] = CHAR_NULL;
        g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, tempBuffer);
    }

    buffer[index] = CHAR_NULL;

    tempBuffer[0] = CHAR_CARRIAGE_RETURN;
    tempBuffer[1] = CHAR_LINEFEED;
    tempBuffer[2] = CHAR_NULL;
    g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, tempBuffer);

    return true;
}

void il2c_initialize(void* imageHandle, void* pSystemTable)
{
    // Setup interop pointer
    g_pSystemTable = pSystemTable;

    // Disable default auto-reset watchdog timer
    g_pSystemTable->BootServices->SetWatchdogTimer(0, 0, 0, NULL);

    // Clear screen
    g_pSystemTable->ConOut->ClearScreen(g_pSystemTable->ConOut);

    il2c_initialize__();
}

void il2c_shutdown()
{
    il2c_shutdown__();
}

#endif
