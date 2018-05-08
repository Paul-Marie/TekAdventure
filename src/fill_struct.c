/*
** fill_struct.c for tekav in /home/Paul.Juyaux/Projet/EN_COUR/tekadventure/test
** 
** Made by Paul Juyaux
** Login   <Paul.Juyaux@epitech.net>
** 
** Started on  Sun May 28 11:25:46 2017 Paul Juyaux
** Last update Sun May 28 14:48:22 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

t_robot		fill_robot()
{
  t_robot	robot;

  robot.pilote = 0;
  robot.charge_shield = 0;
  robot.repair = 0;
  robot.charge = 0;
  robot.energie = 100;
  return (robot);
}

t_aerospace	fill_aerospace()
{
  t_aerospace	aerospace;

  aerospace.canons = 0;
  aerospace.speed = 0.04;
  aerospace.canon_time = 0;
  aerospace.shield_charge = 100;
  aerospace.life = 200;
  aerospace.robot = fill_robot();
  return (aerospace);
}

t_map		fill_map()
{
  t_map		map;

  map.avancment = 50;
  map.event = 0;
  map.event_time = 100;
  map.aerospace = fill_aerospace();
  return (map);
}

