/*
** my_putchar.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure/src
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Sun May 21 08:34:40 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 12:34:41 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

t_dbox	*is_clicked(t_window *window, t_player *player)
{
  if (window->pos.x >= 1500 && window->pos.y < 800
      && window->pos.y > 300 && player->move == 0 &&
      window->dbox->active == 0)
    window->dbox = add_dbox(window->dbox, 1);
  else if (window->pos.x > 1520 && window->pos.y >= 750
	   && player->move == 0 && window->dbox->active == 0)
    window->dbox = add_dbox(window->dbox, 2);
  else if (window->pos.x < 775 && window->pos.y >= 800
	   && player->move == 0 && window->dbox->active == 0)
    window->dbox = add_dbox(window->dbox, 3);
  else if (window->pos.x < 800 && window->pos.y < 700
	   && window->pos.y > 500 && player->move == 0 &&
	   window->dbox->active == 0)
    window->dbox = add_dbox(window->dbox, 4);
  return (window->dbox);
}

int	comput_coord(t_window *window, t_player *player)
{
  if (window->pos.x >= 150 && window->pos.x <= 600 &&
      window->pos.y > 875 && window->pos.y <= 915 &&
      window->dbox->active == 1 && window->dbox->numero == 3
      && player->move == 0)
    return (0);
  if (window->pos.x >= 400 && window->pos.x <= 700
      && window->pos.y >= 570 && window->pos.y <= 607 &&
      window->dbox->active == 1 && window->dbox->numero == 4
      && player->move == 0)
    return (10);
  if (window->pos.x >= 400 && window->pos.x <= 700 &&
      window->pos.y > 537 && window->pos.y <= 575 &&
      window->dbox->active == 1 && window->dbox->numero == 4
      && player->move == 0)
    return (0);
  return (0);
}

int	find_coord(t_window *window, t_player *player)
{
  if (window->pos.x >= 1500 && window->pos.x <= 1800 &&
      window->pos.y >= 850 && window->pos.y < 887 &&
      player->move == 0 && window->dbox->active == 1 &&
      window->dbox->numero == 2)
    return (7);
  if (window->pos.x >= 1500 && window->pos.x <= 1800 &&
      window->pos.y >= 887 && window->pos.y <= 925 &&
      player->move == 0 && window->dbox->active == 1 &&
      window->dbox->numero == 2)
    return (0);
  if (window->pos.x >= 300 && window->pos.x <= 600
      && window->pos.y >= 800 && window->pos.y <= 837 &&
      window->dbox->active == 1 && window->dbox->numero == 3
      && player->move == 0)
    return (8);
  if (window->pos.x >= 300 && window->pos.x <= 600 &&
      window->pos.y > 837 && window->pos.y <= 875 &&
      window->dbox->active == 1 && window->dbox->numero == 3
      && player->move == 0)
    return (9);
  return (comput_coord(window, player));
}

int	wich_pos(t_window *window, t_player *player)
{
  if (window->pos.x >= 1500 && window->pos.x <= 1870 &&
      window->pos.y >= 500 && window->pos.y < 537 &&
      player->move == 0 && window->dbox->active == 1 &&
      window->dbox->numero == 1)
    return (5);
  if (window->pos.x >= 1500 && window->pos.x <= 1870 &&
      window->pos.y >= 537 && window->pos.y <= 575 &&
      player->move == 0 && window->dbox->active == 1 &&
      window->dbox->numero == 1)
    return (6);
  if (window->pos.x >= 1500 && window->pos.x <= 1870 &&
      window->pos.y > 575 && window->pos.y <= 615 &&
      player->move == 0 && window->dbox->active == 1 &&
      window->dbox->numero == 1)
    return (0);
  return (find_coord(window, player));
}
