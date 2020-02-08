/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:23:19 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/08 19:11:07 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl2.h"

int		ft_other(t_core *core)
{
	SDL_Rect rect;
	SDL_Rect rect1;

	rect.x = 0;
	rect.y = 0;
	rect.w = 2000;
	rect.h = 1000;

	SDL_FillRect(core->screenSurface, &rect, 0x000000);

	rect1.x = 930;
	rect1.y = 900;
	rect1.w = 140;
	rect1.h = 50;
	SDL_BlitSurface(core->strelochka, NULL, core->screenSurface, &rect1);
	// SDL_FillRect(core->screenSurface, &rect1, 0xffffff);
	
	return (0);
}

int		ft_game_over(t_core *core)
{
	SDL_Rect rect;
	SDL_Color col;

	rect.x = 0;
	rect.y = 50;
	rect.h = 900;
	rect.w = 1900;

	// col.r = 0xff;
	// col.g = 0xd8;
	// col.b = 0xbd;
	// col.r = 0xac;
	// col.g = 0x75;
	// col.b = 0x4c;
	ft_get_col(&col, 0x5f010a);
	col.a = 20;

	// printf("draw pause\n");
	// SDL_FillRect(core->screenSurface, &rect, 0xffffff);
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_menu, ("game over"), col)))
		ft_error_ttf();
	SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &rect);
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
	// SDL_UpdateWindowSurface(core->window);
	return (0);
}

int		ft_end_game(t_core *core, t_vm *vm)
{
	SDL_Rect rect;

	rect.x = 0;
	rect.y = 0;
	rect.w = 1000;
	rect.h = 1000;

	// printf("ok\n");
	// if (SDL_PollEvent(&(core->event)) != 0)
	// {
	// if ((core->event.key.keysym.sym == SDLK_ESCAPE) || (core->event.type == SDL_QUIT)) //escape
	// 	return (1);
	// }
	// printf("winner=%d", vm->cw->last_alive);

	if (core->game->status == 8)
	{
		int i = 0;
		while (i < 1000)
		{
			if (SDL_PollEvent(&(core->event)) != 0)
			{
				if ((core->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (core->event.type == SDL_QUIT)) //escape
					return (1);
					if ((core->event.button.button == SDL_BUTTON_LEFT) && ((core->event.button.x >= 930 && core->event.button.x <= 1070) &&
																	   (core->event.button.y >= 900 && core->event.button.y <= 950)))
				{
					SDL_FillRect(core->screenSurface, &rect, 0x2f7190);
					rect.x = 1000;
					SDL_FillRect(core->screenSurface, &rect, 0x000000);
					SDL_UpdateWindowSurface(core->window);
					core->game->status = 9;
					// printf("ok3\n");
					return (0);
				}
			}
			ft_game_over(core);
			i += 10;
			SDL_UpdateWindowSurface(core->window);
		}
		// SDL_Delay(10);
		// ft_present_winner(core, vm);
		ft_other(core);
	}
	if (core->game->status >= 9)
	{
		// printf("here 9\n");
		if (SDL_PollEvent(&(core->event)) != 0)
		{
			if ((core->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (core->event.type == SDL_QUIT)) //escape
				return (1);
		}
		if (core->game->status == 9)
		{
			ft_present_winner(core, vm);
			ft_titres(core);
		}
		// if (core->game->status == 10)
		// {
		// 	printf("print\n");
		// 	//core->game->status = 11;
		// 	ft_draw_titre(core, 320, "bsabre-c");
		// 	ft_draw_titre(core, 420, "jmaynard");
		// 	ft_draw_titre(core, 520, "jstokes");
		// 	ft_draw_titre(core, 620, "volyvar-");
		// }
		SDL_UpdateWindowSurface(core->window);
	}
	// SDL_UpdateWindowSurface(core->window);
	// }
	return (0);
}