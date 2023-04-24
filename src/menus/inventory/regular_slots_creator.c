/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** regular_slots_creator
*/

#include "rpg.h"

static slot_t *create_element(sfVector2f pos, sfVector2f scale)
{
    slot_t *element = malloc(sizeof(slot_t));

    element->button = create_visual_button(SLOT, pos, &scale,
    &IRECT(0, 0, 31, 31));
    object_center_origin(element->button.object.sprite);
    element->item = create_item("", "", ALL);
    element->default_look = create_object("", V2F(0, 0));
    element->has_item = sfFalse;
    element->next = NULL;
    element->previous = NULL;
    element->type = STORAGE;
}

void put_slot_in_list(slot_t **slots, sfVector2f pos, sfVector2f scale)
{
    slot_t *element = create_element(pos, scale);
    slot_t *tmp = *slots;

    while (tmp->next)
        tmp = tmp->next;
    tmp->next = element;
    element->previous = tmp;
}

slot_t *create_storage_slot(void)
{
    int x = 650;
    sfVector2f pos = V2F(x, 550);
    sfVector2f scale = V2F(3, 3);
    slot_t *slots = create_element(pos, scale);

    pos.x += 100;
    for (int i = 1; i <= 100; i++, pos.x += 100) {
        if (i % 10 == 0) {
            pos.x = x;
            pos.y += 100;
        }
        put_slot_in_list(&slots, pos, scale);
    }
    return slots;
}
