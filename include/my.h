/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** content all prototypes of all library function
*/

#ifndef MY_H_
    #define MY_H_

void my_putchar(char c);
int my_put_nbr(int nb);
int my_put_nbr_unsigned(unsigned int nb);
int cat(char *filepath);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_free_word_array(char **tab);
int my_pow(int x, int p);
int my_strcmp(char const *s1, char const *s2);
double my_sqrt(int n, double nb);
char *int_to_str(int nb);
char *my_strdup(char *src);
char *my_strcat(char *dest, const char *src);

#endif /*MY_H_ */
