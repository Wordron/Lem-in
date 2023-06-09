/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** prototype the functions of my library
*/

#ifndef MY_H_
    #define MY_H_

    enum array {I, IND, K, NB};

    void my_putchar(char c);
    void my_putcharerr(char c);
    int my_isneg(int nb);
    int my_put_nbr(int nb);
    void my_swap(int *a, int *b);
    int my_putstr(char const *str);
    int my_putstrerr(char const *str);
    int my_strlen(char *str);
    int my_nblen(int nb);
    int my_getnbr(char const *str, int i);
    void my_sort_int_array(int *tab, int size);
    int my_compute_power_rec(int nb, int power);
    int my_compute_square_root(int nb);
    int my_is_prime(int nb);
    int my_find_prime_sup(int nb);
    int my_is_prime_v2(int nb);
    char *my_strcpy(char *dest, char const *src);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_revstr(char *str);
    char *my_strstr(char *str, char const *to_find);
    char *do_an_iteration(char *str, char const *to_find, int *i, int *j);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strupcase(char *str);
    char *my_strlowcase(char *str);
    char *my_strcapitalize(char *str);
    int my_str_isalpha(char const *str);
    int my_str_isnum(char const *str);
    int my_str_islower(char const *str);
    int my_str_isupper(char const *str);
    int my_str_isprintable(char const *str);
    char *my_strcat(char *dest, char const *src);
    char *my_strncat(char *dest, char const *src, int tab);
    char *my_strdup(char const *src);
    int comparison(char s1, char s2);
    int comparison2(char s1, char s2);

#endif /* !MY_H_ */
