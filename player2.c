/*
** player2.c for player2 in /home/raphael/PSU_2016_navy/
**
** Made by Raphael Legrand
** Login   <raphael.legrand@epitech.eu@epitech.eu>
**
** Started on  Wed Feb  1 14:15:59 2017 Raphael Legrand
** Last update Fri Feb 17 15:28:38 2017 Raphael Legrand
*/

#include "my.h"

void		get_posi(int ac)
{
  int		pid;
  char 	*s;

  my_putstr("attack:  ");
  if (ac == 2)
    pid = globale[3];
  if (ac == 3)
    pid = globale[2];
  s = get_next_line(0);
  if (s[2] == 0 && s[0] > 64 && s[0] < 73 && s[1] > 48 && s[1] < 57)
    send(pid, s);
  else
    {
      my_putstr("wrong position\n");
      get_posi(ac);
      return ;
    }
}

void		send(int pid, char *s)
{
  int		lettre;
  int		i = 0;
  int		n = 0;

  signal(12, none);
  while (s[n] != '\0')
    {
      usleep(100);
      if (s[n] > 64 && s[n] < 73)
	lettre = s[n] - 64;
      if (s[n] > 48 && s[n] < 57)
	lettre = s[n] - 48;
      while (i != lettre)
	{
	  kill(pid, 10);
	  pause();
	  i++;
	}
      kill(pid, 12);
      i = 0;
      n++;
    }
  globale[4] = s[0];
  globale[5] = s[1];
  my_putchar('\n');
  my_putstr(s);
}

void			none(int sig)
{
}
