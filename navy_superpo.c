/*
** navy_superpo.c for  in /home/tdebrand/PSU_2016_navy
**
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
**
** Started on  Thu Feb  2 13:26:10 2017 Thomas DEBRAND PASSARD
** Last update Sun Feb 12 15:22:11 2017 Raphael Legrand
*/

#include "my.h"

void	create_map(int ac, t_tool *tool)
{
  char	**map;
  int	x = 0;

  map = malloc(sizeof(char*) * 9);
  while (x != 9)
    {
      map[x] = malloc(sizeof(char) * 9);
      x++;
    }
  full_the_map(ac, map, tool);
  put_in_map1(ac, map, tool);
  tour(ac, map);
}

void	print_the_map(char **map)
{
  int   x = 0;
  int   y = 0;
  int	c = 49;

  my_putstr("my positions:\n |A B C D E F G H\n");
  my_putstr("-+---------------\n");
  my_putchar(c);
  my_putchar('|');
  while (x != 7 || y != 8)
    {
      if (y == 8)
	{
	  x++;
	  y = 0;
	  my_putchar('\n');
	  my_putchar(++c);
	  my_putchar('|');
	}
      my_putchar(map[x][y++]);
      my_putchar(' ');
    }
  my_putchar('\n');
}

int	print_error()
{
  my_putstr("Il y a une erreur\n");
  return (84);
}

void	full_the_map(int ac, char **map, t_tool *tool)
{
  int	x = 0;
  int	y = 0;

  while (x != 7 || y != 8)
    {
      if (y == 8)
	{
	  x++;
	  y = 0;
	}
      map[x][y] = '.';
      y++;
    }
}
