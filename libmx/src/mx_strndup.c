#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n)
{
    if(s1 == NULL)
    {
        return NULL;
    }

    size_t len = mx_strlen(s1);
    size_t lencpy = (len < n) ? len : n;

    char *dup = mx_strnew(lencpy);

    if(dup == NULL)
    {
        return NULL;
    }

    mx_strncpy(dup, s1, lencpy);
    dup[lencpy] = '\0';

    return dup;
}
