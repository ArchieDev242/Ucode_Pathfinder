#include "../inc/libmx.h"

void mx_printint(int n) 
{
    long n_temp = n;

    if(n_temp < 0) 
    {
        mx_printchar('-');
        n_temp *= -1;
    }

    int n_next = n_temp / 10;

    if(n_next) 
    {
        mx_printint(n_next);
    }

    mx_printchar((n_temp % 10) + 48);
}
