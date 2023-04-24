/*
** EPITECH PROJECT, 2022
** destroy
** File description:
** free all memory
*/

#include "rpg.h"

void destroy_home(home_t *home)
{
    destroy_button(&home->exit);
    destroy_button(&home->options);
    destroy_button(&home->play);
    destroy_object(&home->home);
    free(home);

}

void destroy_music(music_t *music)
{
    if (sfMusic_getStatus(music->airship) == sfPlaying)
        sfMusic_stop(music->airship);
    sfMusic_destroy(music->airship);
    free(music);
}

void destroy_option(option_t *option)
{
    destroy_object(&option->box);
    destroy_object(&option->disco);
    destroy_object(&option->house);
    destroy_object(&option->less);
    destroy_object(&option->more);
    destroy_object(&option->title);
    destroy_object(&option->volume);
    free(option);
}

void destroy(game_t *game)
{
    destroy_object(&game->cursor);
    destroy_object(&game->map);
    destroy_home(game->home);
    destroy_music(game->music);
    destroy_player(&game->player);
    destroy_option(game->option);
    destroy_enemies(game->enemies);
    sfFont_destroy(game->font);
    sfRenderWindow_destroy(game->window);
    free(game);
}
