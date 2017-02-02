/*
** read_pos.c for  in /home/tdebrand/PSU_2016_navy
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Tue Jan 31 14:19:23 2017 Thomas DEBRAND PASSARD
** Last update Thu Feb  2 14:29:12 2017 Thomas DEBRAND PASSARD
*/

#include "include/my.h"

int	folder_to_array(int ac, char **av)
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
  array_to_wordtab(ac, av, array);
}

int	array_to_wordtab(int ac, char **av, char *array)
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
  check_boat_len1(ac, av, pos1);
}

int	check_boat_len1(int ac, char **av, char **pos1)
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
  //  my_putstr("1st step clear\n");
  check_boat_len2(ac, av, pos1);
}

int	check_boat_len2(int ac, char **av, char **pos1)
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
      // else
      //my_putstr("Allright\n");
      index1 += 3;
      index2 += 3;
      index += 3;
    }
  //my_putchar(pos1[1][0]);
  //my_put_nbr(pos1[1][0]);
  put_in_map(pos1);
}

/* int	check_order(int ac, char **av, char **pos1) */
/* { */
/*   int	x = 1; */
/*   int	y = 0; */
/*   int	index = 0; */
/*   int	save; */

/*   while (index != 4) */
/*     { */
/*       if (((pos1[x][y] && pos1[x + 1][y]) >= '0') || ((pos1[x][y] && pos1[x + 1][y]) <= '9')) */
/* 	{ */
/* 	  if (((pos1[x][y + 1] && pos1[x + 1][y + 1]) */
/* 	} */
/*       index++; */
/*     } */
/* } */
