##
## EPITECH PROJECT, 2024
## makefile
## File description:
## the makefile
##

SRC	=	./src/main.c\
		./src/event.c\
		./src/collision.c\
		./src/free.c\
		./src/game_loop.c\
		./src/init_game.c\
		./src/move.c\
		./src/render.c\
		./src/process_key.c\

OBJ	=	$(SRC:.c=.o)

LIB	=	-l csfml-graphics -lcsfml-window -lcsfml-system -lm

INCL = -I./include

WARN	=	-Wall -Wextra -Werror

NAME	=	my_magicube

all:	$(NAME)

$(OBJ):	%.o: %.c
		gcc -g -c $< $(INCL) -o $@

$(NAME):	$(OBJ)
	gcc -g $(INCL) -o $(NAME) $(OBJ) $(WARN) $(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

run:
	make re
	./$(NAME)
	make fclean