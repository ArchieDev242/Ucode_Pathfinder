#include "../inc/libmx.h"

bool mx_isspace(char c)
{
    if(c == ' ' || (c >= '\t' && c <= '\r') || c == '\n' || c == '\v' || c == '\f')
    {
        return true;
    } else
    {
        return false;
    }
}

char *mx_del_extra_spaces(const char *str) 
{
    if(str == NULL) 
    {
        return NULL;
    }

    char *trimmed = mx_strtrim(str);
    char *trim_new = mx_strnew(mx_strlen(trimmed));
    int in_word = 0, j = 0;

    if(trimmed == NULL) 
    {
        return NULL;
    }

    if(trim_new == NULL) 
    {
        mx_strdel(&trimmed);
        return NULL;
    }

    for(int i = 0; trimmed[i] != '\0'; i++) 
    {
        if(!mx_isspace(trimmed[i])) 
        {
            trim_new[j++] = trimmed[i];
            in_word = 1;

        } else if(in_word) 
        {
            trim_new[j++] = ' ';
            in_word = 0;

            while(mx_isspace(trimmed[i])) 
            {
                i++;
            }
            
            i--;
        }
    }

    if(j > 0 && trim_new[j - 1] == ' ') 
    {
        trim_new[j - 1] = '\0';
    }

    mx_strdel(&trimmed);
    return trim_new;
}

