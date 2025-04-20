#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) 
{
    if(!str || !sub || !replace) 
    {
        return NULL;
    }

    size_t sub_len = mx_strlen(sub);
    size_t replace_len = mx_strlen(replace);
    size_t new_len = 0;

    if(sub_len == 0) 
    {
        return mx_strdup(str);
    }

    const char *p = str;
    int index = 0;

    while((p = mx_strstr(p, sub)) != NULL) 
    {
        new_len += replace_len;
        p += sub_len;
        index++;
    }

    new_len += mx_strlen(str) - (index * sub_len);

    char *new_str = mx_strnew(new_len);

    if(!new_str) 
    {
        return NULL;
    }

    char *new_str_ptr = new_str;

    while((p = mx_strstr(str, sub)) != NULL) 
    {
        int len_sub = p - str;
        mx_strncpy(new_str_ptr, str, len_sub);
        new_str_ptr += len_sub;

        mx_strcpy(new_str_ptr, replace);
        new_str_ptr += replace_len;

        str = p + sub_len;
    }

    mx_strcpy(new_str_ptr, str);

    return new_str;
}
