#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n)
{

    if(!s)
    {
        return NULL;
    }

    const unsigned char *value = (const unsigned char *)s;

    for(size_t i = n; i > 0; i--)
    {
        if(value[i - 1] == (unsigned char)c)
        {
            return (void*)(value + i - 1);
        }
    }

    return NULL;
}
