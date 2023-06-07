/*
** EPITECH PROJECT, 2023
** Lemin
** File description:
** check_if_finished
*/
#include "include/lemin.h"
#include "include/graph.h"
#include "include/link_graph.h"

int check_if_finished(graph_t *graph, int *ants, file_t *file, int end)
{
    for (int i = 0; i < file->nb_ants; i++) {
        if (graph->path[ants[i]] != end)
            return (0);
    }
    return (1);
}
