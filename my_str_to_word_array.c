/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include "include/lemin.h"

static void do_stuff(char *str, int init[4], char **array_words)
{
    array_words[init[I]] = malloc(sizeof(char) * length_word1(str, init[IND]));
    while ((str[init[IND]] != ' ' && str[init[IND]] != '-')
        && is_a_char(str[init[IND]]) != 1) {
        array_words[init[I]][init[K]] = str[init[IND]];
        init[IND]++;
        init[K]++;
    }
    array_words[init[I]][init[K]] = '\0';
}

char **get_my_array(char *str)
{
    int init[4] = {0, 0, 0, count_words(str)};
    char **array_words = malloc(sizeof(char *) * init[NB] + 1);

    while (init[I] != init[NB]) {
        init[K] = 0;
        if (str[init[IND]] != ' ' && str[init[IND]] != '-')
            do_stuff(str, init, array_words);
        init[IND]++;
        init[I] = add_to_i_if_not_space(init[I], str, init[IND]);
    }
    array_words[init[I]] = 0;
    return (array_words);
}
