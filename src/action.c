/*
** action.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure/src
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Mon May 22 04:29:52 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 23:29:23 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

t_map	charge(t_map map)
{
  map.aerospace.robot.energie += 0.2;
  if (map.aerospace.robot.energie > 100)
    map.aerospace.robot.energie = 100;
  return (map);
}

t_map	pilot(t_map map)
{
  map.aerospace.speed = 0.08;
  return (map);
}

t_map	activ_canon(t_map map)
{
  map.aerospace.canons = 1;
  return (map);
}

t_map	charge_shield(t_map map)
{
  map.aerospace.shield_charge += 0.2;
  map.aerospace.robot.energie -= 0.05;
  if (map.aerospace.shield_charge > 100)
    map.aerospace.shield_charge = 100;
  return (map);
}

t_map	repair(t_map map)
{
  map.aerospace.life += 0.2;
  map.aerospace.robot.energie -= 0.1;
  if (map.aerospace.life > 200)
    map.aerospace.life = 200;
  return (map);
}
