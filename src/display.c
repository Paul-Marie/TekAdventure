/*
** display.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure/src
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Sun May 28 14:35:01 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 14:35:01 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

int	disp_end(t_window *window, t_player *player, t_menu *menu)
{
  sfMusic_destroy(window->background);
  sfMusic_destroy(window->step);
  sfMusic_destroy(window->charge);
  sfSprite_destroy(window->scene->bg->sprite);
  sfSprite_destroy(window->aster->sprite);
  sfSprite_destroy(window->alien->sprite);
  sfSprite_destroy(window->whole->room->sprite);
  sfSprite_destroy(window->whole->prise->sprite);
  sfSprite_destroy(window->whole->ladder->sprite);
  sfSprite_destroy(window->whole->computeur->sprite);
  sfSprite_destroy(window->whole->commandpost->sprite);
  sfSprite_destroy(window->whole->chargingprise->sprite);
  sfSprite_destroy(player->sprite);
  sfSprite_destroy(menu->rocket->sprite);
  sfSprite_destroy(menu->shield->sprite);
  sfSprite_destroy(menu->life->sprite);
  sfRenderWindow_close(window->window);
  sfRenderWindow_destroy(window->window);
  return (0);
}

int		disp_loop(t_window *window,
			  t_player *player, t_menu *menu)
{
  while (sfRenderWindow_isOpen(window->window))
    {
      player->map = add_event(player->map);
      player = check_event(player);
      sfRenderWindow_clear(window->window, sfBlack);
      player = event_handler(window, player, menu);
      window->map.event = player->map.event;
      disp_scene(window);
      disp_room(window, player);
      disp_bar(window, menu, player);
      disp_player(window, player);
      disp_dbox(window);
      sfRenderWindow_display(window->window);
      if (player->map.aerospace.robot.energie < 0
	  || player->map.aerospace.life < 0)
	return (0);
    }
  return (0);
}

int	init_window(t_window *window)
{
  window->window = sfRenderWindow_create(setVideoMode(),
					 "Insert Name Here",
					 sfFullscreen,
					 NULL);
  init_scene(window);
  window->background = sfMusic_createFromFile("ressource/music/hero.ogg");
  sfMusic_setVolume(window->background, 30);
  sfMusic_play(window->background);
  window->step = sfMusic_createFromFile("ressource/music/footstep.ogg");
  sfMusic_setPitch(window->step, 1.8);
  sfMusic_setLoop(window->step, sfTrue);
  window->charge = sfMusic_createFromFile("ressource/music/charge.ogg");
  sfMusic_setPitch(window->charge, 4);
  sfRenderWindow_setVerticalSyncEnabled(window->window, sfTrue);
  return (0);
}

int	disp_window()
{
  t_player	*player;
  t_window	*window;
  t_node	*node;
  t_menu	*menu;

  if ((window = malloc(sizeof(t_window))) == NULL)
    return (0);
  if (window == NULL)
    return (0);
  init_window(window);
  if ((node = init_node()) == NULL ||
      (player = init_player(window, node)) == NULL
      || (menu = init_menu(window)) == NULL)
    return (0);
  disp_loop(window, player, menu);
  disp_end(window, player, menu);
  return (1);
}
