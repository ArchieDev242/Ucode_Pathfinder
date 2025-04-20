#include "../inc/libmx.h"

char *mx_strdup(const char *s1)
{
    if(s1 == NULL)
    {
        return NULL;
    }

    char *str_new = mx_strnew(mx_strlen(s1));

    if(str_new == NULL)
    {
        return NULL;
    }

    mx_strcpy(str_new, s1);

    return str_new;
}
