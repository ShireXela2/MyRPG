/*
** EPITECH PROJECT, 2021
** my_free_word_array
** File description:
** free memory of word array
*/

#include <stdlib.h>

int my_free_word_array(char **tab)
{
    for (int x = 0; tab[x] != NULL; x++)
        free(tab[x]);
    free(tab);
    return (0);
}
