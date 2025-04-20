#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle)
{
    const char *h = haystack;
    const char *n = needle;

    if(*n == '\0')
    {
        return (char *)h;
    }

    while(*h != '\0')
    {
        const char *temp_h = h;
        const char *temp_n = n;

        while(*temp_h!= '\0' && *temp_n!= '\0' && *temp_h == *temp_n)
        {
            temp_h++;
            temp_n++;
        }

        if(*temp_n == '\0')
        {
            return (char *)h;
        }

        h++;
    }

    return NULL;
}
