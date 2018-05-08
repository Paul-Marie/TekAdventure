/*
** my_putstr.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Sun May 28 14:28:09 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 14:49:10 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

void	my_putstr(char *str)
{
  while (*str)
    write(1, str++, 1);
}

