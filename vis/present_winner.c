/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_winner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:57:05 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/08 19:11:42 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl2.h"

int		ft_find_winner_file(char **str, int theme, int pl)
{
	char *str1;
	char *str2;
	char *str3;

	str1 = strdup("./game/winner/t");
	str2 = ft_itoa(theme);
	str3 = ft_strjoin(str1, str2);
	ft_strdel(&str1);
	ft_strdel(&str2);
	str1 = ft_strdup("_p");
	str2 = ft_strjoin(str3, str1);
	ft_strdel(&str1);
	ft_strdel(&str3);
	str1 = ft_itoa(pl);
	str3 = ft_strjoin(str2, str1);
	ft_strdel(&str1);
	ft_strdel(&str2);
	str1 = ft_strdup(".bmp");
	*str = ft_strjoin(str3, str1);
	ft_strdel(&str1);
	ft_strdel(&str3);
	return (0);
}

int		ft_present_winner(t_core *core, t_vm *vm)
{
	char *str;
	t_pl player;
	SDL_Rect rect;
	SDL_Rect rect1;
	char *name;
	int num;
	char *trim;
	static int flag;

	rect1.x = 0;
	rect1.y = 0;
	rect1.w = 1000;
	rect1.h = 1000;

	SDL_FillRect(core->screenSurface, &rect1, 0x2f7190);
	// rect1.x = 1000;
	// SDL_FillRect(core->screenSurface, &rect1, 0x000000);

	ft_find_winner_file(&str, core->number_theme, ft_find_owner_col(core, vm->cw->last_alive + 1, vm->max_pl));
	core->winner = SDL_LoadBMP(str);
	rect.x = 250;
	rect.y = 250;
	rect.h = 500;
	rect.w = 500;
	SDL_BlitSurface(core->winner, NULL, core->screenSurface, &rect);

	// if (!flag)
	// {
		// core->winner = SDL_LoadBMP("./game/winner/winner.bmp");
		flag = 1;
	// }
	rect.x = 100;
	rect.y = 120;
	rect.h = 800;
	rect.w = 800;
	SDL_BlitSurface(core->winner_frame, NULL, core->screenSurface, &rect);

	ft_strdel(&str);
	player = vm->player[vm->cw->last_alive];
	name = ft_strdup(player.name);
	str = ft_strjoin(name, "   as   ");
	ft_strdel(&name);
	num = ft_find_owner_col(core, vm->cw->last_alive + 1, vm->max_pl);
	if (num == 1)
	{
		trim = ft_strtrim(core->player_info->pl1_name);
		name = ft_strjoin(str, trim);
		ft_strdel(&trim);
	}
	if (num == 2)
	{
		trim = ft_strtrim(core->player_info->pl2_name);
		name = ft_strjoin(str, trim);
		ft_strdel(&trim);
	}
	if (num == 3)
	{
		trim = ft_strtrim(core->player_info->pl3_name);
		name = ft_strjoin(str, trim);
		ft_strdel(&trim);
	}
	if (num == 4)
	{
		trim = ft_strtrim(core->player_info->pl4_name);
		name = ft_strjoin(str, trim);
		ft_strdel(&trim);
	}
	ft_strdel(&str);
	rect.x = 250;
	rect.y = 900;
	rect.w = 500;
	rect.h = 80;
	ft_get_col(&core->text_color, 0xffd500);
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, (const char *)name, core->text_color)))
				ft_error_ttf();
	SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &rect);
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
	ft_strdel(&name);
	SDL_UpdateWindowSurface(core->window);
	// printf("file_name=%s\n", str);
	return (0);
}