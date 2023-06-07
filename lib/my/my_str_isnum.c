/*
** EPITECH PROJECT, 2022
** my_str_isalpha.c
** File description:
** returns one if the given string is only made out of number
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9' || str[i] == '-'
            || str[i] == ' ' || str[i] == '\n') {
            i++;
        } else
            return (0);
    }
    return (1);
}
