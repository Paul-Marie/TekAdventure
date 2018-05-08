/*
** scenery.c for tekadventure in /home/linet.vincent/CGraphicalProgramming/tekadventure
** 
** Made by LINET Vincent
** Login   <linet.vincent@epitech.net>
** 
** Started on  Fri Apr 21 13:57:58 2017 LINET Vincent
** Last update Sun May 28 23:29:18 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

void		disp_scene(t_window *window)
{
  t_bgpattern	*bg;

  bg = window->scene->bg;
  while (bg->next != NULL)
    {
      sfSprite_setPosition(bg->sprite, bg->pos);
      sfSprite_setTexture(bg->sprite, bg->texture, sfTrue);
      sfRenderWindow_drawSprite(window->window, bg->sprite, NULL);
      bg->pos.x = bg->pos.x - 1;
      if (bg->pos.x == -400)
	bg->pos.x = SCREEN_WIDTH + 400;
      bg = bg->next;
    }
  sfSprite_setPosition(bg->sprite, bg->pos);
  sfRenderWindow_drawSprite(window->window, bg->sprite, NULL);
  bg->pos.x = bg->pos.x - 1;
  if (bg->pos.x == -400)
    bg->pos.x = SCREEN_WIDTH + 400;
  disp_asteroid(window);
  disp_alien(window);
}

void		init_bg(t_window *window)
{
  t_bgpattern	*bg;
  t_bgpattern	*bgc;
  sfVector2f	pos;

  pos = window->scene->bg->pos;
  bgc = window->scene->bg;
  while (pos.y <= SCREEN_HEIGHT)
    {
      pos.x = window->scene->bg->pos.x;
      while (pos.x <= SCREEN_WIDTH + 800)
	{
	  bgc->pos = pos;
	  pos.x = pos.x + 400;
	  if (pos.x <= SCREEN_WIDTH + 1200)
	    {
	      bg = malloc(sizeof(t_bgpattern));
	      *bg = *bgc;
	      bg->next = bgc;
	    }
	  bgc = bg;
	}
      pos.y = pos.y + 400;
    }
  window->scene->bg = bg;
}

void		init_scene(t_window *window)
{
  sfTexture	*texture;
  sfSprite	*sprite;

  window->scene = malloc(sizeof(t_scene));
  window->scene->bg = malloc(sizeof(t_bgpattern));
  window->whole = init_whole();
  window->dbox = malloc(sizeof(t_dbox));
  window->dbox->active = 0;
  window->dbox->numero = 0;
  window->scene->speed = 0.30;
  window->scene->state = 1;
  window->scene->bg->pos.x = -400;
  window->scene->bg->pos.y = 0;
  texture = sfTexture_createFromFile("ressource/image/sky_b_03.jpg", NULL);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfSprite_setPosition(sprite, window->scene->bg->pos);
  window->scene->bg->texture = texture;
  window->scene->bg->sprite = sprite;
  init_bg(window);
  init_alien(window);
  init_asteroid(window);
}
