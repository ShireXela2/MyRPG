/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

//////////////
// INCLUDES //
//////////////

    #include "utils.h"

////////////
// MACROS //
////////////

    /* Player's spritesheet */
    #define CHAR_SHEET      "assets/images/character_sheet.png"
    #define HEART           "assets/images/heart.png"

    /* Player's spawn coordinates */
    #define PLAYER_SPAWN    V2F(960, 540)

    /* Player scale */
    #define PLAYER_SCALE    V2F(3, 3)

    /* Contains every player's animations rect */
    #define UP_IDLE     IRECT(0, 67, 22, 32)
    #define DOWN_IDLE   IRECT(1, 0, 22, 32)
    #define SIDE_IDLE   IRECT(1, 34, 20, 31)

    #define UP_WALK     IRECT(0, 170, 161, 36)
    #define SIDE_WALK   IRECT(0, 136, 149, 33)
    #define DOWN_WALK   IRECT(0, 100, 143, 35)

    /* Weapons animations rect */
    #define SWORD_IDLE      IRECT(0, 0, 152, 27)
    #define SWORD_SLASH     IRECT(0, 28, 86, 16)

/////////////////
// ENUMERATORS //
/////////////////

typedef enum item_type {
    SWORD,
    BOW,
    RING,
    POTION,
    ALL
} item_type_t;

typedef enum slot_type {
    STUFF,
    STORAGE
} slot_type_t;

////////////////
// STRUCTURES //
////////////////

typedef struct item {
    object_t inv_icon;
    object_t game_obj;
    item_type_t type;
    int damage;
    int attack_speed;
    int range;
} item_t;

typedef struct slot {
    struct slot *next;
    button_t button;
    item_t item;
    slot_type_t type;
    object_t default_look;
    sfBool has_item;
    struct slot *previous;
} slot_t;

typedef struct container {
    object_t item;
    object_t container;
} container_t;

typedef struct inventory {
    container_t player;
    slot_t sword;
    slot_t bow;
    slot_t ring;
    slot_t mana_pot;
    slot_t hp_pot;
    slot_t *slots;
    item_t item_held;
} inv_t;

typedef struct player {
    inv_t *inventory;
    object_t object;
    object_t *hearts;
    float max_hp;
    float hp;
    float speed;
    sfClock *move_clock;
    sfClock *attack_clock;
    sfBool is_left;
    sfBool is_right;
    sfBool is_up;
    sfBool is_down;
    sfBool is_inv_open;
    sfBool is_attacking;
    item_t *curr_weapon;
    sfVector2f position;
} player_t;

///////////////////////
// FUNCTIONS INCLUDE //
///////////////////////

void show_health(player_t *player, sfView *camera, sfRenderWindow *window);

#endif /* !PLAYER_H_ */
