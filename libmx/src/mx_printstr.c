#include "../inc/libmx.h"

void mx_printstr(const char *s) 
{
    if(s!= NULL)
    {
        for(int i = 0; s[i]!= '\0'; i++)
        {
            write(1, &s[i], 1);
        }
    }
}
