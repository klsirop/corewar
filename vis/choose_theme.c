/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_theme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:10:20 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/08 15:09:11 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl2.h"

int		ft_create_theme_rect(t_core *core)
{
	//1600
	//1000
	core->theme->rect0.x = 0;
	core->theme->rect0.y = 0;
	core->theme->rect0.w = core->SCREEN_WIDTH;
	core->theme->rect0.h = core->SCREEN_HEIGHT;
	if (SDL_FillRect(core->screenSurface, &(core->theme->rect0), 0x2f7190) < 0)
		ft_error();
	core->theme->rect1.x = 700;
	core->theme->rect1.y = 300;
	core->theme->rect1.w = 600;
	core->theme->rect1.h = 100;
		
	core->theme->rect2.x = 700;
	core->theme->rect2.y = 500;
	core->theme->rect2.w = 600;
	core->theme->rect2.h = 100;

	core->theme->rect3.x = 700;
	core->theme->rect3.y = 700;
	core->theme->rect3.w = 600;
	core->theme->rect3.h = 100;
	return (0);
}

int		ft_create_theme_text(t_core *core)
{
	if (!(core->font_menu = TTF_OpenFont("./anu/anu.ttf", 288)))
		ft_error_ttf();
	if (!(core->font_field = TTF_OpenFont("18365.ttf", 288)))
		ft_error_ttf();
	if (!(core->font_name = TTF_OpenFont("./amatic/Amatic-Bold.ttf", 288)))
		ft_error_ttf();
	ft_text_theme(core, "Choose Theme:");
	ft_text_fight(core, 0);
	ft_text_inter(core, 0);
	ft_text_disco(core, 0);
	return (0);
}

int		ft_create_instruments(t_core *core)
{
	core->theme = (t_theme *)malloc(sizeof(t_theme));
	ft_create_theme_rect(core);
	ft_create_theme_text(core);
	SDL_UpdateWindowSurface(core->window);
	return (0);
}

int		ft_choose_theme(t_core *core)
{
	while (1)
	{
		if ((SDL_PollEvent(&(core->event)) != 0))
		{
			if ((core->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (core->event.type == SDL_QUIT)) //escape
			{
				
				return (1);
			}
			if (core->event.button.button == SDL_BUTTON_LEFT)
			{
				if ((core->event.button.x >= 700 && core->event.button.x <= 1300) &&
					(core->event.button.y >= 300 && core->event.button.y <= 400))
				{
					ft_text_fight(core, 1);
					ft_text_inter(core, 2);
					ft_text_disco(core, 2);
					SDL_UpdateWindowSurface(core->window);
					core->game_fon = 0x0b2852;
					core->number_theme = 1;
					core->status = 1;
					return (0);
				}
				else if ((core->event.button.x >= 700 && core->event.button.x <= 1300) &&
						 (core->event.button.y >= 500 && core->event.button.y <= 600))
				{
					ft_text_fight(core, 2);
					ft_text_inter(core, 1);
					ft_text_disco(core, 2);
					SDL_UpdateWindowSurface(core->window);
					core->game_fon = 0xb079b0;
					core->number_theme = 2;
					core->status = 1;
					return (0);
				}
				else if ((core->event.button.x >= 700 && core->event.button.x <= 1300) &&
						 (core->event.button.y >= 700 && core->event.button.y <= 800))
				{
					ft_text_fight(core, 2);
					ft_text_inter(core, 2);
					ft_text_disco(core, 1);
					SDL_UpdateWindowSurface(core->window);
					core->game_fon = 0xbabaff;
					//fadbc8
					//cac4b0
					core->number_theme = 3;
					core->status = 1;
					return (0);
				}
			}
		}
	}
	return (0);
}