#include "../inc/libmx.h"

void mx_str_reverse(char *s) 
{
    int length = mx_strlen(s);

    for(int i = 0; i < length / 2; i++) 
    {
        char temp_length = s[i];

        s[i] = s[length - i - 1];
        s[length - i - 1] = temp_length;
    }
}

