##
## EPITECH PROJECT, 2018
## MAkefile
## File description:
## Makefile
##

SRC	=	src/main.c			\
		src/checkpoint.c		\
		src/utils.c			\
		src/utils_suite.c		\
		src/maper.c			\
		src/mapping.c			\
		src/errors.c			\
		src/game.c			\
		src/errors_ingame.c		\
		src/game_ai.c			\
		src/get_next_line.c		\
		src/victory.c			\
		print/flags.c			\
		print/my_printers.c		\
		print/my_printf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc	-o	$(NAME)	$(OBJ)

superclean:
		rm	-f	*~
		rm	-f	*#
		rm	-f	vgcore*
		rm	-f	include/*~
		rm	-f	include/*#
		rm	-f	src/*~
		rm	-f	src/*#
		rm	-f	print/*~
		rm	-f	print/*#

clean:	superclean
		rm	-f	$(NAME)

fclean:	clean
		rm	-f	$(OBJ)

re:	fclean	all
