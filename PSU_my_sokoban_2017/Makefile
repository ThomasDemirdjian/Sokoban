##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

CC = gcc

NAME = my_sokoban

SRCS =  src/main.c		\
	src/help.c		\
	src/get_map.c		\
	src/print.c		\
	src/tools.c		\
	src/check.c		\
	src/check_obj.c		\
	src/check_ingame.c	\
	src/move_player.c	\
	src/game.c		\
	src/move.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -lncurses -Wall -Werror -Wextra
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re