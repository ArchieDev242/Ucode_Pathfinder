#include "../inc/libmx.h"

char *mx_itoa(int number) 
{
    bool is_negative = false;
    int len = 0, index = 0;
    unsigned long temp = number, temp_for_len = temp;

    if(number == 0) 
	{
        char *str = mx_strnew(2);
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    if(number < 0) 
	{
        is_negative = true;
        temp = -temp;
    }

    while(temp_for_len > 0) 
	{
        temp_for_len /= 10;
        len++;
    }

    if(is_negative) 
	{
        len++;
    }

    char *str = mx_strnew(len + 1);

    while(temp > 0) 
	{
        str[index++] = (temp % 10) + '0';
        temp /= 10;
    }

    if(is_negative) 
	{
        str[index++] = '-';
    }

    str[index] = '\0';

    mx_str_reverse(str);

    return str;
}
