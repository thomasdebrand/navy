/*
** my.h for my.h in /home/raphael/PSU_2016_navy/
**
** Made by Raphael Legrand
** Login   <raphael.legrand@epitech.eu@epitech.eu>
**
** Started on  Wed Feb  1 11:11:54 2017 Raphael Legrand
** Last update Sun Feb 12 14:54:29 2017 Raphael Legrand
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>

void		my_putchar(char);
void		my_putstr(char*);
void		my_put_nbr(int);
int			my_getnbr(char*);
void		handler2(int);
void		hit(int);
void		miss(int);
void		none(int);
char		*get_next_line(int fd);
void		listenner();
void		answer();
void		check(char**);
void		send(int, char*);
void		get_posi(int);
void		tour(int, char**);
void		P2pid(int, siginfo_t*, void*);

int		  globale[6];
