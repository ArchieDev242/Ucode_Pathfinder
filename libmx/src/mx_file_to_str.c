#include "../inc/libmx.h"

char *mx_file_to_str(const char *file)
{
    if(!file)
    {
        return NULL;
    }

    int filestr = open(file, O_RDONLY);

    if(filestr < 0)
    {
        close(filestr);
        return NULL;
    }

    int size = lseek(filestr, 0, SEEK_END);
    if(size < 0)
    {
        close(filestr);
        return NULL;
    }

    lseek(filestr, 0, SEEK_SET);

    char *str = mx_strnew(size + 1);

    if(!str)
    {
        close(filestr);
        return NULL;
    }

    int bytes_read = read(filestr, str, size);

    if(bytes_read < 0)
    {
        mx_strdel(&str);
        close(filestr);
        return NULL;
    }

    close(filestr);

    return str;
}

