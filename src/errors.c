/*
** errors.c for tekadventure in /home/linet.vincent/CGraphicalProgramming/tekadventure
** 
** Made by LINET Vincent
** Login   <linet.vincent@epitech.net>
** 
** Started on  Tue Apr 18 15:16:14 2017 LINET Vincent
** Last update Sun May 28 23:29:35 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

int	print_err(char *err)
{
  int	i;

  i = 0;
  while (err[i] != 0)
    i = i + 1;
  write(2, err, i);
  return (84);
}
