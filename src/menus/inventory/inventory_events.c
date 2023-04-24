/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** inventory_events
*/

#include "rpg.h"

void get_inventory_events(inv_t *inv, sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed) {
        if (event->mouseButton.button == sfMouseLeft) {
            get_inventory_clicks(inv, window);
        }
    } else {
        is_inv_slot_hovered(inv, window);
    }
    inventory_actions(inv);
}
