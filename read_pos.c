/*
** read_pos.c for  in /home/tdebrand/PSU_2016_navy
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Tue Jan 31 14:19:23 2017 Thomas DEBRAND PASSARD
** Last update Sat Feb  4 16:57:20 2017 Thomas DEBRAND PASSARD
*/

#include "include/my.h"

int	folder_to_array(char **av, t_tool *tool)
{
  char	*array;
  char	buff[1];
  int	f;
  int	j;
  int	index = 0;
  int	size_malloc = 0;

  if ((f = open(av[1], 'r')) == -1)
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
  array_to_wordtab(av, array, tool);
}

int	array_to_wordtab(char **av, char *array, t_tool *tool)
{
  int	x = 0;
  int	y = 0;
  int	i = 0;
  char	**pos1;

  pos1 = malloc(sizeof(char*) * 12);
  while (array[i] != '\0')
    {
      pos1[y] = malloc(sizeof(char) * 3);
      while (array[i] != ':' && array[i] != '\n')
	{
	  pos1[y][x] = array[i];
	  x++;
	  i++;
	}
      x = 0;
      y++;
      i++;
    }
  check_boat_len1(av, pos1, tool);
}

int	check_boat_len1(char **av, char **pos1, t_tool *tool)
{
  int	x = 0;
  int	i = 0;

  while (i != 4)
    {
      if (pos1[x][0] > 53 || pos1[x][0] < 50)
	{
	  my_put_nbr(pos1[x][0]);
	  my_putstr("Wrong size of boat. Please enter a size between 2 and 5.\n");
	  return (84);
	}
      else
	{
	  x = x + 3;
	  i++;
	}
    }
  check_boat_len2(av, pos1, tool);
}

int	check_boat_len2(char **av, char **pos1, t_tool *tool)
{
  int	index = 0;
  int	index1 = 1;
  int	index2 = 2;
  int	value1 = 0;
  int	value2 = 0;
  int	i = 0;
  
  while (i++ != 4)
    {
      value1 = pos1[index1][0] - pos1[index2][0];
      value2 = pos1[index1][1] - pos1[index2][1];
      if (value1 < 0 || value2 < 0)
	{
	  value1 = value1 * -1;
	  value2 = value2 * -1;
	}
      value1 = value1 + 48;
      value2 = value2 + 48;
      if ((value1 == '0' && value2 == '0') || (value1 != '0' && value2 != '0'))
	{
	  my_putstr("The boat is in diagonal or is 1x1\n");
	  return (84);
	}
      else if ((value1 + 1 != pos1[index][0]) && (value2 + 1 != pos1[index][0]))
	{
	  my_putstr("The boat is too long or too short\n");
	  return (84);
	}
      index1 += 3;
      index2 += 3;
      index += 3;
    }
  create_map(pos1, tool);
}
