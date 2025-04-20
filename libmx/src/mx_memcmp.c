#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n)
{

    if(!s1 || !s2)
    {
        return -1;
    }

    const unsigned char *value1 = (const unsigned char *)s1;
    const unsigned char *value2 = (const unsigned char *)s2;

    for(size_t i = 0; i < n; i++)
    {
        if(value1[i] != value2[i])
        {
            return value1[i] - value2[i];
        }
    }

    return 0;
}
