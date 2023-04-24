/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** create_enemies
*/

#include "rpg.h"

static enemy_t *create_enemy(sfVector2f pos)
{
    enemy_t *element = malloc(sizeof(enemy_t));

    element->previous = NULL;
    element->next = NULL;
    element->object = create_object(SKULL_MOB, pos);
    sfSprite_setTextureRect(element->object.sprite, SKULL_IDLE);
    object_center_origin(element->object.sprite);
    sfSprite_setScale(element->object.sprite, V2F(3, 3));
    element->attack_speed = 1;
    element->damage = 1;
    element->max_hp = 30;
    element->hp = element->max_hp;
    element->speed = 1;
    element->is_list_start = sfFalse;
    return element;
}

void move_to_list_start(enemy_t **enemies)
{
    enemy_t *temp = *enemies;

    while (!temp->is_list_start)
        temp = temp->next;
    *enemies = temp;
}

enemy_t *create_enemies(int amount)
{
    enemy_t *head = create_enemy(V2F(100, 300));
    enemy_t *enemies = head;

    head->is_list_start = sfTrue;
    for (int i = 1; i < amount; i++) {
        enemies->next = create_enemy(V2F(100 * (i + 1), 300));
        enemies->next->previous = enemies;
        enemies = enemies->next;
    }
    enemies->next = head;
    head->previous = enemies;
    return enemies;
}
