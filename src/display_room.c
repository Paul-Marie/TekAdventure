/*
** display_room.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure/src
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Sun May 28 08:31:07 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 09:37:08 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

t_element	*init_room()
{
  t_element	*room;

  room = malloc(sizeof(t_element));
  room->pos.x = -50;
  room->pos.y = 0;
  room->sprite = sfSprite_create();
  room->texture =
    sfTexture_createFromFile("ressource/image/Scenery.png", NULL);
  sfSprite_setTexture(room->sprite, room->texture, sfTrue);
  sfSprite_setPosition(room->sprite, room->pos);
  return (room);
}

t_element	*init_chargingprise()
{
  t_element	*chargingprise;

  chargingprise = malloc(sizeof(t_element));
  chargingprise->pos.x = 1400;
  chargingprise->pos.y = 200;
  chargingprise->sprite = sfSprite_create();
  chargingprise->texture =
    sfTexture_createFromFile("ressource/image/Charge.png", NULL);
  sfSprite_setTexture(chargingprise->sprite, chargingprise->texture, sfTrue);
  sfSprite_setPosition(chargingprise->sprite, chargingprise->pos);
  return (chargingprise);
}

void	display_element(t_window *window)
{
  sfSprite_setPosition(window->whole->room->sprite,
		       window->whole->room->pos);
  sfSprite_setPosition(window->whole->computeur->sprite,
		       window->whole->computeur->pos);
  sfSprite_setPosition(window->whole->prise->sprite,
		       window->whole->prise->pos);
  sfSprite_setPosition(window->whole->commandpost->sprite,
		       window->whole->commandpost->pos);
  sfSprite_setPosition(window->whole->ladder->sprite,
		       window->whole->ladder->pos);
  sfSprite_setPosition(window->whole->chargingprise->sprite,
		       window->whole->chargingprise->pos);
}

int	disp_moving_room(t_window *window,
			 t_player *player, t_move *move)
{
  if (player->pos.x > move->incr1)
    {
      window->whole->room->pos.x += player->pos.x / 4000;
      window->whole->prise->pos.x += player->pos.x / 4000;
      window->whole->computeur->pos.x += player->pos.x / 4000;
      window->whole->commandpost->pos.x += player->pos.x / 4000;
      window->whole->ladder->pos.x += player->pos.x / 4000;
      window->whole->chargingprise->pos.x += player->pos.x / 4000;
    }
  else
    {
      window->whole->room->pos.x -= player->pos.x / 4000;
      window->whole->prise->pos.x -= player->pos.x / 4000;
      window->whole->computeur->pos.x -= player->pos.x / 4000;
      window->whole->commandpost->pos.x -= player->pos.x / 4000;
      window->whole->ladder->pos.x -= player->pos.x / 4000;
      window->whole->chargingprise->pos.x -= player->pos.x / 4000;
    }
  display_element(window);
  return (disp_room(window, player));
}

int	disp_room(t_window *window, t_player *player)
{
  sfRenderWindow_drawSprite(window->window,
			    window->whole->room->sprite, NULL);
  sfRenderWindow_drawSprite(window->window,
			    window->whole->computeur->sprite, NULL);
  sfRenderWindow_drawSprite(window->window,
			    window->whole->commandpost->sprite, NULL);
  sfRenderWindow_drawSprite(window->window,
			    window->whole->ladder->sprite, NULL);
  if (player->map.aerospace.robot.charge != 1 &&
      player->map.aerospace.robot.charge_shield != 1)
    sfRenderWindow_drawSprite(window->window,
			      window->whole->prise->sprite, NULL);
  else
    sfRenderWindow_drawSprite(window->window,
			      window->whole->chargingprise->sprite, NULL);
  return (0);
}
