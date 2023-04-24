/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** create_player
*/

#include "rpg.h"

object_t *create_hearts(int hp)
{
    object_t *hearts = malloc(sizeof(object_t) * (hp));

    for (int i = 0; i < hp; i++) {
        hearts[i] = create_object(HEART, V2F((50 * i) + 10, 60));
        hearts[i].scale = V2F(3, 3);
        sfSprite_setScale(hearts[i].sprite, hearts[i].scale);
    }
    return hearts;
}

void setup_player_obj(object_t *object)
{
    sfSprite_setTextureRect(object->sprite, DOWN_IDLE);
    object_center_origin(object->sprite);
    sfSprite_setScale(object->sprite, PLAYER_SCALE);
}

player_t create_player(void)
{
    player_t player;

    player.inventory = create_inventory();
    player.object = create_object(CHAR_SHEET, PLAYER_SPAWN);
    setup_player_obj(&player.object);
    player.move_clock = sfClock_create();
    player.attack_clock = sfClock_create();
    player.is_up = sfFalse;
    player.is_right = sfFalse;
    player.is_left = sfFalse;
    player.is_down = sfFalse;
    player.is_inv_open = sfFalse;
    player.is_attacking = sfFalse;
    player.curr_weapon = NULL;
    player.speed = 1.0;
    player.max_hp = 5.0;
    player.hp = player.max_hp;
    player.hearts = create_hearts(player.max_hp);
    return player;
}
