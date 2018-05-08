/*
** display_alien.c for tekadventure in /home/linet.vincent/CGraphicalProgramming/tekadventure
** 
** Made by LINET Vincent
** Login   <linet.vincent@epitech.net>
** 
** Started on  Sun May 28 14:46:33 2017 LINET Vincent
** Last update Sun May 28 15:49:46 2017 Paul Juyaux
*/

#include "window.h"

void    disp_alien(t_window *window)
{
  if (window->alien->pos.x < -450 && window->map.event == 1)
    {
      window->alien->pos.x = 0;
      window->alien->pos.y = 0;
    }
  if (window->alien->pos.x == 0 && window->alien->pos.y == 0)
    {
      window->alien->pos.x = SCREEN_WIDTH;
      window->alien->pos.y = 0;
    }
  if (window->alien->pos.x > -500 || window->alien->pos.y < SCREEN_HEIGHT)
    {
      window->alien->pos.x = window->alien->pos.x - 5;
      window->alien->pos.y = window->alien->pos.y + 1;
    }
  sfSprite_setPosition(window->alien->sprite, window->alien->pos);
  sfRenderWindow_drawSprite(window->window, window->alien->sprite, NULL);
}

void            init_alien(t_window *window)
{
  sfTexture     *texture;
  sfSprite      *sprite;

  window->alien = malloc(sizeof(t_object));
  window->alien->pos.x = -500;
  window->alien->pos.y = SCREEN_HEIGHT;
  texture = sfTexture_createFromFile("ressource/image/Metroid7.png", NULL);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfSprite_setPosition(sprite, window->alien->pos);
  window->alien->texture = texture;
  window->alien->sprite = sprite;
}
