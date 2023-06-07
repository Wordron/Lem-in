/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-lemin-camille.dumas
** File description:
** parsing
*/

#include "include/lemin.h"
#include "include/graph.h"
#include "include/link_graph.h"

void get_type_of_room(room_t **room, file_t *file)
{
    room[file->tmp] = malloc(sizeof(room_t));
    room[file->tmp]->type = OTHER;
    if (file->start == 1)
        room[file->tmp]->type = START;
    else if (file->end == 1)
        room[file->tmp]->type = END;
}

void get_room(char **array_words, file_t *file, int i, room_t **room)
{
    file->end = 0;
    file->start = 0;
    if (i > 0 && file->file[i - 1][0] == '#' && file->file[i - 1][1] == '#') {
        if (my_strcmp(file->file[i - 1], "##start\n") == 0)
            file->start = 1;
        if (my_strcmp(file->file[i - 1], "##end\n") == 0)
            file->end = 1;
    }
    if (file->is_rooms == true)
        get_type_of_room(room, file);
    if (my_str_isnum(array_words[file->j]) == 1) {
        if (file->is_rooms == true) {
            room[file->tmp]->nb_room = my_getnbr(array_words[0], 0);
            room[file->tmp]->x = my_getnbr(array_words[1], 0);
            room[file->tmp]->y = my_getnbr(array_words[2], 0);
            room[file->tmp]->nb_link = get_nb_links(room[file->tmp]->nb_room,
                file->file);
            file->tmp++;
        }
    }
}

void is_room(file_t *file, int j)
{
    if (j == 2)
        file->is_rooms = true;
    else
        file->is_rooms = false;
}

void get_number_in_file(file_t *file, room_t **room)
{
    char **array_words = get_my_array(file->file[0]);
    int j = 0;

    for (int temp = 0; temp == 0; j++) {
        if (my_str_isnum(file->file[j]) == 1) {
            file->nb_ants = my_getnbr(file->file[j], 0);
            temp = 1;
        }
    }
    for (int i = j; file->file[i] != NULL; i++) {
        array_words = get_my_array(file->file[i]);
        for (int j = 0; array_words[j] != NULL; j++) {
            is_room(file, j);
            file->j = j;
            get_room(array_words, file, i, room);
        }
        for (int j = 0; array_words[j] != NULL; j++)
            free(array_words[j]);
        free(array_words);
    }
}
