/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** player_movements
*/

#include "rpg.h"
#include "player.h"

void stop_movement(player_t *player)
{
    if (player->is_up) {
        sfSprite_setTextureRect(player->object.sprite, UP_IDLE);
        player->is_up = sfFalse;
    }
    if (player->is_down) {
        sfSprite_setTextureRect(player->object.sprite, DOWN_IDLE);
        player->is_down = sfFalse;
    }
    if (player->is_left) {
        sfSprite_setTextureRect(player->object.sprite, SIDE_IDLE);
        player->is_left = sfFalse;
    }
    if (player->is_right) {
        sfSprite_setTextureRect(player->object.sprite, SIDE_IDLE);
        player->is_right = sfFalse;
    }
}

void vertical_move(player_t *player)
{
    sfVector2f pos = player->position;
    sfFloatRect bounds = GET_GLO_BNDS(player->curr_weapon->game_obj.sprite);

    if (player->is_up  || sfJoystick_getAxisPosition(0, sfJoystickY) < -50) {
        sfSprite_setScale(player->object.sprite, PLAYER_SCALE);
        animate_sprite(&player->object, 1, &UP_WALK, 6);
        sfSprite_move(player->object.sprite, V2F(0, -12 * player->speed));
        player->object.pos = sfSprite_getPosition(player->object.sprite);
        pos = V2F(pos.x, pos.y - bounds.height);
        edit_object(&player->curr_weapon->game_obj, NULL, &pos, 90);
    }
    if (player->is_down || sfJoystick_getAxisPosition(0, sfJoystickY) > 50) {
        sfSprite_setScale(player->object.sprite, PLAYER_SCALE);
        animate_sprite(&player->object, 1, &DOWN_WALK, 6);
        sfSprite_move(player->object.sprite, V2F(0, 12 * player->speed));
        player->object.pos = sfSprite_getPosition(player->object.sprite);
        pos = V2F(pos.x, pos.y + bounds.height);
        edit_object(&player->curr_weapon->game_obj, NULL, &pos, 270);
    }
}

void horizontal_move(player_t *player)
{
    sfVector2f scale = PLAYER_SCALE;
    sfVector2f pos = player->position;
    sfFloatRect bounds = GET_GLO_BNDS(player->curr_weapon->game_obj.sprite);

    if (player->is_right || sfJoystick_getAxisPosition(0, sfJoystickX) > 50) {
        sfSprite_setScale(player->object.sprite, PLAYER_SCALE);
        animate_sprite(&player->object, 1, &SIDE_WALK, 6);
        sfSprite_move(player->object.sprite, V2F(12 * player->speed, 0));
        player->object.pos = sfSprite_getPosition(player->object.sprite);
        pos = V2F(pos.x + bounds.width / 1.2, pos.y + bounds.height / 12);
        edit_object(&player->curr_weapon->game_obj, NULL, &pos, 180);
    }
    if (player->is_left || sfJoystick_getAxisPosition(0, sfJoystickX) < -50) {
        sfSprite_setScale(player->object.sprite, V2F((scale.x * -1), scale.y));
        animate_sprite(&player->object, 1, &SIDE_WALK, 6);
        sfSprite_move(player->object.sprite, V2F(-12 * player->speed, 0));
        player->object.pos = sfSprite_getPosition(player->object.sprite);
        pos = V2F(pos.x - bounds.width / 1.2, pos.y + bounds.height / 2);
        edit_object(&player->curr_weapon->game_obj, NULL, &pos, 0);
    }
}

void move_player(player_t *player, game_state_t *menu)
{
    sfTime time = sfClock_getElapsedTime(player->move_clock);

    if (time.microseconds < 25000) {
        if (*menu != GAME)
            stop_movement(player);
        return;
    }
    sfJoystick_update();
    player->position = sfSprite_getPosition(player->object.sprite);
    vertical_move(player);
    horizontal_move(player);
    sfClock_restart(player->move_clock);
}

void get_player_movement(player_t *player, sfEvent *evt, game_state_t *menu)
{
    sfIntRect rect = sfSprite_getTextureRect(player->object.sprite);

    if (*menu != GAME)
        return;
    if (evt->key.code == sfKeyZ)
        change_animation(&player->is_up, evt, player);
    if (evt->key.code == sfKeyS)
        change_animation(&player->is_down, evt, player);
    if (evt->key.code == sfKeyQ)
        change_animation(&player->is_left, evt, player);
    if (evt->key.code == sfKeyD)
        change_animation(&player->is_right, evt, player);
}
