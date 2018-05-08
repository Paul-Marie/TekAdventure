/*
** move.h for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue May 23 12:03:22 2017 BETTINELLI Paul-Marie
** Last update Fri May 26 17:56:17 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

#ifndef MOVE_H_
# define MOVE_H_

typedef struct	s_move
{
  float		x;
  float		y;
  float		dx;
  float		dy;
  float		incr1;
  float		incr2;
  float		i;
  float		rab;
}		t_move;

#endif /* !MOVE_H_ */
