#include "pathfinder.h"

#define PATH_SEPARATOR "========================================\n"

bool mx_is_char(int c, char type) 
{
    switch(type) 
    {
        case 'd': return(c >= '0' && c <= '9');
        case 'a': return((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
        default: return false;
    }
}

int mx_is_duplicate(char *a, char *b) 
{
    if(mx_strcmp(a, b) == 0)
    {
        return 0;
    }

    return -1;
}

int safe_atoi(char *str) 
{
    int result = 0;

    while(*str >= '0' && *str <= '9') 
    {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result;
}

void path_info(t_islands_path *current_path, t_islands_info *map_info) 
{
    mx_printstr("Path: ");
    mx_printstr(find_island_by_id(map_info -> islands, current_path -> islands[0]));
    mx_printstr(" -> ");
    mx_printstr(find_island_by_id(map_info -> islands, current_path -> islands[current_path -> length - 1]));
    mx_printstr("\n");
}

void route_sequence(t_islands_path *current_path, t_islands_info *map_info) 
{
    mx_printstr("Route: ");

    for(int index = 0; index < current_path->length - 1; ++index) 
    {
        char *start = find_island_by_id(map_info -> islands, current_path -> islands[index]);
        mx_printstr(start);
        mx_printstr(" -> ");
    }

    char *end = find_island_by_id(map_info -> islands, current_path -> islands[current_path -> length - 1]);
    mx_printstr(end);
    mx_printstr("\n");
}

void distances(t_islands_path *current_path, t_islands_info *map_info, int total_length) 
{
    mx_printstr("Distance: ");

    if(current_path->length == 2) mx_printint(total_length);
    else 
    {
        for(int index = 0; index < current_path -> length - 1; ++index) 
        {
            int from = current_path -> islands[index];
            int to = current_path -> islands[index + 1];
            mx_printint(map_info -> graph -> matrix[from][to]);

            if(index < current_path -> length - 2) mx_printstr(" + ");
        }

        mx_printstr(" = ");
        mx_printint(total_length);
    }

    mx_printstr("\n");
}

void path_output(t_path_history *paths, t_islands_info *map_info) 
{
    for(int path_index = 0; path_index < paths -> count; ++path_index) 
    {
        mx_printstr(PATH_SEPARATOR);
        path_info(&paths -> paths[path_index], map_info);
        route_sequence(&paths -> paths[path_index], map_info);
        distances(&paths -> paths[path_index], map_info, paths -> length_min);
        mx_printstr(PATH_SEPARATOR);
    }
}

int main(int argc, char *argv[]) 
{
    if(mx_check_arguments(argc) < 0) return -1;

    int count = count_lines(argv[1]);
    (void)count;

    char *filename = argv[1];

    t_islands_info *data = get_info(filename);

    if(!data) return -1;

    data -> graph = create_graph(data);

    if(!data -> graph) 
    {
        free(data);
        return 1;
    }

    find_all_paths(data);

    free(data -> graph);
    free(data);

    return 0;
}
