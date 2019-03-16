#include <il2c_private.h>

//////////////////////////////////////////////////
// Arduino

#if defined(__GNUC__) && defined(ARDUINO)

// From musl: http://git.musl-libc.org/cgit/musl/tree/src/math/fmod.c
double il2c_fmod(double x, double y)
{
    union { double f; uint64_t i; } ux = { x }, uy = { y };
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

static const wchar_t* g_pHexChars = L"0123456789abcdef";

#define IL2C_DECLARE_INTTOW(name, typeName, utypeName, bufferLength, intOper) \
    wchar_t* name(typeName value, wchar_t* buffer, int radix) { \
        wchar_t temp[bufferLength]; \
        wchar_t *pTemp = &temp[bufferLength - 1]; \
        wchar_t *pBuffer = buffer; \
        utypeName v; \
        *pTemp-- = L'\0'; \
        switch (radix) { \
        case 16: \
            v = (utypeName)value; \
            do { \
                *pTemp-- = g_pHexChars[v % 16]; \
                v /= 16; \
            } while (v); \
            break; \
        default: \
            intOper \
            v = (utypeName)value; \
            do { \
                *pTemp-- = (wchar_t)(v % 10 + L'0'); \
                v /= 10; \
            } while (v); \
            break; \
        } \
        do { \
            *pBuffer++ = *++pTemp; \
        } while (*pTemp); \
        return buffer; \
    }

#define IL2C_DECLARE_INTTOW_INT32_OPERATOR \
    if (value == INT32_MIN) { \
        il2c_wcscpy(buffer, L"-2147483648"); \
        return buffer; \
    } \
    if (value < 0) { \
        *pBuffer++ = L'-'; \
        value = -value; \
    }

#define IL2C_DECLARE_INTTOW_INT64_OPERATOR \
    if (value == INT64_MIN) { \
        il2c_wcscpy(buffer, L"-9223372036854775808"); \
        return buffer; \
    } \
    if (value < 0) { \
        *pBuffer++ = L'-'; \
        value = -value; \
    }

#define IL2C_DECLARE_INTTOW_UINT_OPERATOR

IL2C_DECLARE_INTTOW(il2c_i32tow, int32_t, uint32_t, 14, IL2C_DECLARE_INTTOW_INT32_OPERATOR)
IL2C_DECLARE_INTTOW(il2c_u32tow, uint32_t, uint32_t, 14, IL2C_DECLARE_INTTOW_UINT_OPERATOR)
IL2C_DECLARE_INTTOW(il2c_i64tow, int64_t, uint64_t, 24, IL2C_DECLARE_INTTOW_INT64_OPERATOR)
IL2C_DECLARE_INTTOW(il2c_u64tow, uint64_t, uint64_t, 24, IL2C_DECLARE_INTTOW_UINT_OPERATOR)

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

int32_t* il2c_errno__(void)
{
    static int eno = 0;
    return &eno;
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
long il2c_wtoi32(const wchar_t *nptr, wchar_t **endptr, int base)
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

void il2c_sleep(uint32_t milliseconds)
{
    // TODO:
}

#if defined(_DEBUG)
#include <malloc.h>
void il2c_free(void* p)
{
    if (p)
    {
        // Overwrite invalid signature to target memory.
        // (For debugging purpose same as VC++ runtime.)
        memset(p, 0xdd, malloc_usable_size(p));
        free(p);
    }
}
#endif

void il2c_runtime_debug_log__(const char* message)
{
    il2c_assert(message != NULL);

    int32_t length = il2c_get_utf8_length(message, false);
    wchar_t* il2c_mcalloc(pBuffer, (length + 3) * sizeof(wchar_t));
    wchar_t* pLast = il2c_utf16_from_utf8_and_get_last(pBuffer, message);
    *pLast++ = L'\r';
    *pLast++ = L'\n';
    *pLast = L'\0';

    // TODO: Serial out
    //g_pSystemTable->StdErr->OutputString(g_pSystemTable->StdErr, pBuffer);

    il2c_mcfree(pBuffer);
}

void il2c_runtime_debug_log_format__(const char* format, ...)
{
    il2c_assert(format != NULL);

    va_list va;

    va_start(va, format);
    // TODO: Serial out
    //g_pSystemTable->StdErr->OutputString(g_pSystemTable->StdErr, pBuffer);
    va_end(va);
}

void il2c_write(const wchar_t* s)
{
    il2c_assert(s != NULL);

    // TODO: Serial out
    //g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, (CHAR16*)s);
}

void il2c_writeline(const wchar_t* s)
{
    il2c_assert(s != NULL);

    // TODO: Serial out
    //g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, (CHAR16*)s);
    //g_pSystemTable->ConOut->OutputString(g_pSystemTable->ConOut, L"\r\n");
}

bool il2c_readline(wchar_t* buffer, int32_t length)
{
    il2c_assert(buffer != NULL);
    il2c_assert(length >= 1);

    return false;
}

void il2c_initialize()
{
    il2c_initialize__();
}

void il2c_shutdown()
{
    il2c_shutdown__();
}

#endif
