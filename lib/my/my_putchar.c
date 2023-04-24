/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** display one character with ascii
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
