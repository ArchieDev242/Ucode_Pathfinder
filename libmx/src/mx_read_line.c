#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd)
{
    if(fd < 0 || !lineptr || buf_size <= 0)
    {
        return -2;
    }

    char *buf = mx_strnew(buf_size);
    char *temp = mx_strnew(0);
    size_t len = 0;
    ssize_t bytes_count_read = 0;

    while((bytes_count_read = read(fd, buf, buf_size)) > 0)
    {
        ssize_t i = 0;
        while(i < bytes_count_read)
        {
            if(buf[i] == delim)
            {
                temp = mx_realloc(temp, len + i + 1);
                mx_memcpy(temp + len, buf, i);
                temp[len + i] = '\0';
                *lineptr = temp;
                bytes_count_read -= (i + 1);
                ssize_t remaining_bytes = bytes_count_read - i - 1;

                if(remaining_bytes > 0)
                {
                    mx_memmove(buf, buf + i + 1, remaining_bytes);
                }
                free(buf);
                return len + i;
            }
            i++;
        }

        temp = mx_realloc(temp, len + bytes_count_read + 1);
        mx_memcpy(temp + len, buf, bytes_count_read);
        len += bytes_count_read;
    }

    free(buf);

    if(bytes_count_read < 0)
    {
        return -2;
    }

    if(bytes_count_read == 0)
    {
        if(temp != NULL)
        {
            temp[len] = '\0';
            *lineptr = temp;
            return len;
        }

        return -1;
    }

    temp[len] = '\0';
    *lineptr = temp;

    return len;
}
