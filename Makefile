##
## Makefile for  in /home/tdebrand/usefull/Work
##
## Made by Thomas DEBRAND PASSARD
## Login   <tdebrand@epitech.net>
##
## Started on  Mon Dec 12 10:16:49 2016 Thomas DEBRAND PASSARD
## Last update Sun Feb 12 16:02:56 2017 Raphael Legrand
##

NAME	= navy

SRC	= navy_main.c		\
	  	read_pos.c		\
	  	navy_superpo.c	\
	  	putine.c \
			player1.c \
			player2.c \
			check.c	\
			my_getnbr.c \
			tour.c 


OBJ	= $(SRC:.c=.o)

CC	= gcc

RM	= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -I. -W -Wextra $(OBJ) libLS.a libgnl.a -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

 .PHONY: all clean fclean re
