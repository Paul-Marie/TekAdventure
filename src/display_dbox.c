/*
** display_dbox.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure/src
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Sun May 28 14:33:25 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 23:29:30 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

int			disp_ladder_dbox(t_window *window)
{
  sfRectangleShape	*rectangle;
  sfColor		color;
  sfVector2f		pos;
  sfVector2f		size;
  sfText		*text;
  sfFont		*font;

  color = sfBlack;
  color.a = 200;
  pos.x = 400;
  pos.y = 570;
  size.x = 300;
  size.y = 75;
  rectangle = sfRectangleShape_create();
  sfRectangleShape_setFillColor(rectangle, color);
  sfRectangleShape_setSize(rectangle, size);
  sfRectangleShape_setPosition(rectangle, pos);
  sfRenderWindow_drawRectangleShape(window->window, rectangle, NULL);
  text = sfText_create();
  sfText_setPosition(text, pos);
  font = sfFont_createFromFile("ressource/nasalization-rg.ttf");
  sfText_setFont(text, font);
  sfText_setString(text, "Reparer\nanuller");
  sfRenderWindow_drawText(window->window, text, NULL);
  return (0);
}

int			disp_computeur_dbox(t_window *window)
{
  sfRectangleShape	*rectangle;
  sfColor		color;
  sfVector2f		pos;
  sfVector2f		size;
  sfText		*text;
  sfFont		*font;

  color = sfBlack;
  color.a = 200;
  pos.x = 150;
  pos.y = 800;
  size.x = 350;
  size.y = 115;
  rectangle = sfRectangleShape_create();
  sfRectangleShape_setFillColor(rectangle, color);
  sfRectangleShape_setSize(rectangle, size);
  sfRectangleShape_setPosition(rectangle, pos);
  sfRenderWindow_drawRectangleShape(window->window, rectangle, NULL);
  text = sfText_create();
  sfText_setPosition(text, pos);
  font = sfFont_createFromFile("ressource/nasalization-rg.ttf");
  sfText_setFont(text, font);
  sfText_setString(text, "Activer le bouclier\nActiver les cannons\nAnuller");
  sfRenderWindow_drawText(window->window, text, NULL);
  return (0);
}

int			disp_prise_dbox(t_window *window)
{
  sfRectangleShape	*rectangle;
  sfColor		color;
  sfVector2f		pos;
  sfVector2f		size;
  sfText		*text;
  sfFont		*font;

  color = sfBlack;
  color.a = 200;
  pos.x = 1500;
  pos.y = 500;
  size.x = 370;
  size.y = 115;
  rectangle = sfRectangleShape_create();
  sfRectangleShape_setFillColor(rectangle, color);
  sfRectangleShape_setSize(rectangle, size);
  sfRectangleShape_setPosition(rectangle, pos);
  sfRenderWindow_drawRectangleShape(window->window, rectangle, NULL);
  text = sfText_create();
  sfText_setPosition(text, pos);
  font = sfFont_createFromFile("ressource/nasalization-rg.ttf");
  sfText_setFont(text, font);
  sfText_setString(text, "Se recharger\nRecharger le Bouclier\nAnuller");
  sfRenderWindow_drawText(window->window, text, NULL);
  return (0);
}

int			disp_commandpost_dbox(t_window *window)
{
  sfRectangleShape	*rectangle;
  sfColor		color;
  sfVector2f		pos;
  sfVector2f		size;
  sfText		*text;
  sfFont		*font;

  color = sfBlack;
  color.a = 200;
  pos.x = 1550;
  pos.y = 850;
  size.x = 300;
  size.y = 75;
  rectangle = sfRectangleShape_create();
  sfRectangleShape_setFillColor(rectangle, color);
  sfRectangleShape_setSize(rectangle, size);
  sfRectangleShape_setPosition(rectangle, pos);
  sfRenderWindow_drawRectangleShape(window->window, rectangle, NULL);
  text = sfText_create();
  sfText_setPosition(text, pos);
  font = sfFont_createFromFile("ressource/nasalization-rg.ttf");
  sfText_setFont(text, font);
  sfText_setString(text, "Piloter\nAnuller");
  sfRenderWindow_drawText(window->window, text, NULL);
  return (0);
}

int	disp_dbox(t_window *window)
{
  if (window->dbox->numero == 1 && window->dbox->active == 1)
    disp_prise_dbox(window);
  if (window->dbox->numero == 2  && window->dbox->active == 1)
    disp_commandpost_dbox(window);
  if (window->dbox->numero == 3 && window->dbox->active == 1)
    disp_computeur_dbox(window);
  if (window->dbox->numero == 4 && window->dbox->active == 1)
    disp_ladder_dbox(window);
  return (0);
}
