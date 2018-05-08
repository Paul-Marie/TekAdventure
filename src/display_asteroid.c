/*
** display_asteroid.c for tekadventure in /home/linet.vincent/CGraphicalProgramming/tekadventure
** 
** Made by LINET Vincent
** Login   <linet.vincent@epitech.net>
** 
** Started on  Sun May 28 22:10:56 2017 LINET Vincent
** Last update Sun May 28 15:50:11 2017 Paul Juyaux
*/

#include "window.h"

void	disp_asteroid(t_window *window)
{
  if (window->aster->pos.x < -450 && window->map.event == 0)
    {
      window->aster->pos.x = 0;
      window->aster->pos.y = 0;
    }
  if (window->aster->pos.x == 0 && window->aster->pos.y == 0)
    {
      window->aster->pos.x = SCREEN_WIDTH;
      window->aster->pos.y = 50;
    }
  if (window->aster->pos.x > -500 || window->aster->pos.y < SCREEN_HEIGHT)
    {
      window->aster->pos.x = window->aster->pos.x - 3;
      window->aster->pos.y = window->aster->pos.y + 0;
    }
  sfSprite_setPosition(window->aster->sprite, window->aster->pos);
  sfRenderWindow_drawSprite(window->window, window->aster->sprite, NULL);
}

void		init_asteroid(t_window *window)
{
  sfTexture	*texture;
  sfSprite	*sprite;

  window->aster = malloc(sizeof(t_object));
  window->aster->pos.x = -500;
  window->aster->pos.y = SCREEN_HEIGHT;
  texture = sfTexture_createFromFile("ressource/image/Asteroid2.png", NULL);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfSprite_setPosition(sprite, window->aster->pos);
  window->aster->texture = texture;
  window->aster->sprite = sprite;
}
