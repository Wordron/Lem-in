/*
** EPITECH PROJECT, 2023
** Lemin
** File description:
** lemin
*/

#include "graph.h"
#include "link_graph.h"

#ifndef LEMIN_H_
    #define LEMIN_H_

    char **file_2d(file_t *file, int len, int tmp);
    void get_number_in_file(file_t *file, room_t **room);
    int get_nb_room(file_t *file);
    char **get_my_array(char *str);
    int skip_comment(char *buffer, int i);
    int get_nb_links(int room_nb, char **file);
    void fill_tunnels(file_t *file, room_t **room);
    int display_result(file_t *file, room_t **room);
    void do_dfs(graph_t *graph, int vertex, int nb_rooms);
    void bubble_sort(room_t **rooms, int nb_rooms);
    int get_end(graph_t *graph, int nb_rooms);
    void move_ant(graph_t *graph, int end, file_t *file);
    int is_a_char(char str);
    int count_words(char *str);
    int length_word1(char *str, int index);
    int add_to_i_if_not_space(int i, char *str, int index);
    int check_if_finished(graph_t *graph, int *ants, file_t *file, int end);
    int check_start_room(room_t **room, int nb_rooms);
    int check_nb_ant(file_t *file);
    int check_room_name(room_t **rooms, int nb_rooms, int room_nb);
    int get_nb_all_link(char **file);

#endif /* !LEMIN_H_ */
