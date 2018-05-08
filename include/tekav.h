/*
** tekav.h for tekav in /home/Paul.Juyaux/Projet/EN_COUR/tekadventure/test
** 
** Made by Paul Juyaux
** Login   <Paul.Juyaux@epitech.net>
** 
** Started on  Fri May 26 10:36:19 2017 Paul Juyaux
** Last update Sun May 28 20:47:47 2017 Paul Juyaux
*/

#ifndef TEKAV_H_
# define TEKAV_H_

#include <stdlib.h>
#include <unistd.h>

typedef struct	s_robot
{
  int		pilote;
  int		charge_shield;
  int		repair;
  int		charge;
  float		energie;
}		t_robot;

typedef struct	s_aerospace
{
  int		canons;
  float		canon_time;
  float	        speed;
  float		shield_charge;
  float		life;
  t_robot	robot;
}		t_aerospace;

typedef struct	s_map
{
  float		avancment;
  int		event;
  int		event_time;
  t_aerospace	aerospace;
}		t_map;

t_map		add_event(t_map);

t_map		alien(t_map);
t_map		asteroide(t_map);
t_map		nothing(t_map);
t_robot		fill_robot();
t_map		fill_map();

// Fonction pour Charger le Robot

t_map	charge(t_map);

// Fonction où le robot pilote

t_map	pilot(t_map);

// Fonction qui active les canons

t_map	activ_canon(t_map);

// Fonction pour charger les boucliers

t_map	charge_shield(t_map);

// Fonction pour réparer le vaisseau

t_map	repair(t_map);

t_map	fill_map();

#endif
