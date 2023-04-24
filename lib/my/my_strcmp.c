/*
** EPITECH PROJECT, 2021
** My Str Cmp
** File description:
** my str cmp
*/

#include <stdlib.h>
#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return 0;
        }
    }
    return 1;
}
