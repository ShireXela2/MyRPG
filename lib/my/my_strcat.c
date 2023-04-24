/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** my_strcat
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char *src);

char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    int dest_len = my_strlen(dest);
    char *temp = my_strdup(dest);

    free(dest);
    dest = malloc(sizeof(char) * (dest_len + my_strlen(src)));
    dest = my_strdup(temp);
    free(temp);
    for (; src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];
    return (dest);
}
