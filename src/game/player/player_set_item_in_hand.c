/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** player_set_item_in_hand
*/

#include "rpg.h"

void show_player_item_in_hand(player_t *player, sfRenderWindow *window)
{
    display(&player->curr_weapon->game_obj, window);
}
