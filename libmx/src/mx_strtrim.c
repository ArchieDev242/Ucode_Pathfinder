#include "../inc/libmx.h"

extern bool mx_isspace(char c);

char *mx_strtrim(const char *str) 
{
    if(str == NULL)
    {
        return NULL;
    }

    int start = 0;
    int end = mx_strlen(str) - 1;

    while(start <= end && mx_isspace(str[start]))
    {
        start++;
    }

    while(start <= end && mx_isspace(str[end]))
    {
        end--;
    }

    char *trimmed = mx_strnew(end - start + 1);

    if(trimmed == NULL)
    {
        return NULL;
    }

    mx_strncpy(trimmed, str + start, end - start + 1);

    return trimmed;
}
