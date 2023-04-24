/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** create_item
*/

#include "rpg.h"

item_t create_default_item(char *item_name, item_type_t type)
{
    item_t item;

    item.inv_icon = create_object(item_name, V2F(0, 0));
    object_center_origin(item.inv_icon.sprite);
    sfSprite_setScale(item.inv_icon.sprite, V2F(3, 3));
    item.game_obj = create_object("", V2F(0, 0));
    object_center_origin(item.game_obj.sprite);
    sfSprite_setScale(item.game_obj.sprite, V2F(3, 3));
    item.type = type;
    item.damage = 0;
    item.attack_speed = -1;
    item.range = 1;
    return item;
}

item_t create_item(char *icon_name, char *obj_name, item_type_t type)
{
    item_t item;

    item.inv_icon = create_object(icon_name, V2F(0, 0));
    sfSprite_setTextureRect(item.inv_icon.sprite, IRECT(0, 0, 19, 27));
    object_center_origin(item.inv_icon.sprite);
    sfSprite_setScale(item.inv_icon.sprite, V2F(3, 3));
    item.game_obj = create_object(obj_name, V2F(0, 0));
    sfSprite_setTextureRect(item.game_obj.sprite, IRECT(0, 0, 19, 27));
    object_center_origin(item.game_obj.sprite);
    sfSprite_setScale(item.game_obj.sprite, V2F(3, 3));
    item.type = type;
    item.damage = 0;
    item.attack_speed = 2;
    item.range = 1;
    return item;
}
