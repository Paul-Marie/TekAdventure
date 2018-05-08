/*
** menu_init.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Fri May 26 19:57:09 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 12:23:49 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

t_rocket	*init_shield(t_window *window)
{
  t_rocket	*rocket;

  if ((rocket = malloc(sizeof(t_rocket))) == NULL)
    return (NULL);
  rocket->pos.x = 150;
  rocket->pos.y = 105;
  window = window;
  rocket->texture =
    sfTexture_createFromFile("ressource/image/shield.png", NULL);
  rocket->sprite = sfSprite_create();
  sfSprite_setTexture(rocket->sprite, rocket->texture, sfTrue);
  sfSprite_setPosition(rocket->sprite, rocket->pos);
  return (rocket);
}

t_rocket	*init_life(t_window *window)
{
  t_rocket	*rocket;

  if ((rocket = malloc(sizeof(t_rocket))) == NULL)
    return (NULL);
  rocket->pos.x = 1030;
  rocket->pos.y = 85;
  window = window;
  rocket->texture =
    sfTexture_createFromFile("ressource/image/energy.png", NULL);
  rocket->sprite = sfSprite_create();
  sfSprite_setTexture(rocket->sprite, rocket->texture, sfTrue);
  sfSprite_setPosition(rocket->sprite, rocket->pos);
  return (rocket);
}

t_dbox		*init_dbox()
{
  t_dbox	*dbox;

  if ((dbox = malloc(sizeof(t_dbox))) == NULL)
    return (NULL);
  dbox->active = 0;
  dbox->numero = 0;
  return (dbox);
}
