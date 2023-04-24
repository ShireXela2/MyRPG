/*
** EPITECH PROJECT, 2022
** defender
** File description:
** all prototypes of rpg's project
*/

#ifndef RPG_H_
    #define RPG_H_

//////////////
// INCLUDES //
//////////////

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
    #include <time.h>
    #include <math.h>
    #include "my.h"
    #include "csfml.h"
    #include "utils.h"
    #include "player.h"
    #include "enemies.h"

////////////
// MACROS //
////////////

    /* Converters */
    #define COLOR(r, g, b, a)               (sfColor){r, g, b, a}
    #define WHITE                           COLOR(255, 255, 255, 255)
    #define DARK_GREY                       COLOR(127, 127, 127, 255)
    #define GET_LOC_BNDS                    sfSprite_getLocalBounds
    #define GET_GLO_BNDS                    sfSprite_getGlobalBounds

    /* Menu Sprites */
    #define WELCOME         "assets/images/menus/welcome.jpg"
    #define TITLE           "assets/images/menus/title.png"
    #define START           "assets/images/menus/start.png"
    #define HOME_BG         "assets/images/home.jpg"
    #define BUTTONS         "assets/images/menus/buttons/buttons.png"
    #define BOX             "assets/images/menus/box.png"
    #define SLOT            "assets/images/menus/slot.png"
    #define CONTAINER       "assets/images/menus/container.png"
    #define SWORD_ICON      "assets/images/menus/sword_icon.png"
    #define BOW_ICON        "assets/images/menus/bow_icon.png"
    #define POTIONS_ICON    "assets/images/menus/potions_icon.png"
    #define RING_ICON       "assets/images/menus/ring_icon.png"

    /* Weapons Sprites */
    #define SWORDS          "assets/images/weapons/swords.png"

    /* Map */
    #define MAP             "assets/map/map.png"

    /* Rects */
    #define VOL_UP_R        IRECT(600, 400, 50, 50)
    #define VOL_DOWN_R      IRECT(828, 400, 50, 50)
    #define HOME_R          IRECT(1067, 400, 50, 50)
    #define OPT_EXIT_R      IRECT(1295, 400, 50, 50)

    #define CURSOR      "assets/images/cursor.png"
    #define FONT        "assets/fonts/upheavtt.ttf"

    /* Buttons */
    #define BTN_PLUS    "assets/images/menus/buttons/button_+.png"
    #define BTN_MINUS   "assets/images/menus/buttons/button_-.png"
    #define HOUSE       "assets/images/menus/buttons/button_h.png"
    #define DISCO       "assets/images/menus/buttons/button_d.png"
    #define TITLE_O     "assets/images/menus/title_o.png"
    #define VOLUME      "assets/images/menus/volume.jpg"

    /* Musics */
    #define AIRSHIP     "assets/music/airship.ogg"

/////////////////
// ENUMERATORS //
/////////////////

typedef enum game_state {
    HOME,
    GAME,
    OPTIONS,
    INVENTORY
} game_state_t;

////////////////
// STRUCTURES //
////////////////

typedef struct item_list {
    item_t basic_sword;
} item_l_t;

typedef struct writen_s {
    char *str;
    int size;
    sfColor color;
    sfVector2f pos;
} writen_t;

typedef struct pframe_s {
    int direct;
    sfVector2f pos;
} pframe_t;

typedef struct home_s {
    object_t home;
    button_t play;
    button_t options;
    button_t exit;
} home_t;

typedef struct option_s {
    object_t box;
    object_t more;
    object_t less;
    object_t house;
    object_t disco;
    object_t title;
    object_t volume;
    sfIntRect frame_v;
} option_t;

typedef struct music_s {
    sfMusic *airship;
    float volume;
} music_t;

typedef struct game_s {
    sfRenderWindow *window;
    game_state_t menu;
    sfFont *font;
    object_t map;
    home_t *home;
    option_t *option;
    object_t cursor;
    music_t *music;
    sfEvent event;
    player_t player;
    enemy_t *enemies;
    sfView *camera;
} game_t;

sfBool check_mouse(sfMouseButtonEvent mouse, sfIntRect rect);
void condition(game_t *game);
void condition_welhome(game_t *game);
void create_home(home_t *home, sfFont *font);
void create_picture(game_t *game);
void create_option(option_t *option);
void create_volume(option_t *option);
void destroy(game_t *game);
void destroy_music(music_t *music);
void display_cursor(object_t *cur, sfEvent ev, sfRenderWindow *window);
void display_home(home_t *home, sfRenderWindow *window);
void display_option(home_t *home, option_t *option, sfRenderWindow *window);
void display_volume(option_t *option, sfRenderWindow *window, float volume);
void display_write(writen_t writen, sfRenderWindow *window);
void event_home(home_t *home, game_state_t *menu, sfRenderWindow *window,
sfEvent event);
void event_option(game_t *game);
void event_welcome(game_t *game);
void play_airship(music_t *music);
void play_home(music_t *music);
void usage(void);
void window(unsigned int width, unsigned int height);
void window_initial(unsigned int width, unsigned int height, game_t *game);
void window_src(game_t *game);
void show_inventory(inv_t *inv, sfRenderWindow *window, sfEvent event);
void condition_game(game_t *game);
void get_inventory_events(inv_t *inv, sfRenderWindow *window, sfEvent *event);
void set_click_actions(slot_t *slot, item_t *item_held);
void destroy_inventory(inv_t *inv);
void get_inventory_clicks(inv_t *inv, sfRenderWindow *window);
void is_inv_slot_hovered(inv_t *inv, sfRenderWindow *window);
void inventory_loader(inv_t *inv);
void slot_set_item(slot_t *slot, item_t *new_item);
void inventory_actions(inv_t *inv);
void destroy_player(player_t *player);
void update_game(game_t *game);
void get_events(game_t *game);
void toggle_inventory(sfEvent *evt, game_state_t *menu, sfBool *is_inv_open);
void get_player_movement(player_t *player, sfEvent *evt, game_state_t *menu);
void move_player(player_t *player, game_state_t *menu);
void change_animation(sfBool *is_key_pressed, sfEvent *evt, player_t *player);
void change_side_animation(sfBool *is_key_pressed, sfEvent *evt,
player_t *player);
void set_idle(sfEvent *evt, player_t *player);
void set_game_cam(game_t *game, player_t *player);
void set_hud_cam(sfView *camera, sfRenderWindow *window);
void show_player_item_in_hand(player_t *player, sfRenderWindow *window);
void player_get_attack(player_t *player);
void get_player_actions(player_t *player, sfEvent *evt, game_state_t *menu);
void player_attack(player_t *player);
inv_t *create_inventory(void);
slot_t create_stuff_slot(char *item_name, sfVector2f pos, sfVector2f scale,
item_type_t type);
slot_t *create_storage_slot(void);
item_t create_item(char *icon_name, char *obj_name, item_type_t type);
item_t create_default_item(char *item_name, item_type_t type);
player_t create_player(void);

#endif /* RPG_H_ */
