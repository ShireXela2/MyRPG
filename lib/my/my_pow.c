/*
** EPITECH PROJECT, 2021
** my_puw
** File description:
** calc the power
*/

int my_pow(int x, int p)
{
    int ret;

    for (ret = 1; p >= 1; p--)
        ret = ret * x;
    return (ret);
}
