/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** my_getnbr
*/

static int end(char const *str, int i, int nb, int start)
{
    if (str[i - start] == '-')
        return (-nb);
    else
        return (nb);
}

static int fstart(char const *str)
{
    int i = 0;

    while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
        i++;
    return (i);
}

int my_getnbr(char const *str, int i)
{
    int nb = 0;
    int start = 0;

    for (; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i++) {
        nb = nb * 10 + (str[i] - 48);
        start++;
    }
    return (end(str, i, nb, start));
}
