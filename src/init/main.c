/*
** EPITECH PROJECT, 2021
** main
** File description:
** main function
*/

#include "rpg.h"

int main(int ac, char **av)
{
    if (ac == 1) {
        window(1920, 1080);
        return (0);
    }
    if (ac == 2) {
        if (my_strcmp("-h", av[1]) == 1) {
            usage();
            return (0);
        }
    }
    return (84);
}
