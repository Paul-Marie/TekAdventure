/*
** rocket.h for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Fri May 26 17:06:29 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 14:52:33 2017 BETTINELLI Paul-Marie
*/

#ifndef ROCKET_H_
# define ROCKET_H_

typedef struct	s_rocket
{
  sfVector2f	pos;
  sfSprite	*sprite;
  sfTexture	*texture;
}		t_rocket;

#endif /* !ROCKET_H_ */
