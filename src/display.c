/*
** EPITECH PROJECT, 2022
** display
** File description:
** display one picture with one sprite, one texture, one coordonate and window
*/

#include "rpg.h"

void display_cursor(object_t *cur, sfEvent evt, sfRenderWindow *window)
{
    sfVector2i mouse_pos;

    mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(window, mouse_pos,
    sfRenderWindow_getView(window));
    sfSprite_setPosition(cur->sprite, mouse);
    display(cur, window);
}

void display_write(writen_t writen, sfRenderWindow *window)
{
    sfFont *font = sfFont_createFromFile(FONT);
    sfText *text;

    text = sfText_create();
    sfText_setString(text, writen.str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, writen.size);
    sfText_setColor(text, writen.color);
    sfText_setPosition(text, writen.pos);
    sfRenderWindow_drawText(window, text, NULL);
    sfFont_destroy(font);
}
