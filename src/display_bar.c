/*
** display_bar.c for tekadventure in /home/Paul-Marie/Tek1/MUL/tekadventure
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Fri May 26 15:21:58 2017 BETTINELLI Paul-Marie
** Last update Sun May 28 07:46:23 2017 BETTINELLI Paul-Marie
*/

#include "window.h"

void			disp_progress_bar(t_window *window)
{
  sfRectangleShape	*rectangle;
  sfRectangleShape	*boarder;
  sfVector2f		size_boarder;
  sfVector2f		pos_boarder;
  sfVector2f		size;
  sfVector2f		pos;

  size.x = 1720;
  size.y = 10;
  size_boarder.x = 1730;
  size_boarder.y = 20;
  pos.x = 100;
  pos.y = 40;
  pos_boarder.x = 95;
  pos_boarder.y = 35;
  rectangle = sfRectangleShape_create();
  boarder = sfRectangleShape_create();
  sfRectangleShape_setFillColor(rectangle, sfWhite);
  sfRectangleShape_setFillColor(boarder, sfBlack);
  sfRectangleShape_setSize(rectangle, size);
  sfRectangleShape_setSize(boarder, size_boarder);
  sfRectangleShape_setPosition(rectangle, pos);
  sfRectangleShape_setPosition(boarder, pos_boarder);
  sfRenderWindow_drawRectangleShape(window->window, boarder, NULL);
  sfRenderWindow_drawRectangleShape(window->window, rectangle, NULL);
}

void			disp_semibar(t_window *window,
				      float lifepoint,
				      sfVector2f position,
				      sfColor color)
{
  sfRectangleShape	*rectangle;
  sfRectangleShape	*boarder;
  sfVector2f		size_boarder;
  sfVector2f		pos_boarder;
  sfVector2f		size;
  sfVector2f		pos;

  size.x = 650 * lifepoint;
  size.y = 24;
  size_boarder.x = 660;
  size_boarder.y = 34;
  pos.x = position.x;
  pos.y = position.y;
  pos_boarder.x = position.x - 5;
  pos_boarder.y = position.y - 5;
  rectangle = sfRectangleShape_create();
  boarder = sfRectangleShape_create();
  sfRectangleShape_setFillColor(rectangle, color);
  sfRectangleShape_setFillColor(boarder, sfBlack);
  sfRectangleShape_setSize(rectangle, size);
  sfRectangleShape_setSize(boarder, size_boarder);
  sfRectangleShape_setPosition(rectangle, pos);
  sfRectangleShape_setPosition(boarder, pos_boarder);
  sfRenderWindow_drawRectangleShape(window->window, boarder, NULL);
  sfRenderWindow_drawRectangleShape(window->window, rectangle, NULL);
}

void	disp_rocket(t_window *window, t_rocket *rocket)
{
  if (rocket->pos.x >= 1770)
    {
      my_putstr("Congratulation, You Win ! :D\n");
      sfRenderWindow_close(window->window);
    }
  rocket->pos.x = rocket->pos.x + 0.05;
  sfSprite_setPosition(rocket->sprite, rocket->pos);
  sfSprite_setTexture(rocket->sprite, rocket->texture, sfTrue);
  sfRenderWindow_drawSprite(window->window, rocket->sprite, NULL);
}

void	disp_shield(t_window *window, t_menu *menu)
{
  sfSprite_setPosition(menu->life->sprite, menu->life->pos);
  sfSprite_setPosition(menu->shield->sprite, menu->shield->pos);
  sfSprite_setTexture(menu->life->sprite, menu->life->texture, sfTrue);
  sfSprite_setTexture(menu->shield->sprite, menu->shield->texture, sfTrue);
  sfRenderWindow_drawSprite(window->window, menu->life->sprite, NULL);
  sfRenderWindow_drawSprite(window->window, menu->shield->sprite, NULL);
}

int		disp_bar(t_window *wind, t_menu *menu,
			 t_player *player)
{
  sfVector2f	shield;
  sfVector2f	life;

  life.x = 1070;
  life.y = 143;
  shield.x = 180;
  shield.y = 143;
  player->map.avancment += player->map.aerospace.speed;
  menu->rocket->pos.x = player->map.avancment;
  player->life = player->map.aerospace.robot.energie / 100;
  player->armor = player->map.aerospace.shield_charge / 100;
  disp_progress_bar(wind);
  disp_shipbar(wind, player);
  disp_semibar(wind, 1, shield, sfBlack);
  disp_semibar(wind, player->armor, shield, sfCyan);
  disp_semibar(wind, 1, life, sfBlack);
  disp_semibar(wind, player->life, life, sfYellow);
  disp_endtime(wind, menu->rocket->pos.x - 20);
  disp_rocket(wind, menu->rocket);
  disp_shield(wind, menu);
  return (0);
}
