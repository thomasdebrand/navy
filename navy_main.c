/*
** navy_main.c for  in /home/tdebrand/PSU_2016_navy
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Mon Jan 30 17:06:57 2017 Thomas DEBRAND PASSARD
** Last update Sun Feb 12 15:02:37 2017 Thomas DEBRAND PASSARD
*/

#include "my.h"

int	main(int ac, char **av)
{
  t_tool	tool;

  check_help(ac, av);
  folder_to_array(ac, av, &tool);
  return (0);
}

int	check_help(int ac, char **av)
{
  if (ac == 1)
    return (0);
  if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
    {
      my_putstr("USAGE\n");
      my_putstr("\t./navy [first_player_pid] navy_positions\n\n");
      my_putstr("DESCRIPTION\n");
      my_putstr("\tfirst_player_pid    only for the 2nd player.  pid of the first player.\n");
      my_putstr("\tnavy_positions      file representing the positions of the ships.\n");
    }
  return (0);
}
