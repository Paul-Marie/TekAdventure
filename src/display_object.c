/*
** display_object.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure/src
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Sun May 28 14:26:51 2017 BETTINELLI Paul-Marie
** Last update SUn May 28 14:54:52 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

void	disp_alien(t_window *window)
{
  if (window->alien->pos.x == 0 && window->alien->pos.y == 0)
    {
      window->alien->pos.x = SCREEN_WIDTH;
      window->alien->pos.y = - 50;
    }
  if (window->alien->pos.x > 0 || window->alien->pos.y > 0)
    {
      window->alien->pos.x = window->alien->pos.x - 0.5;
      window->alien->pos.y = window->alien->pos.y + 0.1;
    }
  if (window->alien->pos.x == -50 || window->alien->pos.y == SCREEN_HEIGHT)
    {
      window->alien->pos.x = -100;
      window->alien->pos.y = -100;
    }
  sfSprite_setPosition(window->alien->sprite, window->alien->pos);
  sfRenderWindow_drawSprite(window->window, window->alien->sprite, NULL);
}

void		init_alien(t_window *window)
{
  sfTexture	*texture;
  sfSprite	*sprite;

  window->alien = malloc(sizeof(t_object));
  window->alien->pos.x = -100;
  window->alien->pos.y = -100;
  texture = sfTexture_createFromFile("ressource/image/Metroid2.png", NULL);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfSprite_setPosition(sprite, window->alien->pos);
  window->alien->texture = texture;
  window->alien->sprite = sprite;
}

void	disp_asteroid(t_window *window)
{
  if (window->aster->pos.x == 0 && window->aster->pos.y == 0)
    {
      window->aster->pos.x = SCREEN_WIDTH;
      window->aster->pos.y = - 50;
    }
  if (window->aster->pos.x > 0 || window->aster->pos.y > 0)
    {
      window->aster->pos.x = window->aster->pos.x - 0.5;
      window->aster->pos.y = window->aster->pos.y + 0.1;
    }
  if (window->aster->pos.x == -50 || window->aster->pos.y == SCREEN_HEIGHT)
    {
      window->aster->pos.x = -100;
      window->aster->pos.y = -100;
    }
  sfSprite_setPosition(window->aster->sprite, window->aster->pos);
  sfRenderWindow_drawSprite(window->window, window->aster->sprite, NULL);
}

void		init_asteroid(t_window *window)
{
  sfTexture	*texture;
  sfSprite	*sprite;

  window->aster = malloc(sizeof(t_object));
  window->aster->pos.x = -100;
  window->aster->pos.y = -100;
  texture = sfTexture_createFromFile("ressource/image/Asteroid.png", NULL);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfSprite_setPosition(sprite, window->aster->pos);
  window->aster->texture = texture;
  window->aster->sprite = sprite;
}
