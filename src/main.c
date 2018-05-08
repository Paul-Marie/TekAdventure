/*
** main.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure/src
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Sun May 28 14:34:49 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 14:34:50 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

int		main()
{
  if (!disp_window())
    return (print_err("Error: Window coulnd't be created.\n"));
  my_putstr("Thanks for playing !\n");
  return (0);
}
