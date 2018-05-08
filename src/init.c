/*
** init.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue May 23 08:56:21 2017 BETTINELLI Paul-Marie
** Last update Sat May 27 12:29:27 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

t_node		*init_node()
{
  t_node	*node;

  if ((node = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  node->pos1.x = 1430;
  node->pos2.x = 1486;
  node->pos3.x = 200;
  node->pos4.x = 420;
  node->middle.x = 860;
  node->pos1.y = 530;
  node->pos2.y = 720;
  node->pos3.y = 720;
  node->pos4.y = 500;
  node->middle.y = 610;
  return (node);
}

t_player	*init_player(t_window *window, t_node *node)
{
  t_player	*player;

  if ((player = malloc(sizeof(t_player))) == NULL ||
      (player->frame = init_texture()) == NULL)
    return (NULL);
  window = window;
  player->move = 0;
  player->life = 1;
  player->armor = 1;
  player->node = node;
  player->scale.x = 0.9;
  player->scale.y = 0.9;
  player->direction.x = 1;
  player->direction.y = 1;
  player->pos = node->middle;
  player->sprite = sfSprite_create();
  player->texture = player->frame->idle[0];
  player->map = fill_map();
  sfSprite_setTexture(player->sprite, player->texture, sfTrue);
  sfSprite_setPosition(player->sprite, player->pos);
  return (player);
}

t_rocket	*init_rocket(t_window *window)
{
  t_rocket	*rocket;

  if ((rocket = malloc(sizeof(t_rocket))) == NULL)
    return (NULL);
  rocket->pos.x = 80;
  rocket->pos.y = 20;
  window = window;
  rocket->texture =
    sfTexture_createFromFile("ressource/image/rocket.png", NULL);
  rocket->sprite = sfSprite_create();
  sfSprite_setTexture(rocket->sprite, rocket->texture, sfTrue);
  sfSprite_setPosition(rocket->sprite, rocket->pos);
  return (rocket);
}

t_menu		*init_menu(t_window *window)
{
  t_menu	*menu;

  if ((menu = malloc(sizeof(t_menu))) == NULL)
    return (NULL);
  if ((menu->life = init_life(window)) == NULL
      || (menu->rocket = init_rocket(window)) == NULL
      || (menu->shield = init_shield(window)) == NULL)
    return (NULL);
  return (menu);
}

t_move		*init_move(sfVector2f from, sfVector2f to)
{
  t_move	*move;

  if ((move = malloc(sizeof(t_move))) == NULL)
    return (NULL);
  move->x = from.x;
  move->y = from.y;
  move->dx = from.x - to.x;
  move->dy = from.y - to.y;
  move->i = fmax(fabs(move->dx), fabs(move->dy));
  move->dx = move->dx / move->i;
  move->dy = move->dy / move->i;
  move->incr1 = to.x;
  move->incr2 = to.y;
  return (move);
}
