#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count)
{
    int left_part = 0;
    int right_part = size - 1;
    *count = 0;

    while(left_part <= right_part)
    {
        (*count)++;

        int mid_index = left_part + (right_part - left_part) / 2;
        int cmp = mx_strcmp(arr[mid_index], s);

        if(cmp == 0)
        {
            return mid_index;
        }else if(cmp > 0)
        {
            right_part = mid_index - 1;
        }else
        {
            left_part = mid_index + 1;
        }
    }

    *count = 0;
    return -1;
}
