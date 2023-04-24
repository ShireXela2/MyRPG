##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make
##

SRC	=	my_pow.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_sqrt.c	\
		my_strlen.c	\
		my_free_word_array.c	\
		my_strdup.c	\
		my_strcmp.c	\
		int_to_str.c \
		cat.c \
		my_strcat.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy

BLUE	=	\e[34m
YELLOW	=	\e[33m
WHITE	=	\e[0m

.SILENT:$(OBJ)

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME).a $(OBJ)

clean:
	@find -name '*.o' -delete

fclean: clean
	@find -name '$(NAME).a' -exec echo -e "$(BLUE)File $(YELLOW){} \
	$(BLUE)removed.$(WHITE)" \; -delete

re:	fclean all
