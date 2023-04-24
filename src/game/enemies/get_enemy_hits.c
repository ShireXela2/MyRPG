/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** get_enemy_hits
*/

#include "rpg.h"

void get_enemies_hits(enemy_t *enemies, player_t *player,
sfRenderWindow *window)
{
    while (enemies->is_list_start == sfFalse) {
        if (enemies->hp == 0) {
            enemies = enemies->next;
            continue;
        }
        damage_enemy(enemies, &player->curr_weapon->game_obj, window);
        enemies = enemies->next;
    }
    if (enemies->hp != 0)
        damage_enemy(enemies, &player->curr_weapon->game_obj, window);
}

void damage_enemy(enemy_t *enemy, object_t *player_weapon,
sfRenderWindow *window)
{
    sfFloatRect pl_rect = GET_GLO_BNDS(player_weapon->sprite);
    sfFloatRect en_rect;

    en_rect = GET_GLO_BNDS(enemy->object.sprite);
    if (sfFloatRect_intersects(&en_rect, &pl_rect, NULL) == sfTrue) {
        enemy->hp--;
    }
    display(&enemy->object, window);
}
