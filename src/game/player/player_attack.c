/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** player_attack
*/

#include "rpg.h"

void player_attack(player_t *player)
{
    sfTime anim_time = sfClock_getElapsedTime(player->curr_weapon
    ->game_obj.clock);
    sfTime attack_time = sfClock_getElapsedTime(player->attack_clock);

    if (anim_time.microseconds <= player->curr_weapon->attack_speed * 33333)
        return;
    if (attack_time.microseconds >= player->curr_weapon->attack_speed *
    100000) {
        player->is_attacking = sfFalse;
        return;
    }
    animate_sprite(&player->curr_weapon->game_obj, 1, &SWORD_SLASH, 3);
    sfClock_restart(player->curr_weapon->game_obj.clock);
}

void player_get_attack(player_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->attack_clock);

    if (!player->inventory->sword.has_item ||
    player->curr_weapon->attack_speed == -1 ||
    time.microseconds <= player->curr_weapon->attack_speed * 100000) {
        return;
    }
    player->is_attacking = sfTrue;
    sfClock_restart(player->attack_clock);
}
