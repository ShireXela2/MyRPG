/*
** EPITECH PROJECT, 2022
** play_music
** File description:
** play music of defender's project
*/

#include "rpg.h"

void play_home(music_t *music)
{
    if (sfMusic_getStatus(music->airship) == sfPlaying)
        sfMusic_stop(music->airship);
}

void play_airship(music_t *music)
{
    if (sfMusic_getStatus(music->airship) != sfPlaying) {
        sfMusic_play(music->airship);
        sfMusic_setVolume(music->airship, music->volume);
        sfMusic_setLoop(music->airship, sfTrue);
    }
}
