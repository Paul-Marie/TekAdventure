/*
** display_shipbar.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure/src
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue May 23 14:33:47 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 14:34:03 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

void			bar_ship(t_window *window, float lifepoint,
				     sfVector2f position, sfColor color)
{
  sfRectangleShape	*rectangle;
  sfRectangleShape	*boarder;
  sfVector2f		size_boarder;
  sfVector2f		pos_boarder;
  sfVector2f		size;
  sfVector2f		pos;

  size.x = 1120 * lifepoint;
  size.y = 24;
  size_boarder.x = 1130;
  size_boarder.y = 34;
  pos.x = position.x;
  pos.y = position.y;
  pos_boarder.x = position.x - 5;
  pos_boarder.y = position.y - 5;
  rectangle = sfRectangleShape_create();
  boarder = sfRectangleShape_create();
  sfRectangleShape_setFillColor(rectangle, color);
  sfRectangleShape_setFillColor(boarder, sfBlack);
  sfRectangleShape_setSize(rectangle, size);
  sfRectangleShape_setSize(boarder, size_boarder);
  sfRectangleShape_setPosition(rectangle, pos);
  sfRectangleShape_setPosition(boarder, pos_boarder);
  sfRenderWindow_drawRectangleShape(window->window, boarder, NULL);
  sfRenderWindow_drawRectangleShape(window->window, rectangle, NULL);
}

int		disp_shipbar(t_window *window, t_player *player)
{
  sfVector2f	ship;

  ship.x = 400;
  ship.y = 1054;
  bar_ship(window, 1, ship, sfBlack);
  bar_ship(window, player->map.aerospace.life / 200, ship, sfGreen);
  return (0);
}

