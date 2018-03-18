
#include <stdint.h>
#include <stdbool.h>

// Can't enable intrinsic inlined memcpy/memset with VC++'s /GL and /LTCG options.
// So these are simple implementations for thiers.
void* il2c_memcpy(void* to, const void* from, size_t n)
{
    uint8_t* t = to;
    const uint8_t* f = from;
    n++;
    while (--n >= 1)
        *t++ = *f++;
    return to;
}

void* il2c_memset(void* target, int ch, size_t n)
{
    uint8_t* p = target;
    n++;
    while (--n >= 1)
        *p++ = ch;
    return target;
}

bool twtoi(const wchar_t *_Str, int32_t* value)
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

void itow(int32_t value, wchar_t* p)
{
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
}

char* il2c_itoa(int i, char* d)
{
    char *j, *a = d;
    char b[6];

    if (i < 0)
    {
        *a++ = '-';
        i = -i;
    }
    j = &b[5];
    *j-- = 0;
    do
    {
        *j-- = i % 10 + '0';
        i /= 10;
    } while (i);
    do
    {
        *a++ = *++j;
    } while (*j);

    return d;
}
