/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:53:30 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/08 19:11:37 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl2.h"

int		ft_draw_pause(t_core *core)
{
	SDL_Rect rect;
	SDL_Color col;

	rect.x = 250;
	rect.y = 0;
	rect.h = 960;
	rect.w = 1500;

	// col.r = 0xff;
	// col.g = 0xd8;
	// col.b = 0xbd;
	ft_get_col(&col, 0xffffff);
	col.a = 60;

	// printf("draw pause\n");
	// SDL_FillRect(core->screenSurface, &rect, 0xffffff);
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_menu, ("pause"), col)))
		ft_error_ttf();
	SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &rect);
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
	return (0);
}

int		ft_redraw_pause(t_core *core, t_vm *vm)
{
	SDL_Rect rect;

	rect.x = 250;
	rect.y = 0;
	rect.h = 960;
	rect.w = 1500;

	SDL_FillRect(core->screenSurface, &rect, core->game_fon);
	ft_draw_field(core, vm, 1);
	ft_draw_carriet(core, vm);
	return (0);
}