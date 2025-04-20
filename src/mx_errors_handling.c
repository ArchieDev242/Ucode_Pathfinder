#include "pathfinder.h"

extern bool mx_is_char(int c, char type);
extern int mx_is_duplicate(char *a, char *b);
extern int safe_atoi(char *str);

void mx_printerr(char *str)
{
    write(2, str, mx_strlen(str));
}

void mx_lineerr(int line)
{
    char *line_buff = mx_itoa(line);
    mx_printerr("error: line ");
    mx_printerr(line_buff);
    free(line_buff);
    mx_printerr(" is not valid\n");
}

void mx_is_islands_duplicate(char *a, char *b, int id)
{
    if(mx_is_duplicate(a, b) == 0) mx_lineerr(id);
}

int mx_is_valid_length(int sum, int num)
{
    if(sum > INT_MAX - num)
    {
        mx_printerr("error: sum of bridges lengths is too big\n");
        return -1;
    }
    return 0;
}

int mx_check_arguments(int argc)
{
    if(argc != 2)
    {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return -1;
    }

    return 0;
}

void isFileExist(char *filename)
{
    mx_printerr("error: file ");
    mx_printerr(filename);
    mx_printerr(" does not exist\n");
}

void isFileEmpty(char *filename)
{
    mx_printerr("error: file ");
    mx_printerr(filename);
    mx_printerr(" is empty\n");
}

int count_lines(char *filename)
{
    int fd = open(filename, O_RDONLY);

    if(fd < 0)
    {
        isFileExist(filename);
    }

    int lines = 0;
    int line_number = 1;
    char ch;
    int is_empty_line = 1;
    ssize_t bytes_read;

    while((bytes_read = read(fd, &ch, 1)) > 0)
    {
        if(ch == '\n')
        {
            if(is_empty_line)
            {
                char *buf = mx_itoa(line_number);
                mx_printerr("error: line ");
                mx_printerr(buf);
                mx_printerr(" is not valid\n");
                mx_strdel(&buf);
                close(fd);
                exit(0);
            }

            lines++;
            line_number++;
            is_empty_line = 1;
        } else if(ch != '\r' && ch != ' ') is_empty_line = 0;
    }

    if(bytes_read < 0)
    {
        close(fd);
        exit(0);
    }

    if(!is_empty_line) lines++;
    else if(lines == 0)
    {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" is empty\n");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);
    return lines;
}

int mx_is_first_argument(char *line)
{
    if(line[0] == '0' || line[0] == '\n' || line[0] == '\0')
    {
        mx_lineerr(1);
        return -1;
    }

    long long result = 0;

    for(int i = 0; line[i] != '\0'; i++)
    {
        if(!mx_is_char(line[i], 'd'))
        {
            mx_lineerr(1);
            return -1;
        }

        int digit = line[i] - '0';

        if(result > (INT_MAX - digit) / 10)
        {
            mx_lineerr(1);
            return -1;
        }

        result = result * 10 + digit;
    }

    if(result > INT_MAX)
    {
        mx_lineerr(1);
        return -1;
    }

    return 0;
}

int mx_island_name_valid(char *name, int num)
{
    if(!name) 
    {
        mx_lineerr(num + 1);
        return 0;
    }

    for(int i = 0; name[i] != '\0'; ++i)
    {
        if(!mx_is_char(name[i], 'a'))
        {
            mx_lineerr(num + 1);
            return 0;
        }
    }

    return 1;
}

int mx_second_argerr(char *island1, char *island2, char *length, int num)
{
    if(!island1 || !island2 || !length)
    {
        mx_lineerr(num + 1);
        return -1;
    }

    if(!mx_island_name_valid(island1, num) || !mx_island_name_valid(island2, num)) return -1;

    if(!mx_strcmp(island1, island2))
    {
        mx_lineerr(num + 1);
        return -1;
    }

    if(mx_bridge_length(length, num + 1) < 0) return -1;

    return 0;
}

int mx_bridge_length(char *length, int num)
{
    if(length == NULL || length[0] == '\0' || length[0] == '\n')
    {
        mx_lineerr(num);
        return -1;
    }

    for(int i = 0; length[i] != '\0'; i++)
    {
        if(!mx_is_char(length[i], 'd'))
        {
            mx_lineerr(num);
            return -1;
        }
    }

    if(safe_atoi(length) <= 0)
    {
        mx_lineerr(num);
        return -1;
    }

    return 0;
}

int mx_is_valid_part(char *line, int *i, char valid_char, char delimiter, int num)
{
    while(line[*i] != delimiter && line[*i] != '\0')
    {
        if(!mx_is_char(line[*i], valid_char))
        {
            mx_lineerr(num);
            return -1;
        }

        (*i)++;
    }

    if(line[*i] != delimiter && line[*i] != '\0')
    {
        mx_lineerr(num);
        return -1;
    }

    (*i)++;
    return 0;
}

int mx_extra_data(char *line, int num)
{
    int i = 0;
    int len_data = mx_strlen(line);

    if(len_data > 3)
    {
        if(line[0] == '-')
        {
            mx_lineerr(num);
            return -1;
        }

        if(mx_is_valid_part(line, &i, 'a', '-', num) < 0) return -1;

        if(line[i] == ',')
        {
            mx_lineerr(num);
            return -1;
        }

        if(mx_is_valid_part(line, &i, 'a', ',', num) < 0) return -1;

        if(line[i] == ',')
        {
            mx_lineerr(num);
            return -1;
        }

        if(!mx_is_char(line[i], 'd'))
        {
            mx_lineerr(num);
            return -1;
        }

        while(line[i] != '\0' && line[i] != '\n')
        {
            if(!mx_is_char(line[i], 'd'))
            {
                mx_lineerr(num);
                return -1;
            }

            i++;
        }
    }

    return 0;
}

bool fill_graph(t_island_graph *graph, t_islands_info *data_info)
{
    int total_bridge_length = 0;

    for(int i = 0; i < data_info -> num_bridges; ++i)
    {
        t_islands_bridge current_bridge = data_info -> bridges[i];

        if(total_bridge_length > INT_MAX - current_bridge.length)
        {
            mx_printerr("error: sum of bridges lengths is too big\n");
            return false;
        }

        total_bridge_length += current_bridge.length;

        int idx1 = get_island_idx_by_name(current_bridge.island1, data_info);
        int idx2 = get_island_idx_by_name(current_bridge.island2, data_info);

        if(idx1 < 0 || idx2 < 0 || idx1 >= graph -> num_islands || idx2 >= graph -> num_islands)
        {
            mx_printerr("error: invalid number of islands\n");
            return false;
        }

        if(graph -> matrix[idx1][idx2] != INT_MAX || graph -> matrix[idx2][idx1] != INT_MAX)
        {
            mx_printerr("error: duplicate bridges\n");
            return false;
        }

        graph -> matrix[idx1][idx2] = current_bridge.length;
        graph -> matrix[idx2][idx1] = current_bridge.length;

        graph -> matrix[idx1][idx1] = 0;
        graph -> matrix[idx2][idx2] = 0;
    }

    return true;
}

t_islands_info *get_info(char *filename)
{
    int fd = open(filename, O_RDONLY);

    t_islands_info *data = malloc(sizeof(t_islands_info));
    data -> num_islands = 0;
    data -> islands = NULL;
    data -> graph = NULL;
    data -> bridges = NULL;
    data -> num_bridges = 0;

    parse_islands_bridges(filename, fd, data);

    if(mx_list_size(data -> islands) != data -> num_islands)
    {
        mx_printerr("error: invalid number of islands\n");

        for(int k = 0; k < data -> num_bridges; k++)
        {
            free(data -> bridges[k].island1);
            free(data -> bridges[k].island2);
        }

        free(data -> bridges);
        data -> bridges = NULL;

        t_list *current = data -> islands;

        while(current)
        {
            t_list *next = current -> next;
            t_island *node_data = (t_island *)current -> data;
            free(node_data -> name);
            free(node_data);
            free(current);
            current = next;
        }

        data -> islands = NULL;
        close(fd);
        return NULL;
    }

    close(fd);
    return data;
}
