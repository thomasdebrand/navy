/*
** navy_main.c for  in /home/tdebrand/PSU_2016_navy
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Mon Jan 30 17:06:57 2017 Thomas DEBRAND PASSARD
** Last update Mon Jan 30 17:30:50 2017 Thomas DEBRAND PASSARD
*/

#include "include/my.h"

void	main(int ac, char **av)
{
  check_help(ac, av);
}

int	check_help(int ac, char **av)
{
  if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
    {
      my_putstr("USAGE\n");
      my_putstr("\t./navy [first_player_pid] navy_positions\n\n");
      my_putstr("DESCRIPTION\n");
      my_putstr("\tfirst_player_pid    only for the 2nd player.  pid of the first player,\n");
      my_putstr("\tnavy_positions      file representing the positions of the ships.\n");
    }
  return (0);
}
