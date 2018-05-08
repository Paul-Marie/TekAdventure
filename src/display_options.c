/*
** display_options.c for tekadventure in /home/linet.vincent/CGraphicalProgramming/tekadventure
** 
** Made by LINET Vincent
** Login   <linet.vincent@epitech.net>
** 
** Started on  Fri Apr 21 12:52:59 2017 LINET Vincent
** Last update Sun May 28 07:34:06 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

sfVideoMode     setVideoMode()
{
  sfVideoMode   mode;

  mode.width = 1920;
  mode.height = 1080;
  mode.bitsPerPixel = 32;
  return (mode);
}
