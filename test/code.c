/*
** code.c for serveur in /home/raphael/PSU_2016_navy/
**
** Made by Raphael Legrand
** Login   <raphael.legrand@epitech.eu@epitech.eu>
**
** Started on  Tue Jan 31 18:09:00 2017 Raphael Legrand
** Last update Wed Feb  1 13:38:56 2017 Raphael Legrand
*/

#include "my.h"

static void 		hdl(int sig, siginfo_t *siginfo, void *context)
{
  louis.x = louis.x + 1;
  //kill(siginfo->si_pid, SIGUSR2);
}

void				handsig2(int sig)
{
  printf("%c\n", louis.x - 48);
}

int 					main()
{
  pid_t 	pid = getpid();
  struct sigaction act;
  printf("%i\n", pid);

  act.sa_sigaction = hdl;
  act.sa_flags = SA_SIGINFO;

  sigaction(SIGUSR1, &act, NULL);
  signal(12, handsig2);

  while (1)
    sleep (10);
  return 0;
}
