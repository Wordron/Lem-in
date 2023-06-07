/*
** EPITECH PROJECT, 2023
** Lemin
** File description:
** display_ants_moves
*/
#include "include/lemin.h"
#include "include/graph.h"
#include "include/link_graph.h"
#include "include/my.h"

static int *init_ant_array(int nb_ants)
{
    int *ants = malloc(sizeof(int) * nb_ants);

    for (int i = 0; i < nb_ants; i++)
        ants[i] = 0;
    return (ants);
}

static int get_size_path(int *path, int end)
{
    int i = 0;

    while (path[i] != end)
        i++;
    return (i);
}

static int change_ant_moving(int nb_ants_moving, int size_path,
    int start_of_trail, int nb_ants)
{
    if (nb_ants_moving < size_path
        && nb_ants - start_of_trail > nb_ants_moving)
        return (1);
    if (nb_ants - start_of_trail < nb_ants_moving)
        return (-1);
    return (0);
}

static void display_ant_moves(graph_t *graph, int *ants, file_t *file)
{
    int display_ant = 0;

    for (display_ant = file->start_of_trail; (display_ant + 1) < (
        file->nb_ants_moving + file->start_of_trail); display_ant++) {
        my_putchar('P');
        my_put_nbr(display_ant + 1);
        my_putchar('-');
        my_put_nbr(graph->path[ants[display_ant]]);
        my_putchar(' ');
    }
    if (display_ant + 1 <= file->nb_ants) {
        my_putchar('P');
        my_put_nbr(display_ant + 1);
        my_putchar('-');
        my_put_nbr(graph->path[ants[display_ant]]);
        my_putchar('\n');
    }
}

void move_ant(graph_t *graph, int end, file_t *file)
{
    int *ants = init_ant_array(file->nb_ants);
    int size_path = get_size_path(graph->path, end);

    while (1) {
        if (check_if_finished(graph, ants, file, end) == 1)
            return;
        file->nb_ants_moving = file->nb_ants_moving + change_ant_moving(
        file->nb_ants_moving, size_path, file->start_of_trail, file->nb_ants);
        for (int j = file->start_of_trail; j < (file->nb_ants_moving +
            file->start_of_trail); j++)
            ants[j]++;
        display_ant_moves(graph, ants, file);
        if (graph->path[ants[file->start_of_trail]] == end
            && file->start_of_trail < file->nb_ants)
            file->start_of_trail++;
    }
}
