/*
** texture.h for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Thu May 25 12:53:28 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 14:52:41 2017 BETTINELLI Paul-Marie
*/

#ifndef TEXTURE_H_
# define TEXTURE_H_

typedef struct	s_texture
{
  sfTexture	**run;
  sfTexture	**runinv;
  sfTexture	**idle;
  sfTexture	**dead;
}		t_texture;

t_texture	*init_texture();

#endif /* !TEXTURE_H_ */
