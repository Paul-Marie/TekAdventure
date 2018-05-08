/*
** event.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure/src
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Sun May 28 14:32:28 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 23:29:59 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

t_player	*sub_event(t_window *window,
			   t_player *player, t_menu *menu)
{
  if (wich_pos(window, player) == 8)
    {
      player = player_move(window, player, player->node->pos3, menu);
      window->dbox->numero = 0;
    }
  if (wich_pos(window, player) == 9)
    {
      player = player_move(window, player, player->node->pos3, menu);
      window->dbox->numero = 0;
      player->map.aerospace.canons = 1;
    }
  if (wich_pos(window, player) == 10)
    {
      player = player_move(window, player, player->node->pos4, menu);
      player->map.aerospace.robot.repair = 1;
      window->dbox->numero = 0;
    }
  is_clicked(window, player);
  if (wich_pos(window, player) == 0)
    window->dbox = reset_dbox(window->dbox);
  return (player);
}

t_player	*event_click(t_window *window,
			     t_player *player, t_menu *menu)
{
  if (wich_pos(window, player) == 5)
    {
      player = player_move(window, player, player->node->pos1, menu);
      player->map.aerospace.robot.charge = 1;
      window->dbox->numero = 0;
    }
  if (wich_pos(window, player) == 6)
    {
      player = player_move(window, player, player->node->pos1, menu);
      player->map.aerospace.robot.charge_shield = 1;
      window->dbox->numero = 0;
    }
  if (wich_pos(window, player) == 7)
    {
      player = player_move(window, player, player->node->pos2, menu);
      player->map.aerospace.robot.pilote = 1;
      window->dbox->numero = 0;
    }
  return (sub_event(window, player, menu));
}

t_player	*event_handler(t_window *w, t_player *player, t_menu *menu)
{
  sfEvent	event;

  while (sfRenderWindow_pollEvent(w->window, &event))
    {
      if (event.type == sfEvtKeyReleased)
	if (event.key.code == sfKeyEscape)
	  sfRenderWindow_close(w->window);
      if (event.type == sfEvtMouseButtonReleased)
	{
	  player->map.aerospace.robot.charge = 0;
	  player->map.aerospace.robot.charge_shield = 0;
	  player->map.aerospace.robot.repair = 0;
	  w->pos.x = event.mouseButton.x;
	  w->pos.y = event.mouseButton.y;
	  player = event_click(w, player, menu);
	}
    }
  return (player);
}
