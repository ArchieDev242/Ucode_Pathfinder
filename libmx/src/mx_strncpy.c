#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len)
{
    int i;

    if(dst == NULL)
    {
        return NULL;
    }

    for(i = 0; i < len && src[i] != '\0'; i++)
    {
        dst[i] = src[i];
    }

    for(; i < len; i++)
    {
        dst[i] = '\0';
    }

    return dst;
}
