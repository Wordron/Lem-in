/*
** EPITECH PROJECT, 2023
** Lemin
** File description:
** get_connection
*/
#include <stdio.h>
#include "include/my.h"
#include "include/graph.h"
#include "include/lemin.h"
#include "include/link_graph.h"

static int check_if_link(int room_nb, char *file)
{
    int j = 0;
    int first_room = my_getnbr(file, 0);
    int second_room = -1;

    for (j = 0; file[j] != '-';)
        j++;
    j++;
    second_room = my_getnbr(file, j);
    if (first_room == room_nb)
        return (second_room);
    if (second_room == room_nb)
        return (first_room);
    return (-1);
}

static int *get_connections(int room_nb, char **file, int nb_links)
{
    int *connection = malloc(sizeof(int) * nb_links);
    int temp = -1;
    int j = 0;

    for (int i = 0; file[i] != NULL; i++) {
        temp = -1;
        if (file[i][0] != '#' && my_strlen(file[i]) == 4 && file[i][1] == '-')
            temp = check_if_link(room_nb, file[i]);
        if (temp != -1) {
            connection[j] = temp;
            j++;
        }
    }
    return (connection);
}

void fill_tunnels(file_t *file, room_t **room)
{
    int nb_rooms = get_nb_room(file);

    for (int i = 0; i < nb_rooms; i++)
        room[i]->linked_room = get_connections(room[i]->nb_room, file->file,
            room[i]->nb_link);
}
