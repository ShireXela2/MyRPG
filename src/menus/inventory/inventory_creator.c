/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** create_utils
*/

#include "rpg.h"

slot_t create_stuff_slot(char *item_name, sfVector2f pos, sfVector2f scale,
item_type_t type)
{
    slot_t slot;

    slot.button = create_visual_button(SLOT, pos, &V2F(3, 3),
    &IRECT(0, 0, 31, 31));
    slot.item = create_default_item("", type);
    slot.default_look = create_object(item_name, V2F(0, 0));
    object_center_origin(slot.default_look.sprite);
    slot.next = NULL;
    slot.previous = NULL;
    slot.type = STUFF;
    slot.has_item = sfFalse;
    sfSprite_setPosition(slot.item.inv_icon.sprite, slot.button.object.pos);
    sfSprite_setPosition(slot.default_look.sprite, slot.button.object.pos);
    sfSprite_setScale(slot.item.inv_icon.sprite, scale);
    sfSprite_setScale(slot.default_look.sprite, scale);
    object_center_origin(slot.button.object.sprite);
    object_center_origin(slot.item.inv_icon.sprite);
    return slot;
}

container_t create_container(char *filename, sfVector2f pos, sfVector2f scale)
{
    container_t container;

    container.container = create_object(CONTAINER, pos);
    container.item = create_object(filename, pos);
    sfSprite_setTextureRect(container.item.sprite, DOWN_IDLE);
    sfSprite_setScale(container.item.sprite, scale);
    sfSprite_setScale(container.container.sprite, scale);
    object_center_origin(container.container.sprite);
    object_center_origin(container.item.sprite);
    sfSprite_setPosition(container.item.sprite, pos);
    return container;
}

inv_t *create_inventory(void)
{
    inv_t *inv = malloc(sizeof(inv_t));

    inv->player = create_container(CHAR_SHEET, V2F(650, 300), V2F(5.9, 5.9));
    inv->sword = create_stuff_slot(SWORD_ICON, V2F(800, 200), V2F(2.7, 2.7),
    SWORD);
    inv->bow = create_stuff_slot(BOW_ICON, V2F(800, 300), V2F(4, 4), BOW);
    inv->ring = create_stuff_slot(RING_ICON, V2F(800, 400), V2F(2.7, 2.7),
    RING);
    inv->mana_pot = create_stuff_slot(POTIONS_ICON, V2F(1000, 400),
    V2F(2.7, 2.7), POTION);
    inv->hp_pot = create_stuff_slot(POTIONS_ICON, V2F(1100, 400),
    V2F(2.7, 2.7), POTION);
    inv->slots = create_storage_slot();
    inv->item_held = create_item("", "", ALL);
    inventory_loader(inv);
    return inv;
}
