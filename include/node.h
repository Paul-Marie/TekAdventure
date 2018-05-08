/*
** node.h for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Tue May 23 06:56:18 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 14:52:28 2017 BETTINELLI Paul-Marie
*/

#ifndef NODE_H_
# define NODE_H_

/*
**		    pos5
**	pos4	     |	     ___pos1
**	    '--,__   |__,---'
**		  '--*__
**	    ,__,----'   '---____
**	pos3			pos2
*/

typedef struct	s_node
{
  sfVector2f	pos1;
  sfVector2f	pos2;
  sfVector2f	pos3;
  sfVector2f	pos4;
  sfVector2f	pos5;
  sfVector2f	middle;
}		t_node;

#endif /* !NODE_H_ */
