#include "../inc/libmx.h"

int mx_count_words(const char *str, char c)
{
    if(str == NULL)
    {
        return -1;
    }

    int count = 0;
    int words = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != c && !words)
        {
            words = 1;
            count++;
        }else if(str[i] == c)
        {
            words = 0;
        }
    }

    return count;
}
