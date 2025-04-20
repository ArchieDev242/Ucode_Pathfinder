#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub)
{
    if(str == NULL || sub == NULL)
    {
        return -2;
    }

    char *substrloc = mx_strstr(str, sub);

    if(substrloc != NULL)
    {
        return substrloc - str;
    }

    return -1;
}
