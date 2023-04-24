/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** inventory_loader
*/

#include "rpg.h"

void inventory_loader(inv_t *inv)
{
    item_t item = create_item(SWORDS, SWORDS, SWORD);

    object_center_origin(item.inv_icon.sprite);
    while (inv->slots->previous)
        inv->slots = inv->slots->previous;
    slot_set_item(inv->slots, &item);
}
