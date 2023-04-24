/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** show_health
*/

#include "rpg.h"

void get_player_damage(player_t *player, enemy_t *enemies)
{
    sfTime time = sfClock_getElapsedTime(player->object.clock);
    sfFloatRect player_r = GET_GLO_BNDS(player->object.sprite);
    sfFloatRect enemy_r;

    if (time.microseconds <= 500000)
        return;
    move_to_list_start(&enemies);
    enemies = enemies->next;
    for (; enemies->is_list_start == sfFalse; enemies = enemies->next) {
        if (enemies->hp == 0)
            continue;
        enemy_r = GET_GLO_BNDS(enemies->object.sprite);
        if (sfFloatRect_intersects(&player_r, &enemy_r, NULL) == sfTrue) {
            player->hp -= 1.0;
            sfClock_restart(player->object.clock);
            return;
        }
    }
}

void show_health(player_t *player, sfView *camera, sfRenderWindow *window)
{
    set_hud_cam(camera, window);
    for (int i = 0; i < player->max_hp; i++) {
        if (i > player->hp)
            sfSprite_setColor(player->hearts[i].sprite, DARK_GREY);
        display(&(player->hearts[i]), window);
    }
}
