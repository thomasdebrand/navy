/*
** navy_main.c for  in /home/tdebrand/PSU_2016_navy
**
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
**
** Started on  Mon Jan 30 17:06:57 2017 Thomas DEBRAND PASSARD
** Last update Fri Feb 17 16:29:37 2017 Raphael Legrand
*/

#include "my.h"

int	check_help(int ac, char **av)
{
  if (ac == 1)
    return (1);
  if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
    {
      my_putstr("USAGE\n");
      my_putstr("\t./navy [first_player_pid] navy_positions\n\n");
      my_putstr("DESCRIPTION\n");
      my_putstr("\tfirst_player_pid    only for the 2nd player.");
      my_putstr("  pid of the first player.\n");
      my_putstr("\tnavy_positions      file representing the ");
      my_putstr("positions of the ships.\n");
      return (0);
    }
}
