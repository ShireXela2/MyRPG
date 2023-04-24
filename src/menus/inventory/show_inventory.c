/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** show_inventory
*/

#include "rpg.h"

void show_slot(slot_t *slot, sfRenderWindow *window)
{
    show_button(&slot->button, window);
    animate_sprite(&slot->item.inv_icon, 0, &SWORD_IDLE, 8);
    if (slot->has_item == sfFalse)
        display(&slot->default_look, window);
    else
        display(&slot->item.inv_icon, window);
}

void show_regular_slots(slot_t *slots, sfRenderWindow *window)
{
    while (slots->previous)
        slots = slots->previous;
    while (slots->next) {
        show_slot(slots, window);
        slots = slots->next;
    }
}

void show_inventory(inv_t *inv, sfRenderWindow *window, sfEvent event)
{
    get_inventory_events(inv, window, &event);
    display(&inv->player.container, window);
    display(&inv->player.item, window);
    show_slot(&inv->sword, window);
    show_slot(&inv->bow, window);
    show_slot(&inv->ring, window);
    show_slot(&inv->hp_pot, window);
    show_slot(&inv->mana_pot, window);
    show_regular_slots(inv->slots, window);
}

void toggle_inventory(sfEvent *evt, game_state_t *menu, sfBool *is_inv_open)
{
    if ((evt->type == sfEvtKeyPressed && evt->key.code == sfKeyE) ||
    sfJoystick_isButtonPressed(0, sfJoystickR) && *is_inv_open == sfFalse) {
        toggle_key(is_inv_open, evt);
        if (*menu == GAME) {
            *menu = INVENTORY;
            return;
        }
        if (*menu == INVENTORY) {
            *menu = GAME;
            return;
        }
    }
    if (evt->type == sfEvtKeyReleased ||
    sfJoystick_isButtonPressed(0, sfJoystickR))
        toggle_key(is_inv_open, evt);
}
