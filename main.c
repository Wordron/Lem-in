/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "include/graph.h"
#include "include/lemin.h"
#include "include/link_graph.h"

int *init_visited(int nb_rooms)
{
    int *temp = malloc(sizeof(int) * nb_rooms);

    for (int i = 0; i < nb_rooms; i++)
        temp[i] = 0;
    return (temp);
}

room_t **complete_rooms(file_t *file)
{
    room_t **room = malloc(sizeof(room_t *) * get_nb_room(file));

    get_number_in_file(file, room);
    fill_tunnels(file, room);
    return (room);
}

int get_start(graph_t *graph, int nb_rooms)
{
    int result = 0;

    for (int i = 0; i != nb_rooms; i++)
        if (graph->rooms[i]->type == START)
            result = graph->rooms[i]->nb_room;
    return (result);
}

static void do_main_loop(file_t *file, graph_t *graph, int nb_rooms)
{
    int end = 0;
    int start = 0;

    for (int k = 0; k != nb_rooms; k++)
        graph->path[k] = 0;
    graph->index = 0;
    bubble_sort(graph->rooms, nb_rooms);
    start = get_start(graph, nb_rooms);
    end = get_end(graph, nb_rooms);
    graph->visited_rooms = init_visited(nb_rooms);
    do_dfs(graph, start, nb_rooms);
    file->start_of_trail = 0;
    file->nb_ants_moving = 0;
    move_ant(graph, end, file);
}

int main(int ac, char **av)
{
    file_t *file = malloc(sizeof(file_t));
    graph_t *graph = malloc(sizeof(graph_t));
    int nb_rooms = 0;

    (void)av;
    file->tmp = 0;
    if (ac != 1)
        return (84);
    file_2d(file, 0, 0);
    if (check_nb_ant(file) == 0)
        return (84);
    graph->rooms = complete_rooms(file);
    nb_rooms = get_nb_room(file);
    if (display_result(file, graph->rooms) == 84)
        return (84);
    graph->path = malloc(sizeof(int) * (nb_rooms + 1));
    do_main_loop(file, graph, nb_rooms);
}
