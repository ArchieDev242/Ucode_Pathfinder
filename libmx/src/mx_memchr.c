#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n)
{
    if(!s)
    {
        return NULL;
    }

    const unsigned char *value = (const unsigned char *)s;
    
    for(size_t i = 0; i < n; i++)
    {
        if(value[i] == (unsigned char)c)
        {
            return (void*)(value + i);
        }
    }

    return NULL;
}

