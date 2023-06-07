/*
** EPITECH PROJECT, 2023
** Lemin
** File description:
** check_anthill_validity
*/
#include "include/graph.h"
#include "include/lemin.h"
#include "include/link_graph.h"

static int my_is_num_for_ant(char *str)
{
    for (int i = 0; str[i] != '\0';) {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '\n')
            i++;
        else
            return (0);
    }
    return (1);
}

int check_nb_ant(file_t *file)
{
    for (int i = 0; file->file[i] != NULL; i++) {
        if (file->file[i][0] != '#' && my_is_num_for_ant(file->file[i]) == 1)
            return (1);
    }
    return (0);
}

int check_room_name(room_t **rooms, int nb_rooms, int room_nb)
{
    for (int i = 0; i < room_nb; i++) {
        if (rooms[i]->nb_room == rooms[room_nb]->nb_room)
            return (1);
    }
    return (0);
}

int check_start_room(room_t **room, int nb_rooms)
{
    int nb_start = 0;

    for (int i = 0; i < nb_rooms; i++) {
        if (room[i]->type == START)
            nb_start++;
    }
    if (nb_start != 1)
        return (84);
    return (0);
}
