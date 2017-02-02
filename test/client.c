/*
** client.c for client in /home/raphael/PSU_2016_navy/
**
** Made by Raphael Legrand
** Login   <raphael.legrand@epitech.eu@epitech.eu>
**
** Started on  Mon Jan 30 17:22:20 2017 Raphael Legrand
** Last update Wed Feb  1 13:44:54 2017 Raphael Legrand
*/

#include "my.h"

void			sighandler(int signum)
{
  write(1, "le serveur ma répondu\n", 23);
}

int			main(int ac, char **av)
{
  int		pid = my_getnbr(av[1]);
  int		lettre = av[2][0] + 48;
  int		i = 0;

  while (i != lettre)
    {
      kill(pid, 10);
      usleep(1);
      i++;
    }
  kill(pid, 12);
  //signal(SIGUSR2, sighandler);
  while (1)
    sleep(10);
  return (1);
}
