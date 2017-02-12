/*
** my_putchar.c for  in /home/tdebrand/lib/my
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Tue Oct 25 22:17:32 2016 Thomas DEBRAND PASSARD
** Last update Wed Feb  8 17:03:17 2017 Thomas DEBRAND PASSARD
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
