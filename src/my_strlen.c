/*
** my_strlen.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue May 28 14:28:42 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 23:29:47 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}
