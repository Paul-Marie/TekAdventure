/*
** gest_event.c for tekav in /home/Paul.Juyaux/Projet/EN_COUR/tekadventure/test
** 
** Made by Paul Juyaux
** Login   <Paul.Juyaux@epitech.net>
** 
** Started on  Fri May 26 10:39:10 2017 Paul Juyaux
** Last update Sun May 28 23:39:43 2017 Paul Juyaux
*/

#include "window.h"

t_map	add_event(t_map map)
{
  int	time[4];

  time[0] = (rand() % 200) + 200;
  time[1] = (rand() % 200) + 200;
  time[2] = (rand() % 300) + 200;
  map.event_time -= 1;
  if (map.event_time > 0)
    return (map);
  map.event = (rand() % 3);
  map.event_time = time[map.event];
  return (map);
}
