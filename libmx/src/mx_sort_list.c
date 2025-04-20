#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *))
{
    if(!lst || !cmp)
    {
        return lst;
    }

    bool swap;
    t_list *current = lst;
    t_list *last = NULL;

    do
    {
        swap = false;
        current = lst;
        
        while(current -> next != last)
        {
            if(cmp(current -> data, current -> next -> data))
            {
                void *temp = current -> data;
                current -> data = current -> next -> data;
                current -> next -> data = temp;
                swap = true;
            }

            current = current -> next;
        }

        last = current;
    } while(swap);

    return lst;
}
