/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** get_slots_clicks
*/

#include "rpg.h"

void get_slot_click(slot_t *slot, item_t *item_held, sfRenderWindow *window)
{
    if (get_button_click(&slot->button, window) == sfTrue)
        set_click_actions(slot, item_held);
}

void get_regular_slot_click(slot_t *slots, item_t *item_held,
sfRenderWindow *window)
{
    while (slots->previous)
        slots = slots->previous;
    while (slots->next) {
        get_slot_click(slots, item_held, window);
        slots = slots->next;
    }
    get_slot_click(slots, item_held, window);
}

void get_inventory_clicks(inv_t *inv, sfRenderWindow *window)
{
    get_button_click(&inv->sword.button, window);
    get_button_click(&inv->ring.button, window);
    get_button_click(&inv->bow.button, window);
    get_button_click(&inv->hp_pot.button, window);
    get_button_click(&inv->mana_pot.button, window);
    get_regular_slot_click(inv->slots, &inv->item_held, window);
}
