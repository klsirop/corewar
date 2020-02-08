/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:07:35 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/08 19:13:37 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl2.h"

void	ft_delete_players(t_core *core)
{
	if (!core->players)
		return ;
	if (core->players->pl1)
	{
		SDL_FreeSurface(core->players->pl1);
		core->players->pl1 = NULL;
	}
	if (core->players->pl2)
	{
		SDL_FreeSurface(core->players->pl2);
		core->players->pl2 = NULL;
	}
	if (core->players->pl3)
	{
		SDL_FreeSurface(core->players->pl3);
		core->players->pl3 = NULL;
	}
	if (core->players->pl4)
	{
		SDL_FreeSurface(core->players->pl4);
		core->players->pl4 = NULL;
	}
	if (core->players->pl1_sh)
	{
		SDL_FreeSurface(core->players->pl1_sh);
		core->players->pl1_sh = NULL;
	}
	if (core->players->pl2_sh)
	{
		SDL_FreeSurface(core->players->pl2_sh);
		core->players->pl2_sh = NULL;
	}
	if (core->players->pl3_sh)
	{
		SDL_FreeSurface(core->players->pl3_sh);
		core->players->pl3_sh = NULL;
	}
	if (core->players->pl4_sh)
	{
		SDL_FreeSurface(core->players->pl4_sh);
		core->players->pl4_sh = NULL;
	}
	
	
}

void	ft_free_arr(char **arr)
{
	int i;

	i = 0;
	while (i < 3)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
}

void	ft_list_del(t_lis *list)
{
	t_lis *tmp;

	tmp = list;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	list = NULL;
}

void	ft_free_core(t_core *core)
{
	// tr 1
	
	if (!core)
		return ;
	if (core->text_surface)
		SDL_FreeSurface(core->text_surface);//!!!!!!!!!!!!!!!!
	if (core->screenSurface)
		SDL_FreeSurface(core->screenSurface);

	if (core->strelochka)
		SDL_FreeSurface(core->strelochka);
	if (core->winner_frame)
		SDL_FreeSurface(core->winner_frame);
	if (core->winner)
		SDL_FreeSurface(core->winner);

	//
	
	if (core->font_menu)
	{
		TTF_CloseFont(core->font_menu);
		core->font_menu = NULL;
	}
	if (core->font_field)
	{
		TTF_CloseFont(core->font_field);
		core->font_field = NULL;
	}
	if (core->font_name)
	{
		TTF_CloseFont(core->font_name);
		core->font_name = NULL;
	}

	if (core->window)
		SDL_DestroyWindow(core->window);
	if (core->players)
	{
		ft_delete_players(core);
		free(core->players);
		core->players = NULL;
	}
	if (core->theme)
	{
		free(core->theme);
		core->theme = NULL;
	}
	
	if (core->player_info)
	{
		if (core->player_info->pl1_name)
			ft_strdel(&core->player_info->pl1_name);
		if (core->player_info->pl2_name)
			ft_strdel(&core->player_info->pl2_name);
		if (core->player_info->pl3_name)
			ft_strdel(&core->player_info->pl3_name);
		if (core->player_info->pl4_name)
			ft_strdel(&core->player_info->pl4_name);

		if (core->player_info->pl1_slogan)
			ft_strdel(&core->player_info->pl1_slogan);
		if (core->player_info->pl2_slogan)
			ft_strdel(&core->player_info->pl2_slogan);
		if (core->player_info->pl3_slogan)
			ft_strdel(&core->player_info->pl3_slogan);
		if (core->player_info->pl4_slogan)
			ft_strdel(&core->player_info->pl4_slogan);

		if (core->player_info->pic_com1)
			SDL_FreeSurface(core->player_info->pic_com1);
		if (core->player_info->pic_com2)
			SDL_FreeSurface(core->player_info->pic_com2);
		if (core->player_info->pic_com3)
			SDL_FreeSurface(core->player_info->pic_com3);
		if (core->player_info->pic_com4)
			SDL_FreeSurface(core->player_info->pic_com4);

		if (core->player_info->pl1_comm)
		{
			ft_free_arr(core->player_info->pl1_comm);
			free(core->player_info->pl1_comm);
		}
		if (core->player_info->pl2_comm)
		{
			ft_free_arr(core->player_info->pl2_comm);
			free(core->player_info->pl2_comm);
		}
		if (core->player_info->pl3_comm)
		{
			ft_free_arr(core->player_info->pl3_comm);
			free(core->player_info->pl3_comm);
		}
		if (core->player_info->pl4_comm)
		{
			ft_free_arr(core->player_info->pl4_comm);
			free(core->player_info->pl4_comm);
		}
		free(core->player_info);
		core->player_info = NULL;
	}
	// tr 2

	if (core->game)
	{
		if (core->game->field)
			ft_strdel((char **)(&core->game->field));//////////////
		if (core->game->prev_field)
			ft_strdel((char **)(&core->game->prev_field));////////////
		if (core->game->prev_owner)
			free(core->game->prev_owner);////////////
		if (core->game->posi)
			ft_list_del(core->game->posi);
	}

	//
	if (core->players_status)
		free(core->players_status);
	if (core->status_status)
		free(core->status_status);
}

