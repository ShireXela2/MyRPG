/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** get_inventory_slot_hovering
*/

#include "rpg.h"

void is_regular_slot_hovered(slot_t *slots, sfRenderWindow *window)
{
    while (slots->previous)
        slots = slots->previous;
    while (slots->next) {
        is_button_hovered(&slots->button, window);
        slots = slots->next;
    }
    is_button_hovered(&slots->button, window);
}

void is_inv_slot_hovered(inv_t *inv, sfRenderWindow *window)
{
    is_button_hovered(&inv->sword.button, window);
    is_button_hovered(&inv->bow.button, window);
    is_button_hovered(&inv->ring.button, window);
    is_button_hovered(&inv->hp_pot.button, window);
    is_button_hovered(&inv->mana_pot.button, window);
    is_regular_slot_hovered(inv->slots, window);
}
