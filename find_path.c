/*
** EPITECH PROJECT, 2023
** find_path.c
** File description:
** find_path
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "include/link_graph.h"

void do_dfs(graph_t *graph, int vertex, int nb_rooms)
{
    int connectedVertex = 0;

    graph->visited_rooms[vertex] = 1;
    graph->path[graph->index] = graph->rooms[vertex]->nb_room;
    graph->index++;
    for (int i = 0; i != graph->rooms[vertex]->nb_link; i++) {
        connectedVertex = graph->rooms[vertex]->linked_room[i];
        if (graph->visited_rooms[connectedVertex] == 0)
            do_dfs(graph, connectedVertex, nb_rooms);
    }
}
