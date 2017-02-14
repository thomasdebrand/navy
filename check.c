/*
** check.c for check in /home/raphael/PSU_2016_navy/test/
**
** Made by Raphael Legrand
** Login   <raphael.legrand@epitech.eu@epitech.eu>
**
** Started on  Sat Feb  4 16:11:43 2017 Raphael Legrand
** Last update Sun Feb 12 16:29:43 2017 Raphael Legrand
*/

#include "my.h"

void				check(char** posi)
{
  int				pos_l = globale[5] - 49;
  int				pos_c = globale[4] - 65;

  if (posi[pos_l][pos_c] > 48 && posi[pos_l][pos_c] < 57)
    {
      my_putstr("hit\n");
      if (globale[2] == 0)
	kill(globale[3], 10);
      if (globale[3] == 0)
	kill(globale[2], 10);
      posi[pos_l][pos_c] = 'x';
      //enemy[pos_l + 2][pos_c * 2] = 'x';
    }
  else
    {
      my_putstr("missed\n");
      if (globale[2] == 0)
	kill(globale[3], 12);
      if (globale[3] == 0)
	kill(globale[2], 12);
      posi[pos_l][pos_c] = 'o';
      //enemy[pos_l + 2][pos_c * 2] = 'o';
    }
}

void		miss(int sig)
{
  my_putstr(":  missed\n");
}

void		hit(int sig)
{
  my_putstr(":  hit\n");
}

void				answer()
{
  signal(12, miss);
  signal(10, hit);
  pause();
}
