##
## Makefile for  in /home/tdebrand/usefull/Work
## 
## Made by Thomas DEBRAND PASSARD
## Login   <tdebrand@epitech.net>
## 
## Started on  Mon Dec 12 10:16:49 2016 Thomas DEBRAND PASSARD
## Last update Thu Feb  2 14:24:42 2017 Thomas DEBRAND PASSARD
##

NAME	= navy

SRC	= lib/my/my_putchar.c	\
	  lib/my/my_put_nbr.c	\
	  lib/my/my_putstr.c	\
	  navy_main.c		\
	  read_pos.c		\
	  navy_superpo.c

OBJ	= $(SRC:.c=.o)

CC	= gcc

RM	= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -W -Wextra $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

 .PHONY: all clean fclean re
