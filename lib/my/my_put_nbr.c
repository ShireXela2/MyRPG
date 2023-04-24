/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** displays the number given as a partameter
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int n;

    n = 1;
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    while ((nb / n) >= 10)
        n = n * 10;
    while (n > 0) {
        my_putchar((nb / n) % 10 + 48);
        n = n / 10;
    }
    return (0);
}
