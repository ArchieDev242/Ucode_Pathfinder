#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c)
{
    if(!s)
    {
        return NULL;
    }

    int words = mx_count_words(s, c);

    if(words == 0)
    {
        char **arr = (char **)malloc(sizeof(char *));

        if(arr[0])
        {
            arr[0] = NULL;
        }

        return arr;
    }

    char **arr = (char **)malloc(sizeof(char *) * (words + 1));

    int i = 0, words_index = 0;

    if(!arr)
    {
        return NULL;
    }

    while(s[i] != '\0')
    {
        while(s[i] == c && s[i] != '\0')
        {
            i++;
        }

        int start = i;

        while(s[i]!= c && s[i]!= '\0')
        {
            i++;
        }

        if(i > start)
        {
            arr[words_index] = mx_strndup(s + start, i - start);
            if(arr[words_index] == NULL)
            {
                for(int j = 0; j < words_index; j++)
                {
                    mx_strdel(&arr[j]);
                }
                free(arr);
                return NULL;
            }

            words_index++;
        }
    }

    arr[words_index] = NULL;

    return arr;
}
