/*
** navy_superpo.c for  in /home/tdebrand/PSU_2016_navy
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Thu Feb  2 13:26:10 2017 Thomas DEBRAND PASSARD
** Last update Thu Feb  2 14:39:20 2017 Thomas DEBRAND PASSARD
*/

#include "include/my.h"

void	put_in_map(char **pos1)
{
  int	index = 0;
  int	x = 0;
  int	y = 0;
  int	xpos = 0;
  int	ypos = 0;
  char	**map;

  map = malloc(sizeof(char*) * 9);
  while(x != 9)
    {
      map[x] = malloc(sizeof(char) * 9);
      x++;
    }
  x = 0;
  while (index != 14)
    {
      while (index % 2 != 0)
	{
	  map[pos1[x + 1][y] - 65][pos1[x + 1][y + 1]] = pos1[xpos][ypos];
	  x++;
	  y++;
	  index++;
	}
      xpos += 3;
      ypos += 3;
      index++;
    }
  my_put_nbr(pos1[x + 1][y] - 65);
  my_putchar(map[pos1[x + 1][y] - 65][pos1[x + 1][y + 1]]);
}
