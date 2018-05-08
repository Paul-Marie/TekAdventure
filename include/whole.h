/*
** whole.h for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Sun May 28 13:52:28 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 14:52:24 2017 BETTINELLI Paul-Marie
*/

#ifndef WHOLE_H_
# define WHOLE_H_

typedef struct	s_element
{
  sfVector2f	pos;
  sfSprite	*sprite;
  sfTexture	*texture;
}		t_element;

typedef struct	s_whole
{
  t_element	*room;
  t_element	*prise;
  t_element	*ladder;
  t_element	*computeur;
  t_element	*commandpost;
  t_element	*chargingprise;
}		t_whole;

#endif /* !WHOLE_H_ */
