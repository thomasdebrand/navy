/*
** my_putstr.c for  in /home/tdebrand/lib/my
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Tue Oct 25 22:39:43 2016 Thomas DEBRAND PASSARD
** Last update Wed Feb  8 17:03:39 2017 Thomas DEBRAND PASSARD
*/

#include <unistd.h>
#include "my.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while(str[i])
      i++;
  write(1, str, i);
}
