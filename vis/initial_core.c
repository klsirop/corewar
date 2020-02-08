/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:03:32 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/08 19:13:30 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl2.h"

void	ft_init_players(t_core *core)
{
	if (!core->players)
	{
		// printf("not\n");
		return ;
	}
	core->players->pl1 = NULL;
	core->players->pl1_sh = NULL;
	core->players->pl2 = NULL;
	core->players->pl2_sh = NULL;
	core->players->pl3 = NULL;
	core->players->pl3_sh = NULL;
	core->players->pl4 = NULL;
	core->players->pl4_sh = NULL;
}

void	ft_init_players_info(t_core *core)
{
	core->player_info->pic_com1 = NULL;
	core->player_info->pic_com2 = NULL;
	core->player_info->pic_com3 = NULL;
	core->player_info->pic_com4 = NULL;

	core->player_info->pl1_name = NULL;
	core->player_info->pl2_name = NULL;
	core->player_info->pl3_name = NULL;
	core->player_info->pl4_name = NULL;

	core->player_info->pl1_slogan = NULL;
	core->player_info->pl2_slogan = NULL;
	core->player_info->pl3_slogan = NULL;
	core->player_info->pl4_slogan = NULL;

	core->player_info->pl1_comm = NULL;
	core->player_info->pl2_comm = NULL;
	core->player_info->pl3_comm = NULL;
	core->player_info->pl4_comm = NULL;
}

void	ft_empty_core(t_core *core)
{
	core->screenSurface = NULL;
	core->winner = NULL;
	core->winner_frame = NULL;
	core->strelochka = NULL;
	core->text_surface = NULL;
	
	core->font_menu = NULL;
	core->font_field = NULL;
	core->font_name = NULL;
	core->players = NULL;
	core->theme = NULL;
	core->player_info = NULL;
	core->game = NULL;
	core->players_status = NULL;
	core->status_status = NULL;
}

int		ft_init_core(t_core *core, t_vm *vm)
{
	core->window = NULL;
	core->screenSurface = NULL;
	core->SCREEN_WIDTH = 2000;
	core->SCREEN_HEIGHT = 1000;
	//init necessary part
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		ft_error();
	if (TTF_Init() == -1)
		ft_error_ttf();
	//create window OPEN_GL
	if (!(core->window = SDL_CreateWindow("COREWAR", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, core->SCREEN_WIDTH, core->SCREEN_HEIGHT, SDL_WINDOW_SHOWN)))
		ft_error();
	//create sufrace
	core->screenSurface = SDL_GetWindowSurface(core->window);
	core->status = 0;

	core->number_players = vm->max_pl;//
	// core->number_players = 2;
	core->number_theme = 1;
	
	return (0);
}