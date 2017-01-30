/*
** my_putchar.c for  in /home/tdebrand/lib/my
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Tue Oct 25 22:17:32 2016 Thomas DEBRAND PASSARD
** Last update Wed Dec 14 10:30:37 2016 Thomas DEBRAND PASSARD
*/

#include <unistd.h>
#include "include/my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
