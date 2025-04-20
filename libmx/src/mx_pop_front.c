#include "../inc/libmx.h"

void mx_pop_front(t_list **head)
{
    if(head == NULL || *head == NULL)
    {
        return;
    }

    t_list *new_head = *head;
    *head = (*head) -> next;
    free(new_head);
}

