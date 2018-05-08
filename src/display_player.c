/*
** display_player.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure/src
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Sun May 21 14:19:43 2017 BETTINELLI Paul-Marie
** Last update Sat May 27 13:21:35 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

int		disp_player(t_window *window, t_player *player)
{
  static int	i;
  static int	d;

  if (d++ % 5 == 0)
    player->texture = player->frame->idle[i++ % 10];
  sfSprite_setPosition(player->sprite, player->pos);
  sfSprite_setTexture(player->sprite, player->texture, sfTrue);
  if (player->map.aerospace.robot.charge != 1 &&
      player->map.aerospace.robot.charge_shield != 1
      && player->map.aerospace.robot.repair != 1)
    sfRenderWindow_drawSprite(window->window, player->sprite, NULL);
  else
    sfMusic_play(window->charge);
  return (0);
}
