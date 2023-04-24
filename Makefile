##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile of defender's project
##

SRC	=	src/check_mouse.c	\
		src/condition.c	\
		src/destroy.c	\
		src/display.c	\
		src/init/create_picture.c	\
		src/init/play_music.c	\
		src/init/usage.c	\
		src/init/main.c	\
		src/init/window.c \
		src/menus/main_menu/display_welhome.c	\
		src/menus/main_menu/event_welhome.c	\
		src/menus/inventory/inventory_creator.c \
		src/menus/inventory/show_inventory.c \
		src/menus/inventory/inventory_events.c \
		src/menus/inventory/inventory_actions.c \
		src/menus/inventory/create_item.c \
		src/menus/inventory/destroy_inventory.c \
		src/menus/inventory/regular_slots_creator.c \
		src/menus/inventory/get_inventory_slot_hovering.c \
		src/menus/inventory/get_slots_clicks.c \
		src/menus/inventory/inventory_loader.c \
		src/game/camera_on_player.c \
		src/game/display_game.c \
		src/game/player/create_player.c \
		src/game/player/destroy_player.c \
		src/game/player/player_actions.c \
		src/game/player/player_movements.c \
		src/game/player/change_animation.c \
		src/game/player/player_set_item_in_hand.c \
		src/game/player/player_attack.c \
		src/game/player/show_health.c \
		src/game/enemies/create_enemies.c \
		src/game/enemies/destroy_enemies.c \
		src/game/enemies/get_enemy_hits.c \
		src/game/enemies/show_enemies.c \
		src/event_handler/get_events.c \
		utils/objects/create_object.c \
		utils/objects/destroy_object.c \
		utils/objects/display_object.c \
		utils/objects/object_edit.c \
		utils/buttons/create_button.c \
		utils/buttons/destroy_button.c \
		utils/buttons/button_events.c \
		utils/buttons/set_button_state.c \
		utils/animator/animate_sprite.c \
		utils/keys/key_toggle.c \

CFLAGS	=	-lcsfml-graphics -lcsfml-system

DFLAGS	=	-lcsfml-window -lcsfml-audio

LDFLAGS	=	-L./lib/my/ -lmy

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

SEPARATOR	=	$(YELLOW)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
FILE_REMOVED	=	$(BLUE)File $(YELLOW){} $(BLUE)removed.$(WHITE)
TITLE	=	$(BOLD)$(SEPARATOR)\n\t\t
BOLD	=	\e[1m
GREEN	=	\e[92m
YELLOW	=	\e[93m
BLUE	=	\e[94m
WHITE	=	\e[0m

.SILENT:$(OBJ)
.PHONY: all clean fclean re $(NAME)

all:	$(NAME)

$(OBJ):	%.o: %.c
		gcc -I./include/ -g3 -c -o $@ $<
		echo -e "$(GREEN)File $(YELLOW)$@$(GREEN) created.$(WHITE)"

$(NAME):	$(OBJ)
	@$(MAKE) -C lib/my/ --no-print-directory
	@gcc -g3 -I./include/ -o $(NAME) $(OBJ) $(CFLAGS) $(DFLAGS) $(LDFLAGS)
	@echo -e "$(GREEN)Binary $(YELLOW)$(NAME) $(GREEN)created.$(WHITE)"
	@echo -e "$(TITLE)$(GREEN)Compilation done. \n$(SEPARATOR)$(WHITE)"

clean:
	@find -name '*.o' -exec echo -e "$(FILE_REMOVED)" \; -delete
	@echo -e "$(TITLE)$(BLUE)Cleaning done. \n$(SEPARATOR)$(WHITE)"

fclean:	clean
	@$(MAKE) -C lib/my/ fclean --no-print-directory
	@find -name '$(NAME)' -exec echo -e "$(FILE_REMOVED)" \; -delete
	@find -name 'vgcore*' -exec echo -e "$(FILE_REMOVED)" \; -delete
	@find -name 'vg.core*' -exec echo -e "$(FILE_REMOVED)" \; -delete
	@find -name 'vg' -exec echo -e "$(FILE_REMOVED)" \; -delete
	@echo -e "$(TITLE)$(BLUE)Full cleaning done. \n$(SEPARATOR)$(WHITE)"

re:	fclean all

no_object:
	@$(MAKE) -C lib/my/ --no-print-directory
	@gcc -g3 -o $(NAME) $(SRC) $(CFLAGS) $(DFLAGS) $(LDFLAGS)
