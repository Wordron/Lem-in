/*
** EPITECH PROJECT, 2023
** B-CPE-200-NAN-2-1-lemin-camille.dumas
** File description:
** read_file
*/
#include "include/graph.h"

char *add_buff(char *dest, char *src, int size)
{
    int i = 0;
    char *result = malloc(sizeof(char) * (size + 1));
    int len_dest = 0;

    if (dest != NULL) {
        my_strcpy(result, dest);
        len_dest = my_strlen(dest);
    }
    while (src[i] != '\0') {
        result[i + len_dest] = src[i];
        i++;
    }
    result[len_dest + i] = '\0';
    return (result);
}

void read_file(file_t *file)
{
    char *line = NULL;
    char *buffer = NULL;
    int size = 0;
    size_t len = 0;
    ssize_t line_size;

    line_size = getline(&line, &len, stdin);
    while (line_size > 0) {
        size += line_size;
        buffer = add_buff(buffer, line, size);
        line_size = getline(&line, &len, stdin);
    }
    file->buffer = my_strdup(buffer);
    free(buffer);
}

int get_nb_line(file_t *file)
{
    int nb_line = 0;

    for (int i = 0; file->buffer[i] != '\0'; i++) {
        if (file->buffer[i] == '\n') {
            nb_line++;
        }
    }
    return (nb_line + 1);
}

int special_len(file_t *file, int i)
{
    int len = 0;

    while (file->buffer[i] != '\n') {
        len++;
        i++;
    }
    return (len);
}

char **file_2d(file_t *file, int len, int tmp)
{
    read_file(file);
    char **result = malloc(sizeof(char *) * (get_nb_line(file) + 1));
    int i = 0;

    for (int k = 0; i != get_nb_line(file); i++) {
        if (i == 0)
            len = special_len(file, len);
        else {
            tmp += len + 1;
            len = special_len(file, tmp);
        }
        result[i] = malloc(sizeof(char) * (len + 1));
        for (int j = 0; j != (len + 1); j++) {
            result[i][j] = file->buffer[k];
            k++;
        }
    }
    result[i] = NULL;
    file->file = result;
    return (NULL);
}
