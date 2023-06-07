/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-lemin-camille.dumas
** File description:
** display
*/
#include "include/lemin.h"
#include "include/graph.h"
#include "include/link_graph.h"

static int check_link_validity(char nb_room, room_t **room)
{
    for (int i = 0; room[i] != NULL; i++) {
        if (nb_room - '0' == room[i]->nb_room)
            return (0);
    }
    return (1);
}

static int print_link(char **file, room_t **room)
{
    for (int i = 0; file[i] != NULL; i++) {
        if (file[i][0] != '#' && file[i][1] == '-' &&
            (check_link_validity(file[i][0], room) == 1 ||
            check_link_validity(file[i][2], room) == 1))
            return (84);
        if (file[i][0] != '#' && file[i][1] == '-') {
            my_putchar(file[i][0]);
            my_putchar(file[i][1]);
            my_putchar(file[i][2]);
            my_putchar('\n');
        }
    }
    return (0);
}

int print_rooms(room_t **room, int nb_room)
{
    for (int i = 0; i < nb_room; i++) {
        if (check_room_name(room, nb_room, i) == 1)
            return (84);
        if (room[i]->type == END)
            my_putstr("##end\n");
        if (room[i]->type == START)
            my_putstr("##start\n");
        my_put_nbr(room[i]->nb_room);
        my_putchar(' ');
        my_put_nbr(room[i]->x);
        my_putchar(' ');
        my_put_nbr(room[i]->y);
        my_putchar('\n');
    }
    return (0);
}

int display_result(file_t *file, room_t **room)
{
    int nb_room = get_nb_room(file);

    my_putstr("#number_of_ants\n");
    my_put_nbr(file->nb_ants);
    my_putstr("\n#rooms\n");
    if (nb_room == 0)
        return (84);
    if (print_rooms(room, nb_room) == 84)
        return (84);
    if (check_start_room(room, nb_room) == 84)
        return (84);
    my_putstr("#tunnels\n");
    if (get_nb_all_link(file->file) == 0)
        return (84);
    if (print_link(file->file, room) == 84)
        return (84);
    my_putstr("#moves\n");
    return (0);
}

int get_end(graph_t *graph, int nb_rooms)
{
    int result = 0;

    for (int i = 0; i != nb_rooms; i++)
        if (graph->rooms[i]->type == END)
            result = graph->rooms[i]->nb_room;
    return (result);
}
