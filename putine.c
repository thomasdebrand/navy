/*
** putine.c for  in /home/tdebrand/PSU_2016_navy
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Sat Feb  4 17:06:03 2017 Thomas DEBRAND PASSARD
** Last update Sat Feb  4 17:24:28 2017 Thomas DEBRAND PASSARD
*/

#include "include/my.h"

int     put_in_map1(char **map, char **pos1, t_tool *tool)
{
  int   check = 0;
  int   index = 0;
  int   x = 0;
  int   y = 0;

  while (check != 4)
    {
      index = pos1[x][y] - 48;
      tool->value1 = pos1[x + 1][y] - 65;
      tool->value2 = pos1[x + 2][y] - 65;
      tool->value3 = pos1[x + 1][y + 1] - 48;
      tool->value4 = pos1[x + 2][y + 1] - 48;
      put_in_map2(map, pos1, tool, index);
      check++;
      x += 3;
    }
  put_in_map2(map, pos1, tool,index);
}

int	put_in_map2(char **map, char **pos1, t_tool *tool, int index)
{
  if (tool->value1 == tool->value2)
    {
      while (tool->value3 != tool->value4 + 1)
	{
	  if (map[tool->value3 - 1][tool->value1] != '.')
	    print_error();
	  map[tool->value3 - 1][tool->value1] = index + 48;
	  tool->value3++;
	}
    }
  else if (tool->value3 == tool->value4)
    {
      while (tool->value1 != tool->value2 + 1)
	{
	  if (map[tool->value3 - 1][tool->value1] != '.')
	    print_error();
	  map[tool->value3 - 1][tool->value1] = index + 48;
	  tool->value1++;
	}
    }
}
