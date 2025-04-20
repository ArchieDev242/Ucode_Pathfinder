#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len)
{
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;

    if(d == s || len == 0)
    {
        return dst;
    }

    if(d > s + len || d < s)
    {
        return mx_memcpy(dst, src, len);
    }

    if(d > s && d < s + len)
    {
        for(size_t i = len; i > 0; i--)
        {
            d[i - 1] = s[i - 1];
        }
    }

    return dst;
}

