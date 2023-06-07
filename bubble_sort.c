/*
** EPITECH PROJECT, 2023
** Lemin
** File description:
** bubble_sort
*/
#include <stdlib.h>
#include "include/link_graph.h"

static void replace_room(room_t *room_to_be_replaced,
    room_t *room_to_replace_by)
{
    room_to_be_replaced->linked_room = malloc(sizeof(int) *
        room_to_replace_by->nb_link);
    for (int i = 0; i < room_to_replace_by->nb_link; i++)
        room_to_be_replaced->linked_room[i] =
            room_to_replace_by->linked_room[i];
    room_to_be_replaced->nb_link = room_to_replace_by->nb_link;
    room_to_be_replaced->nb_room = room_to_replace_by->nb_room;
    room_to_be_replaced->type = room_to_replace_by->type;
    room_to_be_replaced->x = room_to_replace_by->x;
    room_to_be_replaced->y = room_to_replace_by->y;
}

static void change_room(room_t *room_one, room_t *room_two)
{
    room_t *temp = malloc(sizeof(room_t));

    replace_room(temp, room_one);
    free(room_one->linked_room);
    replace_room(room_one, room_two);
    free(room_two->linked_room);
    replace_room(room_two, temp);
    free(temp->linked_room);
    free(temp);
}

void bubble_sort(room_t **rooms, int nb_rooms)
{
    int sorted = 0;

    for (int i = 0; i < nb_rooms - 1; i++) {
        if (rooms[i]->nb_room > rooms[i + 1]->nb_room) {
            change_room(rooms[i], rooms[i + 1]);
            sorted = 1;
        }
    }
    if (sorted == 1)
        bubble_sort(rooms, nb_rooms);
    return;
}
