/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** count and returns the number of characters
*/

int my_strlen(char const *str)
{
    int c = 0;

    while (str[c] != '\0')
        c++;
    return (c);
}
