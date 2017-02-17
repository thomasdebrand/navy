/*
** check.c for check in /home/raphael/PSU_2016_navy/test/
**
** Made by Raphael Legrand
** Login   <raphael.legrand@epitech.eu@epitech.eu>
**
** Started on  Sat Feb  4 16:11:43 2017 Raphael Legrand
** Last update Fri Feb 17 11:38:32 2017 Raphael Legrand
*/

#include "my.h"

void				check(char** posi, int *c)
{
  int				pos_l = globale[5] - 49;
  int				pos_c = globale[4] - 65;

  if (posi[pos_l][pos_c] > 48 && posi[pos_l][pos_c] < 57)
    {
      my_putstr("hit\n\n");
      if (globale[2] == 0)
	kill(globale[3], 10);
      if (globale[3] == 0)
	kill(globale[2], 10);
      posi[pos_l][pos_c] = 'x';
      c--;
    }
  else
    {
      my_putstr("missed\n\n");
      if (globale[2] == 0)
	kill(globale[3], 12);
      if (globale[3] == 0)
	kill(globale[2], 12);
      posi[pos_l][pos_c] = 'o';
    }
}

void		miss(int sig)
{
  my_putstr(":  missed\n\n");
  globale[6] = 1;
}

void		hit(int sig)
{
  my_putstr(":  hit\n\n");
  globale[6] = 2;

}

void				answer(char **enemy)
{
  signal(12, miss);
  signal(10, hit);
  pause();
  if (globale[6] == 1)
    enemy[globale[5] - 49][globale[4] - 65] = 'o';
  if (globale[6] == 2)
    enemy[globale[5] - 49][globale[4] - 65] = 'x';
}
