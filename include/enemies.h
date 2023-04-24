/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** enemies
*/

#ifndef ENEMIES_H_
    #define ENEMIES_H_

/////////////////////
// HEADER INCLUDES //
/////////////////////

    #include "player.h"

////////////
// MACROS //
////////////

    #define SKULL_MOB   "assets/images/enemies/spite_skull1.png"
    #define SKULL_IDLE  IRECT(57, 5, 29, 43)

////////////////
// STRUCTURES //
////////////////

typedef struct enemy {
    object_t object;
    unsigned int damage;
    unsigned int max_hp;
    unsigned int hp;
    unsigned int speed;
    unsigned int attack_speed;
    sfBool is_list_start;
    struct enemy *previous;
    struct enemy *next;
} enemy_t;

///////////////////////
// FUNCTION INCLUDES //
///////////////////////

void destroy_enemy(enemy_t *enemy);
void destroy_enemies(enemy_t *enemy);
void delete_enemy_from_list(enemy_t **enemy);
void get_enemies_hits(enemy_t *enemies, player_t *player,
sfRenderWindow *window);
void damage_enemy(enemy_t *enemy, object_t *player_weapon,
sfRenderWindow *window);
void get_player_damage(player_t *player, enemy_t *enemies);
void show_enemies(enemy_t *enemies, player_t *player, sfRenderWindow *window);
void move_to_list_start(enemy_t **enemies);
enemy_t *create_enemies(int amount);

#endif /* !ENEMIES_H_ */
