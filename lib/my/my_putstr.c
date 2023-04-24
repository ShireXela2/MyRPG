/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** displays a string of characters
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int x;

    for (x = 0; str[x] != '\0'; x++)
        my_putchar(str[x]);
    return (0);
}
