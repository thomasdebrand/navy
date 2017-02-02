/*
** my.h for  in /home/tdebrand/usefull/Work
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Mon Dec 12 09:54:55 2016 Thomas DEBRAND PASSARD
** Last update Thu Feb  2 14:24:22 2017 Thomas DEBRAND PASSARD
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

#ifndef MY_H_
# define MY_H_

void	my_putchar(char);
void	my_putstr(char *);
int	my_put_nbr(int);

int	check_help(int, char **);

int	folder_to_array(int, char **);
int	array_to_wordtab(int, char **, char *);
int	check_boat_len1(int, char **, char **);	
int	check_boat_len2(int, char **, char **);

void	put_in_map(char **);

#endif /* MY_H_ */
