/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** allocates memory and copies the old string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char *src)
{
    int len = my_strlen(src);
    int i = 0;
    char *dest = malloc(sizeof(char) * (len + 1));

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
