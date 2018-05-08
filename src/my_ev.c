/*
** my_ev.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure/src
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Sun May 28 14:32:21 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 14:32:22 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

t_map	asteroide(t_map map)
{
  float	dmg;

  dmg = 0.07;
  if (map.aerospace.robot.pilote == 1)
    dmg = 0.01;
  map.aerospace.shield_charge -= dmg;
  if (map.aerospace.shield_charge < 0.01)
    {
      map.aerospace.life -= dmg;
      map.aerospace.shield_charge = 0;
    }
  map.aerospace.speed = 0.01;
  map.avancment += map.aerospace.speed;
  return (map);
}

t_map	alien(t_map map)
{
  if (map.aerospace.canons == 0)
    {
      map.aerospace.shield_charge -= 0.15;
      if (map.aerospace.shield_charge < 0.01)
	{
	  map.aerospace.life -= 0.15;
	  map.aerospace.shield_charge = 0;
	}
    }
  else
    {
      map.event = 2;
      map.aerospace.canons = 0;
    }
  map.avancment += map.aerospace.speed;
  return (map);
}

t_map	nothing(t_map map)
{
  map.aerospace.speed = 0.02;
  map.avancment += map.aerospace.speed;
  return (map);
}
