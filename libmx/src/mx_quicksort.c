#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right)
{
    int swap = 0;

    if(!arr)
    {
        return -1;
    }

    if(left < right)
    {
        int move_left = left;
        int move_right = right;
        int element_mid = left + (right - left) / 2;
        int element_len = mx_strlen(arr[element_mid]);

        while(left <= right)
        {
            while(mx_strlen(arr[left]) < element_len)
            {
                left++;
            }

            while(mx_strlen(arr[right]) > element_len)
            {
                right--;
            }

            if(left <= right)
            {
                if(left != right)
                {
                    char *temp_swap = arr[left];
                    arr[left] = arr[right];
                    arr[right] = temp_swap;
                    swap++;
                }

                left++;
                right--;
            }
        }

        swap += mx_quicksort(arr, move_left, right);
        swap += mx_quicksort(arr, left, move_right);
    }

    return swap;
}
