/*
** com.c for com in /home/raphael/PSU_2016_navy/
**
** Made by Raphael Legrand
** Login   <raphael.legrand@epitech.eu@epitech.eu>
**
** Started on  Wed Feb  1 13:43:40 2017 Raphael Legrand
** Last update Thu Feb  2 16:54:16 2017 Raphael Legrand
*/

#include "my.h"
#include "globale.h"

void		handler1(int sig, siginfo_t *siginfo, void *context)
{
  dede.x = dede.x + 1;
}

void		handler2(int sig)
{
  if (dede.av == 0)
    my_putchar(dede.x + 64);
  if (dede.av == 1)
    my_putchar(dede.x + 48);
  dede.x = 0;
  dede.av = dede.av + 1;
  if (dede.av == 2)
    {
      my_putchar('\n');
      dede.av = 0;
    }
}

void		player1(char *file)
{
  struct sigaction act;
  pid_t 	pid = getpid();
  my_put_nbr(pid);

  act.sa_sigaction = handler1;
  act.sa_flags = SA_SIGINFO;

  sigaction(SIGUSR1, &act, NULL);
  signal(12, handler2);

  while (1)
    sleep (10);
}

int			main(int ac, char **av)
{
  if (ac == 2)
    player1(av[1]);
  else if (ac == 3)
    player2(av[1], av[2]);
}
