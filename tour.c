/*
** tour.c for tour in /home/raphael/PSU_2016_navy/test/
**
** Made by Raphael Legrand
** Login   <raphael.legrand@epitech.eu@epitech.eu>
**
** Started on  Fri Feb  3 11:32:34 2017 Raphael Legrand
** Last update Sun Feb 12 16:05:49 2017 Raphael Legrand
*/

#include "my.h"

void		tour(int ac, char **map)
{
  while (1)
    {
      my_putchar('\n');
      print_the_map(map);
      if (ac == 2)
	{
	  get_posi(ac);
	  answer();
	  listenner();
	  check(map);
	}
      if (ac == 3)
	{
	  listenner();
	  check(map);
	  get_posi(ac);
	  answer();
	}
    }
}

void		P2pid(int sig, siginfo_t *siginfo, void *context)
{
  globale[3] = siginfo->si_pid;
  my_putstr("enemy connected\n");
}

int			main(int ac, char **av)
{
  t_tool		tool;
  pid_t pid = getpid();
  my_putstr("my_pid:  ");
  my_put_nbr(pid);
  my_putchar('\n');
  if (ac == 2)
    {
      my_putstr("waiting for enemy connection...\n");
      struct sigaction act;
      act.sa_sigaction = P2pid;
      act.sa_flags = SA_SIGINFO;
      sigaction(SIGUSR1, &act, NULL);
      pause();
    }
  if (ac == 3)
    {
      if ((kill(my_getnbr(av[1]), 10)) != -1)
	my_putstr("successfully connected\n");
      globale[2] = my_getnbr(av[1]);
    }
  check_help(ac, av);
  folder_to_array(ac, av, &tool);
  return (0);
}
