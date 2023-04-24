/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** key_toggle
*/

#include "csfml.h"
#include <stdio.h>

void toggle_key(sfBool *is_key_pressed, sfEvent *evt)
{
    if ((evt->type == sfEvtKeyPressed ||
    sfJoystick_isButtonPressed(0, sfJoystickR)) && !*is_key_pressed) {
        *is_key_pressed = sfTrue;
    } else if ((evt->type == sfEvtKeyReleased ||
    sfJoystick_isButtonPressed(0, sfJoystickR)) && *is_key_pressed) {
        *is_key_pressed = sfFalse;
    }
}
