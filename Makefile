# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 12:16:02 by bsabre-c          #+#    #+#              #
#    Updated: 2020/02/13 21:05:53 by bsabre-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= corewar
FLAGS		= -Wall -Wextra -Werror  -g

# directories
DIR_O		=	objects
DIR_V		=	vis
DIR_SRC		=	src
DIR_INC		=	includes

# files
SRC			=	vm_main.c						vm_free_exit.c				\
				vm_reader.c						vm_parse_flags_1.c			\
				vm_parse_flags_2.c				vm_extract.c				\
				vm_carriage_1.c					vm_carriage_2.c				\
				vm_initialize_all.c				vm_initialize_game.c		\
				vm_dump.c						vm_getters.c				\
				vm_get_set_bytes.c		\
				vm_war.c						vm_dump_arena.c			\
							vm_operation/null.c		\
							vm_operation/live.c		\
							vm_operation/ld.c		\
							vm_operation/st.c		\
							vm_operation/add.c		\
							vm_operation/sub.c		\
							vm_operation/and.c		\
							vm_operation/or.c		\
							vm_operation/xor.c		\
							vm_operation/zjmp.c		\
							vm_operation/sti.c		\
							vm_operation/ldi.c		\
							vm_operation/fork.c		\
							vm_operation/lld.c		\
							vm_operation/lldi.c		\
							vm_operation/lfork.c	\
							vm_operation/aff.c		

VIS			=	choose_players.c 				choose_theme.c				\
				comments.c						draw_field.c				\
				draw_letter.c					error.c						\
				free.c							game.c						\
				initial_core.c					main.c						\
				see_stat.c						theme_text.c				\
				lib/get_next_line.c  			pause.c draw_carriet.c 		\
				end_game.c 						present_winner.c			\
				titres.c						choose_players_h.c			\
				choose_players_hh.c				ft_load_players.c			\
				ft_load_players_info.c			ft_load_players_info_h.c	\
				ft_choose_players.c				ft_choose_theme.c			\
				comments_help.c					comments_help_h.c			\
				comments_help_hh.c				comments_help_hhh.c			\
				ft_new_hope.c					ft_change_comment.c			\
				comments_h.c					ft_find_owner_col.c			\
				draw_field_help.c 				ft_find_winner_file.c		\
				ft_del.c						ft_free_player_info.c		\
				present_status.c				status_change.c				\
				players_game.c					put_field.c					\
				defines.c						fon.c						\
				game_event.c					game_func.c

INC			=	op.h vis.h vm.h
D_INC		=	$(addprefix $(DIR_INC)/,$(INC))

SRC_D		=	$(addprefix $(DIR_SRC)/,$(SRC))
# OBJ			=	$(addprefix $(DIR_O)/,$(SRC_D:.c=.o))
OBJ_V		=	$(addprefix $(DIR_V)/,$(VIS:.c=.o))
OBJ			=	$(SRC_D:.c=.o)

TTF			=	-I./includes -L./sdl2library/ttf -lSDL2_ttf
SDL			=	-I./includes -L./sdl2library/orig -lSDL2

# libraries
L_FT_D 		= 	./libft
L_FT_L 		= 	$(L_FT_D)/libft.a
 
AAAA 		= 		-I./frameworks/SDL2.framework/Versions/A/Headers \
					-I./frameworks/SDL2_image.framework/Versions/A/Headers \
					-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
					-I./frameworks/SDL2_mixer.framework/Versions/A/Headers \

FRAMEWORKS	=		-F./frameworks \
					-rpath ./frameworks \
					-framework SDL2 -framework SDL2_ttf -framework SDL2_image -framework SDL2_mixer

.PHONY: all clean fclean re proj

$(NAME) : $(OBJ) $(OBJ_V) 
			@make -sC $(L_FT_D)
			@echo "Compiling corewar"
			@gcc $(FLAGS) $(OBJ) $(OBJ_V) $(INCS) $(L_FT_L) $(FRAMEWORKS) -o $(NAME)
			@echo "File $(NAME) was created succesfully"

%.o: %.c
			gcc $(CFLAGS) $(INCS) -I$(DIR_INC) -I$(L_FT_D) -c $< -o $@ 

clean :
			@echo "Start cleaning"
			@make clean -sC $(L_FT_D)
			@rm -rf .DS_Store
			@rm -rf $(L_FT_D)/.DS_Store
			@rm -rf $(OBJ)
			@rm -rf $(OBJ_V)
			@echo "Cleaning finished"

fclean : clean
			@rm -rf $(L_FT_L)
			@rm -rf $(NAME)
			@rm -rf $(NAME).dSYM

all : 		$(NAME)

re: fclean all
