/*
** check_event.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Sun May 28 19:41:36 2017 BETTINELLI Paul-Marie
** Last update Tue May 28 19:48:03 2017 Paul Juyaux
*/

#include "window.h"

t_player	*check_event(t_player *player)
{
  if (player->map.event == 0)
    player->map = asteroide(player->map);
  if (player->map.event == 1)
    player->map = alien(player->map);
  if (player->map.event == 2)
    player->map = nothing(player->map);
  if (player->map.aerospace.robot.charge == 1)
    player->map = charge(player->map);
  if (player->map.aerospace.robot.pilote == 1)
    player->map = pilot(player->map);
  if (player->map.aerospace.robot.charge_shield == 1)
    player->map = charge_shield(player->map);
  if (player->map.aerospace.robot.repair == 1)
    player->map = repair(player->map);
  return (player);
}
