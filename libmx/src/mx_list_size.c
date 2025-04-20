#include "../inc/libmx.h"

int mx_list_size(t_list *list)
{
    int size = 0;
    t_list *current_list = list;

    while(current_list)
    {
        size++;
        current_list = current_list -> next;
    }

    return size;
}

