##
## Makefile for Makefile in /home/Paul-Marie/Tek1/MUL/tekadventure
## 
## Made by BETTINELLI Paul-Marie
## Login   <Paul-Marie@epitech.net>
## 
## Started on  Mon May 22 07:24:03 2017 BETTINELLI Paul-Marie
## Last update Tue May 30 10:04:28 2017 LINET Vincent
##

CC	=	@gcc

RM	=	@rm -f

SRC	=	$(addprefix src/,		\
		display_options.c		\
		display_shipbar.c		\
		display_player.c		\
		display_asteroid.c		\
		display_alien.c			\
		display_dbox.c			\
		display_room.c			\
		texture_init.c			\
		player_move.c			\
		display_bar.c			\
		check_event.c			\
		fill_struct.c			\
		gest_event.c			\
		timeup_bar.c			\
		my_putchar.c			\
		whole_init.c			\
		menu_init.c			\
		my_putstr.c			\
		display.c			\
		scenery.c			\
		errors.c			\
		action.c			\
		my_ev.c				\
		event.c				\
		goto.c				\
		init.c				\
		main.c)

NOM	=	$(basename $(notdir $(SRC)))

OBJ	=	$(addprefix obj/, $(addsuffix .o, $(NOM)))

CFLAGS	+=	-Wall -Wextra -g3 -Wpedantic -o3

CPPFLAGS	=	-Iinclude

LDLIBS	=	-lm -lc_graph_prog

NAME	=	tekadventure

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) -lc_graph_prog -lm
	$(eval($(MAK) = 42))
ifeq ($(MAK),)
	@echo -e "\033[32m* * * * * COMPLETED * * * * *\033[0m"
endif

clean:
	@$(RM) $(OBJ)
	$(eval($(CLE) = 42))
ifeq ($(CLE),)
	@echo -e "\033[31m* * * * *  CLEANED  * * * * *\033[0m"
endif

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

obj/%.o:	src/%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -c -o $@ $< && echo -e "\e[32m[OK]\033[0m\e[1m\e[32m" $< "\033[0m" || echo -e "\e[91;5m[KO]\e[25m" $< "\033[0m"

.PHONY: all clean fclean re obj/%.o
