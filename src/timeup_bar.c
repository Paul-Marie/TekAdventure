/*
** timeup_bar.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Sat May 27 13:37:34 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 14:51:53 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

int			disp_endtime(t_window *window, float x)
{
  sfRectangleShape	*rectangle;
  sfColor		color;
  sfVector2f		size;
  sfVector2f		pos;

  size.x = x;
  size.y = 10;
  pos.x = 100;
  pos.y = 40;
  color.r = 255;
  color.g = 100;
  color.b = 0;
  color.a = 255;
  rectangle = sfRectangleShape_create();
  sfRectangleShape_setFillColor(rectangle, color);
  sfRectangleShape_setSize(rectangle, size);
  sfRectangleShape_setPosition(rectangle, pos);
  sfRenderWindow_drawRectangleShape(window->window, rectangle, NULL);
  return (0);
}
