/*
** EPITECH PROJECT, 2022
** check_mouse
** File description:
** check the coordonate of mouse in rect's area
*/

#include "rpg.h"

sfBool check_mouse(sfMouseButtonEvent mouse, sfIntRect rect)
{
    if (sfIntRect_contains(&rect, mouse.x, mouse.y) && mouse.type ==
    sfEvtMouseButtonPressed)
        return sfTrue;
    return sfFalse;
}
