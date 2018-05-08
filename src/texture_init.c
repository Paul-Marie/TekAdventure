/*
** texture_init.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Thu May 25 13:14:59 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 14:51:58 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

t_texture	*init_run(t_texture *texture)
{
  if ((texture->run = malloc(sizeof(sfSprite *) * 9)) == NULL)
    return (NULL);
  texture->run[0] =
    sfTexture_createFromFile("ressource/image/run/Run (1).png", NULL);
  texture->run[1] =
    sfTexture_createFromFile("ressource/image/run/Run (2).png", NULL);
  texture->run[2] =
    sfTexture_createFromFile("ressource/image/run/Run (3).png", NULL);
  texture->run[3] =
    sfTexture_createFromFile("ressource/image/run/Run (4).png", NULL);
  texture->run[4] =
    sfTexture_createFromFile("ressource/image/run/Run (5).png", NULL);
  texture->run[5] =
    sfTexture_createFromFile("ressource/image/run/Run (6).png", NULL);
  texture->run[6] =
    sfTexture_createFromFile("ressource/image/run/Run (7).png", NULL);
  texture->run[7] =
    sfTexture_createFromFile("ressource/image/run/Run (8).png", NULL);
  texture->run[8] = NULL;
  return (texture);
}

t_texture	*init_runinv(t_texture *texture)
{
  if ((texture->runinv = malloc(sizeof(sfSprite *) * 9)) == NULL)
    return (NULL);
  texture->runinv[0] =
    sfTexture_createFromFile("ressource/image/runinv/Runinv (1).png", NULL);
  texture->runinv[1] =
    sfTexture_createFromFile("ressource/image/runinv/Runinv (2).png", NULL);
  texture->runinv[2] =
    sfTexture_createFromFile("ressource/image/runinv/Runinv (3).png", NULL);
  texture->runinv[3] =
    sfTexture_createFromFile("ressource/image/runinv/Runinv (4).png", NULL);
  texture->runinv[4] =
    sfTexture_createFromFile("ressource/image/runinv/Runinv (5).png", NULL);
  texture->runinv[5] =
    sfTexture_createFromFile("ressource/image/runinv/Runinv (6).png", NULL);
  texture->runinv[6] =
    sfTexture_createFromFile("ressource/image/runinv/Runinv (7).png", NULL);
  texture->runinv[7] =
    sfTexture_createFromFile("ressource/image/runinv/Runinv (8).png", NULL);
  texture->runinv[8] = NULL;
  return (texture);
}

t_texture	*init_idle(t_texture *texture)
{
  if ((texture->idle = malloc(sizeof(sfSprite *) * 12)) == NULL)
    return (NULL);
  texture->idle[0] =
    sfTexture_createFromFile("ressource/image/idle/Idle (1).png", NULL);
  texture->idle[1] =
    sfTexture_createFromFile("ressource/image/idle/Idle (2).png", NULL);
  texture->idle[2] =
    sfTexture_createFromFile("ressource/image/idle/Idle (3).png", NULL);
  texture->idle[3] =
    sfTexture_createFromFile("ressource/image/idle/Idle (4).png", NULL);
  texture->idle[4] =
    sfTexture_createFromFile("ressource/image/idle/Idle (5).png", NULL);
  texture->idle[5] =
    sfTexture_createFromFile("ressource/image/idle/Idle (6).png", NULL);
  texture->idle[6] =
    sfTexture_createFromFile("ressource/image/idle/Idle (7).png", NULL);
  texture->idle[7] =
    sfTexture_createFromFile("ressource/image/idle/Idle (8).png", NULL);
  texture->idle[8] =
    sfTexture_createFromFile("ressource/image/idle/Idle (9).png", NULL);
  texture->idle[9] =
    sfTexture_createFromFile("ressource/image/idle/Idle (10).png", NULL);
  texture->idle[10] = NULL;
  return (texture);
}

t_texture	*init_dead(t_texture *texture)
{
  if ((texture->dead = malloc(sizeof(sfSprite *) * 12)) == NULL)
    return (NULL);
  texture->dead[0] =
    sfTexture_createFromFile("ressource/image/dead/Dead (1).png", NULL);
  texture->dead[1] =
    sfTexture_createFromFile("ressource/image/dead/Dead (2).png", NULL);
  texture->dead[2] =
    sfTexture_createFromFile("ressource/image/dead/Dead (3).png", NULL);
  texture->dead[3] =
    sfTexture_createFromFile("ressource/image/dead/Dead (4).png", NULL);
  texture->dead[4] =
    sfTexture_createFromFile("ressource/image/dead/Dead (5).png", NULL);
  texture->dead[5] =
    sfTexture_createFromFile("ressource/image/dead/Dead (6).png", NULL);
  texture->dead[6] =
    sfTexture_createFromFile("ressource/image/dead/Dead (7).png", NULL);
  texture->dead[7] =
    sfTexture_createFromFile("ressource/image/dead/Dead (8).png", NULL);
  texture->dead[8] =
    sfTexture_createFromFile("ressource/image/dead/Dead (9).png", NULL);
  texture->dead[9] =
    sfTexture_createFromFile("ressource/image/dead/Dead (10).png", NULL);
  texture->dead[10] = NULL;
  return (texture);
}

t_texture	*init_texture()
{
  t_texture	*texture;

  if ((texture = malloc(sizeof(t_texture))) == NULL
      || (texture = init_run(texture)) == NULL
      || (texture = init_runinv(texture)) == NULL
      || (texture = init_idle(texture)) == NULL
      || (texture = init_dead(texture)) == NULL)
    return (NULL);
  return (texture);
}
