/*
** EPITECH PROJECT, 2023
** graph.h
** File description:
** graph
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include <stdbool.h>

#ifndef GRAPH_H_
    #define GRAPH_H_

    typedef struct link {
        int data;
        struct link **next;
    } link_t;

    typedef struct file {
        char *buffer;
        char **file;
        int tmp;
        int nb_ants;
        int end;
        int start;
        bool is_rooms;
        int j;
        int start_of_trail;
        int nb_ants_moving;
    } file_t;

void read_file(file_t *file);

#endif /* !GRAPH_H_ */
