/*
** my.h for  in /home/tdebrand/usefull/Work
**
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
**
** Started on  Mon Dec 12 09:54:55 2016 Thomas DEBRAND PASSARD
** Last update Thu Feb 16 11:14:23 2017 Raphael Legrand
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <time.h>

#ifndef MY_H_
# define MY_H_

typedef struct	s_tool
{
  int	value1;
  int	value2;
  int	value3;
  int	value4;
  char	**pos1;
  char	**pos2;
  char	**map1;
}			t_tool;

int	check_help(int, char **);

int	folder_to_array(int, char **, t_tool *);
int	array_to_wordtab(int, char **, char *, t_tool *);
int	swap(int, t_tool *);
int	check_boat_len1(int, char **, t_tool *);
int	check_boat_len2(int, char **, t_tool *);

void	create_map(int, t_tool *);
void	print_the_map(char **);
void	print_e_map(char **);
void	full_the_map(int, char **, t_tool *, char **);
int	print_error();

int	put_in_map1(int, char **, t_tool *);
int	put_in_map2(int, char **, t_tool *, int);

void		my_putchar(char);
void		my_putstr(char *);
void		my_put_nbr(int);
int		my_getnbr(char *);
void		handler2(int);
void		hit(int);
void		miss(int);
void		none(int);
char		*get_next_line(int fd);
void		listenner();
void		answer(char**);
void		check(char **);
void		send(int, char *);
void		get_posi(int);
void		tour(int, char **, char **);
void		P2pid(int, siginfo_t*, void*);

int		  globale[6];

#endif /* MY_H_ */
