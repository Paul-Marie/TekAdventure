/*
** goto.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Sat May 27 14:27:25 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 10:08:15 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

t_dbox	*reset_dbox(t_dbox *dbox)
{
  dbox->active = 0;
  dbox->numero = 0;
  return (dbox);
}

t_dbox	*add_dbox(t_dbox *dbox, int numero)
{
  dbox->active = 1;
  dbox->numero = numero;
  return (dbox);
}
