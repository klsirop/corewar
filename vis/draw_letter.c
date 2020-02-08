/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_letter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:29:53 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/08 19:11:32 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl2.h"

int		ft_get_symb_n(t_core *core, char **str, int n)
{
	if (!(*str))
		ft_strdel(str);
	*str = (char *)malloc(sizeof(char) * 2);
	(*str)[0] = (core->game->field)[n];
	(*str)[1] = '\0';
	return (0);
}

int		ft_draw_letter(t_core *core, int n, t_vm *vm)
{
	int		new_n;
	int		n_x;
	int		n_y;
	int		x;
	int		y;
	char	*str;
	SDL_Rect rect;

	new_n = (n / 2) * 3 + (n % 2) + 1;
	n_y = new_n / 192;
	n_x = new_n % 192;
	y = 2 + (15) * n_y;
	x = 228 + 8 * n_x;
	rect.x = x;
	rect.y = y;
	rect.w = 6;
	rect.h = 13;
	core->text_color.a = 0;
	if (vm->arena_owner[n / 2] == 0)
			core->text_color.a = 60;
	ft_get_symb_n(core, &str, n);
		if (!(core->text_surface = TTF_RenderText_Blended(core->font_field, (const char *)str, core->text_color)))
			ft_error_ttf();
		SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &rect);
		SDL_FreeSurface(core->text_surface);
		core->text_surface = NULL;
	ft_strdel(&str);
	core->text_color.a = 0;
	if (vm->arena_owner[n / 2] == 0)
			core->text_color.a = 60;
	rect.x+= 8;
	ft_get_symb_n(core, &str, n + 1);
		if (!(core->text_surface = TTF_RenderText_Blended(core->font_field, (const char *)str, core->text_color)))
			ft_error_ttf();
		SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &rect);
		SDL_FreeSurface(core->text_surface);
		core->text_surface = NULL;
	ft_strdel(&str);
	core->text_color.a = 0;
	return (0);
}

int		ft_draw_wall(t_core *core, int n)
{
	int		new_n;
	int		n_x;
	int		n_y;
	int		x;
	int		y;
	char	*str;
	SDL_Rect rect;

	new_n = (n / 2) * 3 + (n % 2) + 1;
	n_y = new_n / 192;
	n_x = new_n % 192;
	y = 2 + (15) * n_y;
	x = 228 + 8 * n_x;
	rect.x = x;
	rect.y = y;
	rect.w = 14;//14
	rect.h = 13;
	// ft_get_symb_n(core, &str, n);
	if (SDL_FillRect(core->screenSurface, &(rect), core->col) < 0)
		ft_error();
	// ft_get_symb_n(core, &str, n + 1);
	// if (SDL_FillRect(core->screenSurface, &(rect), core->col) < 0)
	// 	ft_error();
	return (0);
}