#include "../inc/libmx.h"

int mx_sqrt(int x)
{
    if(x < 0 || x == 0 || x == 1)
    {
        return x == 1 ? 1 : 0;
    }

    int left_part = 1, right_part = x / 2, middle_num;

    while(left_part <= right_part)
    {
        middle_num = left_part + (right_part - left_part) / 2;
        int middle_num_sqr = middle_num * middle_num;

        if(middle_num_sqr == x)
        {
            return middle_num;
        }else if(middle_num_sqr < x)
        {
            left_part = middle_num + 1;
        } else
        {
            right_part = middle_num - 1;
        }
    }

    return 0;
}
