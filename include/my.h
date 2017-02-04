/*
** my.h for  in /home/tdebrand/usefull/Work
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Mon Dec 12 09:54:55 2016 Thomas DEBRAND PASSARD
** Last update Sat Feb  4 17:25:18 2017 Thomas DEBRAND PASSARD
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

#ifndef MY_H_
# define MY_H_

typedef struct	s_tool
{
  int	value1;
  int	value2;
  int	value3;
  int	value4;
}	t_tool;

void	my_putchar(char);
void	my_putstr(char *);
int	my_put_nbr(int);

int	check_help(int, char **);

int	folder_to_array(char **, t_tool *);
int	array_to_wordtab(char **, char *, t_tool *);
int	check_boat_len1(char **, char **, t_tool *);	
int	check_boat_len2(char **, char **, t_tool *);

void	create_map(char **, t_tool *);
void	print_the_map(char **, t_tool *);
void	full_the_map(char **, t_tool *);
int	print_error();

int	put_in_map1(char **, char **, t_tool *);
int	put_in_map2(char **, char **, t_tool *, int);

#endif /* MY_H_ */
