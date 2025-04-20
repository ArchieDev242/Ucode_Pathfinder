#include "../inc/libmx.h"

void mx_pop_back(t_list **head)
{
    if(head == NULL || *head == NULL)
    {
        return;
    }

    if((*head) -> next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    t_list *current_head = *head;
    
    while(current_head -> next -> next != NULL)
    {
        current_head = current_head -> next;
    }

    free(current_head -> next);
    current_head -> next = NULL;
}

