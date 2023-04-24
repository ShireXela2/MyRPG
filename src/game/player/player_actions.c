/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** player_actions
*/

#include "rpg.h"

void get_player_actions(player_t *player, sfEvent *evt, game_state_t *menu)
{
    if (evt->type == sfEvtMouseButtonPressed &&
    evt->mouseButton.button == sfMouseLeft && *menu == GAME) {
        player_get_attack(player);
    }
}
