/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:06:39 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/08 19:07:13 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "lib/get_next_line.h"
#include </Users/volyvar-/Library/SDL2/SDL.h>
#include </Users/volyvar-/Library/SDL2/SDL_ttf.h>
#include </Users/volyvar-/Library/SDL2/SDL_image.h>
#include "../vm.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// #define GAME_FON_COL 0x0b2852

// # include "/Users/volyvar-/Library/SDL2/SDL_image.h"

typedef struct		s_theme
{
		SDL_Rect rect0;
		SDL_Rect rect1;
		SDL_Rect rect2;
		SDL_Rect rect3;
}					t_theme;

typedef struct		s_players
{
	SDL_Surface *	pl1;
	SDL_Surface *	pl1_sh;
	SDL_Surface *	pl2;
	SDL_Surface *	pl2_sh;
	SDL_Surface *	pl3;
	SDL_Surface *	pl3_sh;
	SDL_Surface *	pl4;
	SDL_Surface *	pl4_sh;
}					t_players;

typedef struct s_lis
{
	int	posi;
	struct s_lis *next;
}				t_lis;

typedef struct		s_game
{
	unsigned char	*field;
	unsigned char	*prev_field;
	short *prev_owner;
	t_lis			*posi;


	int		cycle;
	int		processes;
	int		cycle_to_die;
	int		cycle_delta;
	int		nbr_live;
	int		max_checks;
	int		status;
}					t_game;

typedef struct		s_player_info
{
		char		*pl1_name;
		char		*pl2_name;
		char		*pl3_name;
		char		*pl4_name;
		
		char		*pl1_slogan;
		char		*pl2_slogan;
		char		*pl3_slogan;
		char		*pl4_slogan;
		
		char		**pl1_comm;
		char		**pl2_comm;
		char		**pl3_comm;
		char		**pl4_comm;

		SDL_Surface *pic_com1;
		SDL_Surface *pic_com2;
		SDL_Surface *pic_com3;
		SDL_Surface *pic_com4;
		
		SDL_Color	pl1_col;
		SDL_Color	pl2_col;
		SDL_Color	pl3_col;
		SDL_Color	pl4_col;

}					t_player_info;

// typedef struct		s_final
// {
// 	SDL_Surface *r1_black;
// 	SDL_Surface *pic_com2;
// 	SDL_Surface *pic_com3;
// 	SDL_Surface *pic_com4;
// }					t_final;

typedef struct		s_core
{
		SDL_Window *window;

		SDL_Surface *screenSurface;
		SDL_Surface *winner;
		SDL_Surface *winner_frame;
		SDL_Surface *strelochka;
		SDL_Surface *text_surface;

		TTF_Font *font_menu;
		TTF_Font *font_field;
		TTF_Font *font_name;
		
		t_players	*players;
		t_theme		*theme;
		t_player_info		*player_info;
		
		t_game		*game;
		

		int			*players_status;//NULL
		int			*status_status;//NULL
		int SCREEN_WIDTH;
		int SCREEN_HEIGHT;
		int		status;
		SDL_Event event;
		SDL_Color text_color;
		int col;	
		int			number_players;
		int			number_theme;
		int			game_fon;
}					t_core;

/*
** error.c
*/

void	ft_error();
void	ft_error_ttf();
void	ft_success(t_core *core);

/*
** free.c
*/
void	ft_free_core(t_core *core);
void	ft_delete_players(t_core *core);

/*
** initial_core.c
*/
void	ft_empty_core(t_core *core);
int		ft_init_core(t_core *core, t_vm *vm);
void	ft_init_players(t_core *core);
void	ft_init_players_info(t_core *core);

/*
** choose_theme.c
*/
int		ft_choose_theme(t_core *core);
int		ft_create_instruments(t_core *core);

/*
** theme_text.c
*/

int		ft_text_theme(t_core *core, char *str);
int		ft_text_fight(t_core *core, int fl);
int		ft_text_inter(t_core *core, int fl);
int		ft_text_disco(t_core *core, int fl);


/*
** choose_players.c
*/

int		ft_choose_players(t_core *core);
int		ft_load_players_info(t_core *core, t_vm *vm);
void	ft_get_col(SDL_Color *col, int mycol);

/*
** game.c
*/

int		ft_game(t_core *core, t_vm *vm);

/*
** draw_field.c
*/

int		ft_draw_field(t_core *core, t_vm *vm, int flag);
void	ft_eql_col(SDL_Color *col1, SDL_Color col2);
int		ft_get_symb(t_core *core, char **str, int flag);
int ft_find_owner_col(t_core *core, short pl, short max_pl);

/*
** draw_letter.c
*/

int		ft_draw_letter(t_core *core, int n, t_vm *vm);
int		ft_draw_wall(t_core *core, int n);

/*
** see_stat.c
*/

int		ft_see_stat1(t_core *core, int x, int y, int num);
int		ft_present_status(t_core *core);
int		ft_fill_status_array(t_core *core, int a, int b);

/*
** comments.c
*/

int		ft_load_comments(t_core *core);
int		ft_change_comment(t_core *core);
int		ft_load_pic_com(t_core *core);

/*
** move_car.c
*/

int		ft_move_car(t_core *core);

/*
** main.c
*/

int main_vis(t_vm *vm);

char			*ft_itoa_base(unsigned short value, int base);

/*
** pause.c
*/

int		ft_draw_pause(t_core *core);
int		ft_redraw_pause(t_core *core, t_vm *vm);

/*
** draw_carriet.c
*/

int		ft_draw_carriet(t_core *core, t_vm *vm);

/*
** end_game.c
*/

int		ft_end_game(t_core *core, t_vm *vm);

/*
** present_winner.c
*/

int		ft_present_winner(t_core *core, t_vm *vm);

/*
** titres.c
*/

int		ft_titres(t_core *core);
int		ft_draw_titre(t_core *core, int y, char *aut);