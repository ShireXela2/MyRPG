/*
** EPITECH PROJECT, 2022
** window
** File description:
** create a window
*/

#include "rpg.h"

void window_src(game_t *game)
{
    game->music->airship = sfMusic_createFromFile(AIRSHIP);
    game->music->volume = 0.0;
    game->menu = HOME;
    create_picture(game);
}

void window_initial(unsigned int width, unsigned int height, game_t *game)
{
    sfVideoMode mode = {width, height, 32};

    game->home = malloc(sizeof(home_t));
    game->option = malloc(sizeof(option_t));
    game->music = malloc(sizeof(music_t));
    game->font = sfFont_createFromFile(FONT);
    game->map = create_object(MAP, V2F(0, 0));
    sfSprite_setScale(game->map.sprite, V2F(4, 4));
    game->cursor = create_object(CURSOR, V2F(0, 0));
    game->player = create_player();
    game->enemies = create_enemies(10);
    window_src(game);
    game->window = sfRenderWindow_create(mode, "My_RPG", sfDefaultStyle, NULL);
    game->camera = sfView_create();
}

void window(unsigned int width, unsigned int height)
{
    game_t *game = malloc(sizeof(game_t));

    window_initial(width, height, game);
    play_home(game->music);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        condition(game);
        display_cursor(&game->cursor, game->event, game->window);
        sfRenderWindow_display(game->window);
    }
    destroy(game);
}
