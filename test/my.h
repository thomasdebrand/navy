/*
** my.h for my.h in /home/raphael/PSU_2016_navy/
**
** Made by Raphael Legrand
** Login   <raphael.legrand@epitech.eu@epitech.eu>
**
** Started on  Wed Feb  1 11:11:54 2017 Raphael Legrand
** Last update Thu Feb  2 15:45:53 2017 Raphael Legrand
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>

void		my_putchar(char);
void		my_put_nbr(int);
int			my_getnbr(char*);
void		handler2(int);
char		*get_next_line(int fd);
void		player1(char*);
void		send(int, char*, char*);
void		player2(char*, char*);
