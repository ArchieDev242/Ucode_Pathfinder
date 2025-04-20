#pragma once

#include "../libmx/inc/libmx.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483647

typedef struct s_island 
{
    int id;
    char *name;
} t_island;

typedef struct s_island_graph 
{
    int num_islands;
    int **matrix;
    char **island_names;
} t_island_graph;

typedef struct s_islands_bridge 
{
    char *island1;
    char *island2;
    int length;
} t_islands_bridge;

typedef struct s_islands_info 
{
    int num_islands;
    t_list *islands;
    t_islands_bridge *bridges;
    int num_bridges;
    t_island_graph *graph;
} t_islands_info;

typedef struct s_islands_path 
{
    int *islands;
    int length;
} t_islands_path;

typedef struct s_path_history 
{
    t_islands_path *paths;
    int count;
    int length_min;
} t_path_history;

typedef struct s_islands_path_info 
{
    int *visited;
    int *path;
    int path_index;
    int length;
} t_islands_path_info;

// mx_errors_handling.c
void mx_printerr(char *str);
int mx_check_arguments(int argc);
void isFileExist(char *filename);
void isFileEmpty(char *filename);
int count_lines(char *filename);
void mx_lineerr(int line);
int mx_is_first_argument(char *line);
int mx_second_argerr(char *island1, char *island2, char *length, int num);
int mx_bridge_length(char *length, int num);
int mx_extra_data(char *line, int num);
int mx_is_valid_part(char *line, int *i, char valid_char, char delimiter, int num);
int mx_island_name_valid(char *name, int num);

// mx_short_paths.c
t_island *get_island_by_name(t_islands_info *data, char *name);
int mx_get_first_argument(char *filename, int fd);
void parse_islands_bridges(char *filename, int fd, t_islands_info *data);
t_islands_info *get_info(char *filename);
int get_island_idx_by_name(char *island_name, t_islands_info *data);
void cleanup_data(t_islands_info *data);
char *find_island_by_id(t_list *island_list, int island_id);
ssize_t mx_read_file_data(int fd, char *buffer, size_t buffer_size);

// some funcs for graphs
t_island_graph *initialize_graph_structure(t_islands_info *data);
bool fill_graph(t_island_graph *graph, t_islands_info *data);
t_island_graph *create_graph(t_islands_info *data);

// Path finding funcs
void update_node(int from, t_islands_path_info *path_info);
void reset_node(int from, t_islands_path_info *path_info);
void save_path(t_islands_path_info *path_info, t_path_history *all_paths);
void check_dist_islands(int *mark, t_islands_info *data, t_islands_path_info *path_info, t_path_history *all_paths);
void trace_all_routes(int *coords, t_islands_info *data, t_islands_path_info *path_info, t_path_history *all_paths);
t_islands_path_info *initialize_path_info_structure(int graph_size);
t_path_history *initialize_path_list_structure(void);
void free_path_info(t_islands_path_info *path_info);
void free_paths(t_path_history *all_paths);
void find_all_paths(t_islands_info *data);

// Output funcs
void path_info(t_islands_path *current_path, t_islands_info *map_info);
void route_sequence(t_islands_path *current_path, t_islands_info *map_info);
void distances(t_islands_path *current_path, t_islands_info *map_info, int total_length);
void path_output(t_path_history *paths, t_islands_info *map_info);
