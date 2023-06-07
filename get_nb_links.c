/*
** EPITECH PROJECT, 2023
** Lemin
** File description:
** get_nb_links
*/
#include <stdio.h>
#include "include/my.h"

static int check_if_right_room(int room_nb, char *file)
{
    int j = 0;

    if (my_getnbr(file, 0) == room_nb)
        return (1);
    for (j = 0; file[j] != '-';)
        j++;
    j++;
    if (my_getnbr(file, j) == room_nb)
        return (1);
    return (0);
}

int get_nb_links(int room_nb, char **file)
{
    int nb_links_for_room = 0;

    for (int i = 0; file[i] != NULL; i++) {
        if (file[i][0] != '#' && my_strlen(file[i]) == 4 && file[i][1] == '-')
            nb_links_for_room = nb_links_for_room + check_if_right_room(
                room_nb, file[i]);
    }
    return (nb_links_for_room);
}

int get_nb_all_link(char **file)
{
    int nb_links = 0;

    for (int i = 0; file[i] != NULL; i++) {
        if (file[i][0] != '#' && my_strlen(file[i]) == 4 && file[i][1] == '-')
            nb_links++;
    }
    return (nb_links);
}
