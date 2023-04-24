/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** camera_on_player
*/

#include "rpg.h"

void set_hud_cam(sfView *camera, sfRenderWindow *window)
{
    camera = sfRenderWindow_getDefaultView(window);
    sfView_setCenter(camera, V2F(960, 540));
    sfRenderWindow_setView(window, camera);
}

void set_game_cam(game_t *game, player_t *player)
{
    game->camera = sfRenderWindow_getDefaultView(game->window);
    sfView_setCenter(game->camera, player->position);
    sfRenderWindow_setView(game->window, game->camera);
}
