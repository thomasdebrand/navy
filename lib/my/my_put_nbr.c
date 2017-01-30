/*
** my_put_nbr.c for  in /home/tdebrand/lib/my
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Tue Oct 25 22:26:00 2016 Thomas DEBRAND PASSARD
** Last update Wed Dec 14 10:30:51 2016 Thomas DEBRAND PASSARD
*/

#include <stdlib.h>
#include "include/my.h"

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      my_put_nbr(nb * (-1));
    }
  else if (nb >= 10)
    {
      my_put_nbr(nb / 10);
      my_putchar(nb % 10 + 48);
    }
  else
    {
      my_putchar(nb + 48);
    }
  return (0);
}
