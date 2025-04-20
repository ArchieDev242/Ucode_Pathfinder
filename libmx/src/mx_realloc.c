#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size)
{
    if(size == 0)
    {
        free(ptr);
        return NULL;
    }

    if(!ptr)
    {
        return malloc(size);
    }

    void *new_data = malloc(size);

    if(new_data)
    {
        size_t old_size = malloc_usable_size(ptr);  // change mx_strlen((char *)ptr) + 1; ??
        size_t copy_size = (old_size < size) ? old_size : size;

        mx_memcpy(new_data, ptr, copy_size);
        free(ptr);
    }

    return new_data;
}
