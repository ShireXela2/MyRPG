/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_

//////////////
// INCLUDES //
//////////////

    #include "csfml.h"

////////////
// MACROS //
////////////

    #define V2F(x, y)                   (sfVector2f){x, y}
    #define V2I(x, y)                   (sfVector2i){x, y}
    #define IRECT(x, y, width, height)  (sfIntRect){x, y, width, height}

/////////////////
// ENUMERATORS //
/////////////////

typedef enum button_state {
    IDLE,
    HOVERED,
    PRESSED
} btn_state_t;

typedef enum action_queued {
    YES,
    WAITING,
    NO
} act_queue_t;

////////////////
// STRUCTURES //
////////////////

typedef struct object {
    sfClock *clock;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
} object_t;

typedef struct button {
    sfClock *clock;
    btn_state_t state;
    act_queue_t action_queued;
    object_t object;
    sfText *text;
    sfVector2f scale;
} button_t;

////////////////////////
// FUNCTIONS INCLUDES //
////////////////////////

void display(object_t *object, sfRenderWindow *win);
void object_center_origin(sfSprite *sprite);
void toggle_key(sfBool *is_key_pressed, sfEvent *evt);
void set_button_state(button_t *button, btn_state_t state);
void destroy_object(object_t *object);
void destroy_button(button_t *button);
void text_center_origin(sfText *text);
void show_button(button_t *button, sfRenderWindow *window);
void is_button_hovered(button_t *button, sfRenderWindow *window);
void animate_sprite(object_t *object, unsigned int offset, sfIntRect *limits,
unsigned int steps);
void edit_object(object_t *object, sfVector2f *scale, sfVector2f *pos,
float rotation);
sfBool get_button_click(button_t *button, sfRenderWindow *window);
object_t create_object(char *filename, sfVector2f pos);
button_t create_text_button(char *text, sfFont *font, sfVector2f pos,
sfVector2f *scale);
button_t create_visual_button(char *filename, sfVector2f pos,
sfVector2f *scale, sfIntRect *area);
sfText *create_text(char *string, sfFont *font, sfVector2f pos,
sfVector2f *scale);

#endif /* !UTILS_H_ */
