/*
** EPITECH PROJECT, 2023
** Lemin
** File description:
** get_nb_rooms
*/
#include "include/graph.h"

int skip_comment(char *buffer, int i)
{
    while (buffer[i] != '\n')
        i++;
    return (i);
}

int check_line(char *buffer, int i)
{
    if (buffer[i] == '#' || (buffer[i + 1] != '\0' && buffer[i + 1] == '#'))
        return (skip_comment(buffer, i));
    if (buffer[i] == ' ')
        return (-1);
    return (0);
}

int get_nb_room(file_t *file)
{
    int nb_spaces = 0;
    int temp = 0;

    for (int i = 0; file->buffer[i] != 0; i++) {
        temp = check_line(file->buffer, i);
        if (temp != -1 && temp != 0)
            i = temp;
        if (temp == -1)
            nb_spaces++;
        if (file->buffer[i] == '-')
            return (nb_spaces / 2);
    }
    return (nb_spaces / 2);
}
