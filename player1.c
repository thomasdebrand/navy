/*
** com.c for com in /home/raphael/PSU_2016_navy/
**
** Made by Raphael Legrand
** Login   <raphael.legrand@epitech.eu@epitech.eu>
**
** Started on  Wed Feb  1 13:43:40 2017 Raphael Legrand
** Last update Sun Feb 12 12:52:45 2017 Raphael Legrand
*/

#include "my.h"

void		handler1(int sig, siginfo_t *siginfo, void *context)
{
  globale[0]++;
  if (globale[2] == 0)
    kill(globale[3], 12);
  if (globale[3] == 0)
    kill(globale[2], 12);
}

void		handler2(int sig)
{
  static char	pos[2];
  if (globale[1] == 0)
    pos[0] = globale[0] + 64;
  if (globale[1] == 1)
    pos[1] = globale[0] + 48;
  globale[0] = 0;
  globale[1]++;
  if (globale[1] == 2)
    {
      globale[4] = pos[0];
      globale[5] = pos[1];
      my_putstr(pos);
      my_putstr(":  ");
    }
}

void		listenner()
{
  struct sigaction act;

  act.sa_sigaction = handler1;
  act.sa_flags = SA_SIGINFO;
  globale[1] = 0;
  globale[0] = 0;

  my_putstr("waiting for enemy's attack...\n");
  sigaction(SIGUSR1, &act, NULL);
  signal(12, handler2);

  while (globale[1] < 2)
    pause();
}
