/*
** tour.c for tour in /home/raphael/PSU_2016_navy/test/
**
** Made by Raphael Legrand
** Login   <raphael.legrand@epitech.eu@epitech.eu>
**
** Started on  Fri Feb  3 11:32:34 2017 Raphael Legrand
** Last update Fri Feb 17 14:22:41 2017 Raphael Legrand
*/

#include "my.h"

void		tour(int ac, char **map, char **map_e)
{
  while (globale[7] != 0 && globale[8] != 14)
    {
      print_the_map(map);
      print_e_map(map_e);
      if (ac == 2)
	{
	  get_posi(ac);
	  answer(map_e);
	  listenner();
	  check(map);
	}
      if (ac == 3)
	{
	  listenner();
	  check(map);
	  get_posi(ac);
	  answer(map_e);
	}
    }
  print_the_map(map);
  print_e_map(map_e);
  if (globale[8] == 14)
    my_putstr("I won\n");
  if (globale[7] == 0)
    my_putstr("Enemy won\n");
}

void		P2pid(int sig, siginfo_t *siginfo, void *context)
{
  globale[3] = siginfo->si_pid;
  my_putstr("enemy connected\n\n");
}

void		connexion(int	ac, char **map, char **e_map, t_tool *tool)
{
  pid_t pid = getpid();
  my_putstr("my_pid:  ");
  my_put_nbr(pid);
  my_putchar('\n');
  if (ac == 2)
    {
      my_putstr("waiting for enemy connexion...\n");
      struct sigaction act;
      act.sa_sigaction = P2pid;
      act.sa_flags = SA_SIGINFO;
      sigaction(SIGUSR1, &act, NULL);
      pause();
    }
  if (ac == 3)
    {
      if ((kill(my_getnbr(tool->pid), 10)) != -1)
	my_putstr("successfully connected\n\n");
      globale[2] = my_getnbr(tool->pid);
    }
  tour(ac, map, e_map);
}

int			main(int ac, char **av)
{
  if (check_help(ac, av) == 0)
    return (0);
  globale[7] = 14;
  globale[8] = 0;
  t_tool		tool;
  if (ac == 3)
    tool.pid = av[1];
  folder_to_array(ac, av, &tool);
  return (0);
}
