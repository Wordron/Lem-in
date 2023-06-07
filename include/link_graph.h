/*
** EPITECH PROJECT, 2023
** Lemin
** File description:
** link_graph
*/

#ifndef LINK_GRAPH_H_
    #define LINK_GRAPH_H_

    enum e_room_type {
        OTHER = 0,
        START,
        END
    };

    typedef struct room {
        enum e_room_type type;
        int x;
        int y;
        int nb_room;
        int nb_link;
        int *linked_room;
    } room_t;

    typedef struct graph_t {
        room_t **rooms;
        int *visited_rooms;
        int *path;
        int index;
    } graph_t;

    #define IS_START(a) (a == START)
    #define IS_END(a) (a == END)

#endif /* !LINK_GRAPH_H_ */
