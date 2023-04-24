/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** destroy_player
*/

#include "rpg.h"

void destroy_hearts(object_t *hearts, int hp)
{
    for (int i = 0; i < hp; i++) {
        destroy_object(&hearts[i]);
    }
    free(hearts);
}

void destroy_player(player_t *player)
{
    destroy_inventory(player->inventory);
    destroy_object(&player->object);
    sfClock_destroy(player->move_clock);
    sfClock_destroy(player->attack_clock);
    destroy_hearts(player->hearts, player->max_hp);
}
