/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** inventory_actions
*/

#include "rpg.h"

void item_copy(item_t *dest, item_t *src)
{
    dest->attack_speed = src->attack_speed;
    dest->damage = src->damage;
    dest->inv_icon.clock = sfClock_copy(src->inv_icon.clock);
    dest->inv_icon.pos = src->inv_icon.pos;
    dest->inv_icon.scale = src->inv_icon.scale;
    dest->inv_icon.sprite = sfSprite_copy(src->inv_icon.sprite);
    dest->inv_icon.texture = sfTexture_copy(src->inv_icon.texture);
    sfSprite_setTexture(dest->inv_icon.sprite, dest->inv_icon.texture,
    sfFalse);
    dest->game_obj.clock = sfClock_copy(src->game_obj.clock);
    dest->game_obj.pos = src->game_obj.pos;
    dest->game_obj.scale = src->game_obj.scale;
    dest->game_obj.sprite = sfSprite_copy(src->game_obj.sprite);
    dest->game_obj.texture = sfTexture_copy(src->game_obj.texture);
    sfSprite_setTexture(dest->game_obj.sprite, dest->game_obj.texture,
    sfFalse);
    dest->range = src->range;
    dest->type = src->type;
}

void slot_set_item(slot_t *slot, item_t *new_item)
{
    destroy_object(&slot->item.inv_icon);
    destroy_object(&slot->item.game_obj);
    slot->item = *new_item;
    slot->has_item = (slot->has_item == sfTrue) ? sfFalse : sfTrue;
    sfSprite_setPosition(new_item->inv_icon.sprite, slot->button.object.pos);
}

void move_item(slot_t *slot, item_t *item_held)
{
    item_t empty_item = create_item("", "", ALL);

    if (item_held->type == ALL && slot->item.type != ALL &&
    slot->has_item == sfTrue) {
        item_copy(item_held, &slot->item);
        slot_set_item(slot, &empty_item);
    } else if (item_held->type != ALL && (slot->item.type == item_held->type ||
    slot->item.type == ALL)) {
        slot_set_item(slot, item_held);
        item_copy(item_held, &empty_item);
    } else {
        destroy_object(&empty_item.game_obj);
        destroy_object(&empty_item.inv_icon);
    }
}

void set_click_actions(slot_t *slot, item_t *item_held)
{
    if (slot->button.action_queued == YES) {
        slot->button.action_queued = NO;
        move_item(slot, item_held);
    }
}

void inventory_actions(inv_t *inv)
{
    set_click_actions(&inv->sword, &inv->item_held);
    set_click_actions(&inv->bow, &inv->item_held);
    set_click_actions(&inv->ring, &inv->item_held);
    set_click_actions(&inv->mana_pot, &inv->item_held);
    set_click_actions(&inv->hp_pot, &inv->item_held);
    while (inv->slots->previous)
        inv->slots = inv->slots->previous;
    while (inv->slots->next) {
        set_click_actions(inv->slots, &inv->item_held);
        inv->slots = inv->slots->next;
    }
    set_click_actions(inv->slots, &inv->item_held);
}
