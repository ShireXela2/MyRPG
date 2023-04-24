/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** show_enemies
*/

#include "rpg.h"

void show_alive_enemies(enemy_t *enemies, sfRenderWindow *window)
{
    while (enemies->is_list_start == sfFalse) {
        if (enemies->hp == 0) {
            enemies = enemies->next;
            continue;
        }
        display(&enemies->object, window);
        enemies = enemies->next;
    }
    if (enemies->hp != 0)
        display(&enemies->object, window);
}

void show_enemies(enemy_t *enemies, player_t *player, sfRenderWindow *window)
{
    move_to_list_start(&enemies);
    enemies = enemies->next;
    if (player->is_attacking == sfTrue) {
        get_enemies_hits(enemies, player, window);
    } else {
        show_alive_enemies(enemies, window);
    }
}
