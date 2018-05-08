/*
** whole_init.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure/src
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Sun May 28 14:32:11 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 14:32:12 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

t_element	*init_prise()
{
  t_element	*prise;

  prise = malloc(sizeof(t_element));
  prise->pos.x = 1400;
  prise->pos.y = 200;
  prise->sprite = sfSprite_create();
  prise->texture =
    sfTexture_createFromFile("ressource/image/ChargeOpen.png", NULL);
  sfSprite_setTexture(prise->sprite, prise->texture, sfTrue);
  sfSprite_setPosition(prise->sprite, prise->pos);
  return (prise);
}

t_element	*init_commandpost()
{
  t_element	*commandpost;

  commandpost = malloc(sizeof(t_element));
  commandpost->pos.x = 1500;
  commandpost->pos.y = 750;
  commandpost->sprite = sfSprite_create();
  commandpost->texture =
    sfTexture_createFromFile("ressource/image/Commandpost.png", NULL);
  sfSprite_setTexture(commandpost->sprite, commandpost->texture, sfTrue);
  sfSprite_setPosition(commandpost->sprite, commandpost->pos);
  return (commandpost);
}

t_element	*init_computeur()
{
  t_element	*computeur;

  computeur = malloc(sizeof(t_element));
  computeur->pos.x = 150;
  computeur->pos.y = 750;
  computeur->sprite = sfSprite_create();
  computeur->texture =
    sfTexture_createFromFile("ressource/image/Computer.png", NULL);
  sfSprite_setTexture(computeur->sprite, computeur->texture, sfTrue);
  sfSprite_setPosition(computeur->sprite, computeur->pos);
  return (computeur);
}

t_element	*init_ladder()
{
  t_element	*ladder;

  ladder = malloc(sizeof(t_element));
  ladder->pos.x = 300;
  ladder->pos.y = 500;
  ladder->sprite = sfSprite_create();
  ladder->texture =
    sfTexture_createFromFile("ressource/image/Ladder.png", NULL);
  sfSprite_setTexture(ladder->sprite, ladder->texture, sfTrue);
  sfSprite_setPosition(ladder->sprite, ladder->pos);
  return (ladder);
}

t_whole		*init_whole()
{
  t_whole	*whole;

  if ((whole = malloc(sizeof(t_whole))) == NULL ||
      (whole->commandpost = init_commandpost()) == NULL ||
      (whole->room = init_room()) == NULL ||
      (whole->prise = init_prise()) == NULL ||
      (whole->ladder = init_ladder()) == NULL ||
      (whole->computeur = init_computeur()) == NULL ||
      (whole->chargingprise = init_chargingprise()) == NULL)
    return (NULL);
  return (whole);
}
