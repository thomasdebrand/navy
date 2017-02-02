/*
** player2.c for player2 in /home/raphael/PSU_2016_navy/
**
** Made by Raphael Legrand
** Login   <raphael.legrand@epitech.eu@epitech.eu>
**
** Started on  Wed Feb  1 14:15:59 2017 Raphael Legrand
** Last update Thu Feb  2 16:55:10 2017 Raphael Legrand
*/

#include "my.h"

void		player2(char *ppid, char *file)
{
  char 	*s;
  int		pid = my_getnbr(ppid);
  while ((s = get_next_line(0)))
    {
      if (s[2] != 0)
	return ;
      send(pid, file, s);
      free(s);
  }
}

void		send(int pid, char *file, char *s)
{
  int		lettre;
  int		i = 0;
  int		n = 0;

  while (s[n] != '\0')
    {
      if (s[n] > 64 && s[n] < 73)
	lettre = s[n] - 64;
      if (s[n] > 48 && s[n] < 57)
	lettre = s[n] - 48;
      while (i != lettre)
	{
	  kill(pid, 10);
	  usleep(5);
	  i++;
	}
      my_put_nbr(i);
      kill(pid, 12);
      i = 0;
      n++;
    }
}
