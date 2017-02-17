/*
** read_pos.c for  in /home/tdebrand/PSU_2016_navy
**
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
**
** Started on  Tue Jan 31 14:19:23 2017 Thomas DEBRAND PASSARD
** Last update Fri Feb 17 16:39:48 2017 Raphael Legrand
*/

#include "my.h"

int	folder_to_array(int ac, char **av, t_tool *tool)
{
  char	*array;
  char	buff[1];
  int	f;
  int	j;
  int	index = 0;
  int	size_malloc = 0;
  int	k = 1;

  if (ac == 3)
    k = 2;
  if ((f = open(av[k], O_RDONLY)) == -1)
    {
      my_putstr("ERROR, no such file.\n");
      return (84);
    }
  else
    {
      array = malloc(sizeof(char) * 28);
      while ((j = read(f, buff, 1)) != 0)
	{
	  array[index] = buff[0];
	  index++;
	}
    }
  array_to_wordtab(ac, av, array, tool);
}

int	array_to_wordtab(int ac, char **av, char *array, t_tool *tool)
{
  int	x = 0;
  int	y = 0;
  int	i = 0;

  tool->pos1 = malloc(sizeof(char*) * 12);
  while (array[i] != '\0')
    {
      tool->pos1[y] = malloc(sizeof(char) * 3);
      while (array[i] != ':' && array[i] != '\n')
	{
	  tool->pos1[y][x] = array[i];
	  x++;
	  i++;
	}
      x = 0;
      y++;
      i++;
    }
  swap(ac, tool);
  check_boat_len1(ac, av, tool);
}

int	swap(int ac, t_tool *tool)
{
  int	x = 1;
  int	y = 0;
  int	index;
  int	boucle = 0;

  while (boucle != 8)
    {
      if (tool->pos1[x][y] < tool->pos1[x][y + 1])
	{
	  index = tool->pos1[x][y];
	  tool->pos1[x][y] = tool->pos1[x][y + 1];
	  tool->pos1[x][y + 1] = index;
	}
      if (boucle % 2 != 0)
	x = x + 2;
      else
	x++;
      boucle++;
    }
}

int	check_boat_len1(int ac, char **av, t_tool *tool)
{
  int	x = 0;
  int	i = 0;

  while (i != 4)
    {
      if (tool->pos1[x][0] > 53 || tool->pos1[x][0] < 50)
	return (84);
      else
	{
	  x = x + 3;
	  i++;
	}
    }
  check_boat_len2(ac, av, tool);
}

int	check_boat_len2(int ac, char **av, t_tool *tool)
{
  int	index = 0;
  int	index1 = 1;
  int	index2 = 2;
  int	value1 = 0;
  int	value2 = 0;
  int	i = 0;

    while (i++ != 4) {
      value1 = tool->pos1[index1][0] - tool->pos1[index2][0];
      value2 = tool->pos1[index1][1] - tool->pos1[index2][1];
	if (value1 < 0 || value2 < 0) {
	  value1 = value1 * -1;
	  value2 = value2 * -1;
	}
      value1 = value1 + 48;
      value2 = value2 + 48;
      if ((value1 == '0' && value2 == '0') || (value1 != '0' && value2 != '0'))
	return (84);
      else if ((value1 + 1 != tool->pos1[index][0]) && (value2 + 1 != tool->pos1[index][0]))
	return (84);
      index1 += 3;
      index2 += 3;
      index += 3;
    }
  create_map(ac, tool);
}
