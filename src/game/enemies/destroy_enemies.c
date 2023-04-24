/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** destroy_enemies
*/

#include "rpg.h"

void delete_enemy_from_list(enemy_t **enemy)
{
    enemy_t *temp = *enemy;
    enemy_t *prev = temp->previous;
    enemy_t *next = temp->next;

    if (temp->is_list_start == sfTrue)
        next->is_list_start = sfTrue;
    prev->next = next;
    next->previous = prev;
    destroy_enemy(temp);
    *enemy = next;
}

void destroy_enemy(enemy_t *enemy)
{
    destroy_object(&enemy->object);
    free(enemy);
}

void destroy_enemies(enemy_t *enemies)
{
    move_to_list_start(&enemies);
    enemies = enemies->next;
    while (!enemies->is_list_start) {
        enemies = enemies->next;
        destroy_enemy(enemies->previous);
        enemies->previous = NULL;
    }
}
