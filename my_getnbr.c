/*
** my_getnbr.c for my_getnbr in /home/raphael/BSQ/
**
** Made by Raphael Legrand
** Login   <raphael.legrand@epitech.eu@epitech.eu>
**
** Started on  Sat Dec 17 15:54:44 2016 Raphael Legrand
** Last update Sat Dec 17 15:55:59 2016 Raphael Legrand
*/

int		my_getnbr(char *str)
{
  int	i;
  int	z = 0;

  i = 0;
  while (str[i] != '\0')
    {
      z = z * 10 + str[i] - 48;
      i++;
    }
  return (z);
}
