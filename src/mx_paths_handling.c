#include "pathfinder.h"

extern bool mx_isdigit(int c);
extern bool mx_isalpha(int c);
extern int safe_atoi(char *str);
extern int mx_is_duplicate(char *a, char *b);

ssize_t mx_read_file_data(int fd, char *buffer, size_t buffer_size)
{
    if(fd < 0 || buffer == NULL || buffer_size == 0) return -1;

    size_t i = 0;
    char c;
    ssize_t bytes_read;

    while(i < buffer_size - 1 && (bytes_read = read(fd, &c, 1)) > 0)
    {
        if(c == '\n') break;
        buffer[i++] = c;
    }

    if(bytes_read < 0) return -1;

    buffer[i] = '\0';

    return(bytes_read == 0 && i == 0) ? 0 : i;
}

int mx_get_first_argument(char *filename, int fd)
{
    char buf[1024];

    ssize_t bytes_read = mx_read_file_data(fd, buf, sizeof(buf));

    if(bytes_read == 0)
    {
        isFileEmpty(filename);
        return -1;
    } else if(bytes_read == -1)
    {
        isFileExist(filename);
        return -1;
    }

    if(mx_is_first_argument(buf) < 0)
    {
        return -1;
    }

    int count = safe_atoi(buf);

    if(count <= 0)
    {
        mx_printerr("error: invalid argument count\n");
        return -1;
    }

    return count;
}


void parse_islands_bridges(char *filename, int fd, t_islands_info *data)
{
    int bridge_index = 0, i = 1, j = 2, size = mx_get_first_argument(filename, fd);
    char buf[1024];

    if (size <= 0)
    {
        cleanup_data(data);
        exit(1);
    }

    data -> num_islands = size;
    data -> bridges = malloc(sizeof(t_islands_bridge) * (data -> num_islands * (data -> num_islands - 1)) / 2);

    while(mx_read_file_data(fd, buf, sizeof(buf)) > 0)
    {
        if(mx_extra_data(buf, j) < 0)
        {
            cleanup_data(data);
            exit(1);
        }

        char **parts = mx_strsplit(buf, ',');

        if(!parts || parts[0] == NULL || parts[1] == NULL)
        {
            mx_del_strarr(&parts);
            continue;
        }

        char **islands = mx_strsplit(parts[0], '-');

        if(!islands || islands[0] == NULL || islands[1] == NULL)
        {
            mx_del_strarr(&parts);
            mx_del_strarr(&islands);
            continue;
        }

        char *island1 = islands[0];
        char *island2 = islands[1];

        if(mx_second_argerr(island1, island2, parts[1], i) < 0)
        {
            cleanup_data(data);
            exit(1);
        }

        char *length_str = mx_strdup(parts[1]);
        int length = safe_atoi(length_str);

        data -> bridges[bridge_index].island1 = mx_strdup(island1);
        data -> bridges[bridge_index].island2 = mx_strdup(island2);
        data -> bridges[bridge_index].length = length;
        bridge_index++;
        t_island *node1 = get_island_by_name(data, island1);

        if(!node1)
        {
            node1 = malloc(sizeof(t_island));
            node1 -> id = mx_list_size(data -> islands);
            node1 -> name = mx_strdup(island1);
            mx_push_back(&data -> islands, node1);
        }

        t_island *node2 = get_island_by_name(data, island2);

        if(!node2)
        {
            node2 = malloc(sizeof(t_island));
            node2 -> id = mx_list_size(data->islands);
            node2 -> name = mx_strdup(island2);
            mx_push_back(&data->islands, node2);
        }

        free(length_str);
        i++;
        j++;
    }

    data -> num_bridges = bridge_index;
}

void cleanup_data(t_islands_info *data)
{
    if(data -> bridges)
    {
        for(int k = 0; k < data -> num_bridges; k++)
        {
            free(data -> bridges[k].island1);
            free(data -> bridges[k].island2);
        }

        free(data -> bridges);
    }

    t_list *current = data -> islands;

    while (current)
    {
        t_list *next = current -> next;
        t_island *node_data = current -> data;
        free(node_data -> name);
        free(node_data);
        free(current);
        current = next;
    }

    free(data);
}

char *find_island_by_id(t_list *island_list, int island_id) 
{
    t_list *current_list = island_list;

    while(current_list) 
    {
        t_island *island_node = (t_island *)current_list -> data;

        if(island_node->id == island_id) return island_node->name;

        current_list = current_list -> next;
    }

    return NULL;
}


t_island *get_island_by_name(t_islands_info *data, char *name) 
{
    t_list *node = data -> islands;

    while(node) 
    {
        t_island *current = (t_island *)node->data;

        if(!mx_strcmp(current->name, name)) return current;

        node = node->next;
    }

    return NULL;
}


int get_island_idx_by_name(char *island_name, t_islands_info *data_info)
{
    t_list *current_node = data_info->islands;
    int idx = 0;

    while(current_node != NULL)
    {
        t_island *current_island = (t_island *)current_node -> data;
        if (mx_strcmp(current_island -> name, island_name) == 0) return idx;
        current_node = current_node -> next;

        idx++;
    }

    return -1;
}

void update_node(int from, t_islands_path_info *path_info)
{
    path_info -> visited[from] = 1;
    path_info -> path[path_info->path_index] = from;
    ++path_info -> path_index;
}

void reset_node(int from, t_islands_path_info *path_info)
{
    --path_info -> path_index;
    path_info -> visited[from] = 0;
}

void save_path(t_islands_path_info *path_info, t_path_history *all_paths) 
{
    if(path_info -> length < all_paths -> length_min) 
    {
        for(int i = 0; i < all_paths -> count; ++i) 
        {
            free(all_paths->paths[i].islands);
        }

        free(all_paths -> paths);
        all_paths -> paths = NULL;
        all_paths -> count = 0;
    }

    all_paths -> paths = (t_islands_path *)mx_realloc(all_paths->paths, (all_paths->count + 1) * sizeof(t_islands_path));

    t_islands_path *new_path = &all_paths -> paths[all_paths -> count];
    new_path -> islands = (int *)malloc(path_info -> path_index * sizeof(int));
    new_path -> length = path_info->path_index;

    for(int i = 0; i < path_info->path_index; ++i) 
    {
        new_path -> islands[i] = path_info -> path[i];
    }

    ++all_paths -> count;
    all_paths -> length_min = path_info -> length;
}

void check_dist_islands(int *mark, t_islands_info *data, t_islands_path_info *path_info, t_path_history *all_paths)
{
    int from = mark[0];

    for(int i = 0; i < data -> graph -> num_islands; ++i)
    {
        int weight = data -> graph -> matrix[from][i];

        if(weight != INT_MAX && !path_info -> visited[i])
        {
            path_info -> length += weight;
            int new_coords[2] = {i, mark[1]};
            trace_all_routes(new_coords, data, path_info, all_paths);
            path_info -> length -= weight;
        }
    }
}

void trace_all_routes(int *coords, t_islands_info *data, t_islands_path_info *path_info, t_path_history *all_paths)
{
    int from = coords[0], to = coords[1];
    update_node(from, path_info);

    if(all_paths -> count > 0 && path_info -> length > all_paths -> length_min)
    {
        reset_node(from, path_info);
        return;
    }

    if(from == to) save_path(path_info, all_paths);
    else check_dist_islands(coords, data, path_info, all_paths);

    reset_node(from, path_info);
}

t_islands_path_info *initialize_path_info_structure(int graph_size)
{
    t_islands_path_info *path_info = (t_islands_path_info *)malloc(sizeof(t_islands_path_info));
    path_info -> visited = (int *)calloc(graph_size, sizeof(int));
    path_info -> path = (int *)malloc(graph_size * sizeof(int));
    path_info -> path_index = 0;
    path_info -> length = 0;
    return path_info;
}

t_path_history *initialize_path_list_structure(void)
{
    t_path_history *all_paths = (t_path_history *)malloc(sizeof(t_path_history));
    all_paths -> paths = NULL;
    all_paths -> count = 0;
    all_paths -> length_min = INT_MAX;
    return all_paths;
}

void free_path_info(t_islands_path_info *path_info)
{
    free(path_info -> visited);
    free(path_info -> path);
    free(path_info);
}

void free_paths(t_path_history *all_paths)
{
    for(int i = 0; i < all_paths -> count; ++i)
    {
        free(all_paths -> paths[i].islands);
    }

    free(all_paths -> paths);
    free(all_paths);
}

void find_all_paths(t_islands_info *data)
{
    for(t_list *current = data -> islands; current; current = current -> next)
    {
        for(t_list *copy = current -> next; copy; copy = copy -> next)
        {
            t_islands_path_info *path_info = initialize_path_info_structure(data -> graph -> num_islands);
            t_path_history *all_paths = initialize_path_list_structure();

            int coords[2] = {((t_island *)current->data)->id, ((t_island *)copy -> data) -> id};

            trace_all_routes(coords, data, path_info, all_paths);

            path_output(all_paths, data);

            free_path_info(path_info);
            free_paths(all_paths);
        }
    }
}

t_island_graph *initialize_graph_structure(t_islands_info *data_info)
{
    t_island_graph *new_graph = (t_island_graph *)malloc(sizeof(t_island_graph));

    if (new_graph == NULL) return NULL;

    new_graph -> num_islands = data_info -> num_islands;
    new_graph -> matrix = (int **)malloc(sizeof(int *) * new_graph -> num_islands);
    new_graph -> island_names = (char **)malloc(sizeof(char *) * new_graph -> num_islands);

    for(int i = 0; i < new_graph -> num_islands; i++)
    {
        new_graph -> matrix[i] = (int *)malloc(sizeof(int) * new_graph -> num_islands);
        new_graph -> island_names[i] = NULL;

        for(int j = 0; j < new_graph -> num_islands; j++)
        {
            new_graph -> matrix[i][j] = INT_MAX;
        }
    }

    t_list *current_node = data_info -> islands;

    for(int i = 0; i < data_info -> num_islands; i++)
    {
        new_graph -> island_names[i] = ((t_island *)current_node -> data) -> name;
        current_node = current_node->next;
    }

    return new_graph;
}

t_island_graph *create_graph(t_islands_info *data_info)
{
    t_island_graph *graph = initialize_graph_structure(data_info);

    if(graph == NULL) return NULL;

    if(!fill_graph(graph, data_info))
    {
        free(graph);
        return NULL;
    }

    return graph;
}
