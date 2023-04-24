/*
** EPITECH PROJECT, 2021
** my_sqrt
** File description:
** calc the sqrt of number
*/

double my_sqrt(int n, double nb)
{
    int i;
    double x = nb;

    if (nb <= 0)
        return (84);
    for (i = 0; i < n; i++)
        x = ((x + (n / x)) / 2);
    return (x);
}
