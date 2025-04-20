#include "../inc/libmx.h"

void mx_del_strarr(char ***arr)
{
    if(!arr || !*arr)
    {
        return;
    }

    for(int i = 0; (*arr)[i] != NULL; i++)
    {
        free((*arr)[i]);
    }

    free(*arr);
    *arr = NULL;
}
