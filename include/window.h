
#ifndef WINDOW_H_
# define WINDOW_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Network.h>

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

#include "move.h"
#include "node.h"
#include "rocket.h"
#include "menu.h"
#include "dbox.h"
#include "texture.h"
#include "whole.h"
#include "tekav.h"

/*
***************************************************************************
**                                 Scene                                 **
***************************************************************************
** speed = vitesse de défilement de la scène
** state = état graphique de la scène
*/

typedef struct	s_bgpattern
{
  sfTexture		*texture;
  sfSprite		*sprite;
  sfVector2f		pos;
  struct s_bgpattern	*next;
}		t_bgpattern;

typedef struct	s_scene
{
  t_bgpattern	*bg;
  float		speed;
  int		state;
}		t_scene;

/*
***************************************************************************
**                                Missile                                **
***************************************************************************
**
** pos.x = position en x
** pos.y = position en y
** speed.x = vitesse en x
** speed.y = vitesse en y
** speed.z = vitesse en z
** damage = dégâts du projectile
** sprite = apparence du projectile
** side = source du missile (joueur ou ennemi)
*/

typedef struct	s_missile
{
  sfVector2f	pos;
  sfVector3f	speed;
  int		damage;
  int		sprite;
  int		side;
}		t_missile;

/*
***************************************************************************
**                                Player                                 **
***************************************************************************
**
** pos.x = position en x
** pos.y = position en y
** size.x = taille en hauteur
** size.y = taille en largeur
** life = vie du vaisseau
** armor = réduction des dégâts

** pattern = chemin des projectiles
** missile = spécifications des projectiles
** move = bouge t-il actuellement
** node = structure contenant les 5 position de machine
*/

typedef struct	s_player
{
  sfSprite	*sprite;
  sfTexture	*texture;
  t_texture	*frame;
  t_missile	*missile;
  t_node	*node;
  sfVector2f	direction;
  sfVector2f	pos;
  sfVector2f	size;
  sfVector2f	scale;
  float		life;
  float		armor;
  int		pattern;
  int		move;
  t_map		map;
}		t_player;

/*
***************************************************************************
**                                Ennemy                                 **
***************************************************************************
**
** pos.x = position en x
** pos.y = position en y
** size.x = taille en hauteur
** size.y = taille en largeur
** speed = vitesse du vaisseau
** life = vie du vaisseau
** armor = réduction des dégâts
** damage_c = dégâts de collision
** pattern_v = trajectoire du vaisseau
** pattern_m = chemin des projectiles
** missile = spécifications des projectiles
*/

typedef struct	s_enemy
{
  sfVector2f	pos;
  sfVector2f	size;
  float		speed;
  int		life;
  int		armor;
  int		damage_c;
  int		pattern_v;
  int		pattern_m;
  t_missile	*missile;
}		t_enemy;

/*
***************************************************************************
**                                Object                                 **
***************************************************************************
**
*/

typedef struct		s_object
{
  sfTexture		*texture;
  sfSprite		*sprite;
  sfVector2f		pos;
}			t_object;

/*
***************************************************************************
**                                Window                                 **
***************************************************************************
*/

# define SCREEN_WIDTH	1920
# define SCREEN_HEIGHT	1080

typedef struct		s_window
{
  sfVideoMode		mode;
  sfRenderWindow	*window;
  sfMusic		*background;
  sfMusic		*step;
  sfMusic		*charge;
  t_dbox		*dbox;
  t_scene		*scene;
  t_player		*player;
  t_missile		*missile;
  t_whole		*whole;
  sfVector2i		pos;
  t_object		*alien;
  t_object		*aster;
  t_map			map;
}			t_window;

/*
***************************************************************************
**                              Utilities                                **
***************************************************************************
*/

int	print_err(char *err);

/*
***************************************************************************
**                                Window                                 **
***************************************************************************
*/

sfVideoMode	setVideoMode();
int		init_window(t_window *window);
int		disp_window();
int		disp_end(t_window *window, t_player *player, t_menu *menu);
int		disp_loop(t_window *window, t_player *player, t_menu *menu);
t_player	*event_handler(t_window *w, t_player *player, t_menu *menu);

/*
***************************************************************************
**                                 Scene                                 **
***************************************************************************
*/

void	(*define_scene[6])(t_window *window);
void	init_scene(t_window *window);
void	init_alien(t_window *window);
void	init_asteroid(t_window *window);
void	disp_scene(t_window *window);
void	disp_alien(t_window *window);
void	disp_asteroid(t_window *window);

/*
***************************************************************************
**                                Player                                 **
***************************************************************************
*/

int		disp_player(t_window *window, t_player *player);
int		disp_bar(t_window *window, t_menu *menu,
			 t_player *player);
t_node		*init_node();
t_player	*init_player(t_window *window, t_node *node);
t_player	*player_move(t_window *window, t_player *player,
			     sfVector2f pos, t_menu *menu);
t_move		*init_move(sfVector2f pos1, sfVector2f pos2);
t_rocket	*init_rocket(t_window *window);
t_rocket	*init_life(t_window *window);
t_rocket	*init_shield(t_window *window);
t_menu		*init_menu(t_window *window);
t_dbox		*init_dbox();
t_dbox		*reset_dbox(t_dbox *dbox);
t_dbox		*add_dbox(t_dbox *dbox, int numero);
int		disp_machine_dbox(t_window *window);
int		disp_endtime(t_window *window, float x);
int		goto_machine(t_window *window, sfEvent event);
int		disp_dbox(t_window *window);
int		disp_room(t_window *window, t_player *player);
t_dbox		*is_clicked(t_window *window, t_player *player);
int		wich_pos(t_window *window, t_player *player);
t_whole		*init_whole();
t_element	*init_room();
int		disp_moving_room(t_window *window,
				 t_player *player, t_move *move);
t_player	*check_event(t_player *player);
int		disp_shipbar(t_window *window, t_player *player);
void		disp_shield(t_window *window, t_menu *menu);
void		disp_semibar(t_window *window, float lifepoint,
			     sfVector2f position, sfColor color);
void		my_putstr(char *str);
t_element	*init_chargingprise();

#endif /* !WINDOW_H_ */
