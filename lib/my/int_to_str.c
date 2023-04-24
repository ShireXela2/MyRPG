/*
** EPITECH PROJECT, 2021
** int_to_str
** File description:
** convert a int value to string
*/

#include <stdlib.h>

char *int_to_str(int nb)
{
    int i = 0;
    int len = 1;
    int n = 1;
    char *str;

    if (nb < 0) {
        len++;
        nb = -nb;
    }
    for (; (nb / n) >= 10; n = n * 10, len++);
    str = malloc(sizeof(char) * (len + 1));
    if (nb < 0) {
        str[0] = '-';
        i = 1;
    }
    for (; n > 0; i++, n = n / 10)
        str[i] = (nb / n) % 10 + '0';
    str[i] = '\0';
    return (str);
}
