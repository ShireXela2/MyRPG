/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** destroy_inventory
*/

#include "rpg.h"

void destroy_slot(slot_t *slot)
{
    destroy_button(&slot->button);
    destroy_object(&slot->item.inv_icon);
    destroy_object(&slot->item.game_obj);
    destroy_object(&slot->default_look);
}

void destroy_regular_slots(slot_t *slots)
{
    while (slots->previous)
        slots = slots->previous;
    while (slots->next) {
        slots = slots->next;
        destroy_slot(slots->previous);
        free(slots->previous);
    }
    destroy_slot(slots);
    free(slots);
}

void destroy_inventory(inv_t *inv)
{
    destroy_slot(&inv->bow);
    destroy_slot(&inv->hp_pot);
    destroy_slot(&inv->mana_pot);
    destroy_slot(&inv->ring);
    destroy_slot(&inv->sword);
    destroy_regular_slots(inv->slots);
    destroy_object(&inv->player.container);
    destroy_object(&inv->player.item);
    destroy_object(&inv->item_held.inv_icon);
    destroy_object(&inv->item_held.game_obj);
    free(inv);
}
