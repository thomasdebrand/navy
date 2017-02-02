/*
** signal.c for signal in /home/raphael/Mini_Shell/
**
** Made by Raphael Legrand
** Login   <raphael.legrand@epitech.eu@epitech.eu>
**
** Started on  Mon Jan  9 16:37:24 2017 Raphael Legrand
** Last update Tue Jan 31 13:15:32 2017 Raphael Legrand
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sighandler(int);
void test(int);

int main()
{
  signal(SIGINT, test);
  signal(SIGUSR1, sighandler);
  pid_t	pid;
  pid = getpid();
   while (1)
   {
      sleep(2);
   }
   return (0);
}

void sighandler(int signum)
{
  my_putstr("Signal reçu lel\n");
}

void	test(int signum)
{
  pid_t pid;
  pid = getpid();
  kill(pid, SIGQUIT);
}
