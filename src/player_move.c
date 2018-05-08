/*
** player_move.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue May 23 11:36:54 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 23:29:54 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

t_player	*player_scale(t_player *player, t_move *move, t_window *wind)
{
  sfRenderWindow_display(wind->window);
  if (move->y >= move->incr2)
    {
      player->scale.y = player->scale.y - (player->pos.y / 600000);
      player->scale.x = player->scale.x - (player->pos.y / 600000);
    }
  else
    {
      player->scale.y = player->scale.y + (player->pos.y / 600000);
      player->scale.x = player->scale.x + (player->pos.y / 600000);
    }
  player->map.aerospace.robot.energie -= 0.02;
  player->pos.x = move->x;
  player->pos.y = move->y;
  return (player);
}

t_player	*positive_move(t_window *w, t_player *player,
			       t_move *move, t_menu *menu)
{
  int		i[2];

  i[0] = (i[1] = 0);
  sfMusic_play(w->step);
  while (move->x != move->incr1 && move->y != move->incr2)
    {
      player = event_handler(w, player, menu);
      sfRenderWindow_clear(w->window, sfBlack);
      disp_scene(w);
      disp_moving_room(w, player, move);
      disp_bar(w, menu, player);
      if (i[1]++ % 5 == 0)
	(move->x > move->incr1) ?
	  (player->texture = player->frame->runinv[i[0]++ % 8]) :
	  (player->texture = player->frame->run[i[0]++ % 8]);
      sfSprite_setTexture(player->sprite, player->texture, sfTrue);
      sfSprite_setScale(player->sprite, player->scale);
      sfSprite_setPosition(player->sprite, player->pos);
      sfRenderWindow_drawSprite(w->window, player->sprite, NULL);
      move->x = move->x - move->dx * 2;
      move->y = move->y - move->dy * 2;
      player = player_scale(player, move, w);
    }
  sfMusic_stop(w->step);
  return (player);
}

t_player	*player_move(t_window *window, t_player *player,
			     sfVector2f pos, t_menu *menu)
{
  t_move	*move;

  player->move = 1;
  move = init_move(player->pos, player->node->middle);
  player = positive_move(window, player, move, menu);
  move = init_move(player->pos, pos);
  player = positive_move(window, player, move, menu);
  player->move = 0;
  player->texture = player->frame->idle[0];
  sfSprite_setTexture(player->sprite, player->texture, sfTrue);
  sfRenderWindow_drawSprite(window->window, player->sprite, NULL);
  return (player);
}
