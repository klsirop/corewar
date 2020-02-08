/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   see_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:51:40 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/08 19:12:03 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl2.h"

int		ft_see_stat1(t_core *core, int x, int y, int num)
{
	
	
	if (num == -1)
	{
		return (0);
	}
	core->text_color.r = 0xf7;
	core->text_color.g = 0x3a;
	core->text_color.b = 0x18;
	if (num == 1 && x >= core->theme->rect0.x + 30 && x <= core->theme->rect0.x + 150 - 30)
	{
		// printf("llll1\n");
		if (num % 2 != 0 && y >= core->theme->rect0.y + 150 + 5 && y <= core->theme->rect0.y + 150 + 30 + 5)
		{
			// printf("fffff1\n");
			return (1);
		}
	}
	else if (num == 2 && x >= core->theme->rect1.x + 30 && x <= core->theme->rect1.x + 150 - 30)
	{
		// printf("llll2\n");
		if (num % 2 == 0 && y >= core->theme->rect1.y - 5 - 30  && y <= core->theme->rect1.y - 5)
		{
			// printf("fffff2\n");
			return (1);
		}
	}
	else if (num == 3 && x >= core->theme->rect2.x + 30 && x <= core->theme->rect2.x + 150 - 30)
	{
		// printf("llll3\n");
		if (num % 2 != 0 && y >= core->theme->rect2.y + 150 + 5 && y <= core->theme->rect2.y + 150 + 30 + 5)
		{
			// printf("fffff3\n");
			return (1);
			
		}
	}
	else if (num == 4 && x >= core->theme->rect3.x + 30 && x <= core->theme->rect3.x + 150 - 30)
	{
		// printf("llll4\n");
		if (num % 2 == 0 && y >= core->theme->rect3.y - 5 - 30 && y <= core->theme->rect3.y - 5)
		{
			// printf("fffff4\n");
			return (1);
		}
	}

	return (0);
}

int		ft_fill_status_array(t_core *core, int a, int b)
{
	if (core->status_status[0] != 2)
		core->status_status[0] = a / 10;
	if (core->status_status[1] != 2)
		core->status_status[1] = a % 10;
	if (core->status_status[2] != 2)
		core->status_status[2] = b / 10;
	if (core->status_status[3] != 2)
		core->status_status[3] = b % 10;
	return (0);
}

int		ft_present_status(t_core *core)
{
	SDL_Rect rect;
	char *str;

	rect.x = core->theme->rect0.x - 35;
	rect.y = core->theme->rect0.y + 150 + 30 + 5 + 5;
	rect.w = 220;
	rect.h = 30;
	if (core->status_status[0] && core->players_status[0] && core->player_info->pl1_slogan[0] != '\0')
	{
		ft_eql_col(&core->text_color, core->player_info->pl1_col);
		if (ft_strlen(core->player_info->pl1_slogan) > 23)
		{
			str = (char *)malloc(sizeof(char) * 24);
			ft_strncpy(str, core->player_info->pl1_slogan, 23);
			str[23] = '\0';
			if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, (const char *)str, core->text_color)))
				ft_error_ttf();
			SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &rect);
			rect.y = core->theme->rect0.y + 150 + 30 + 5 + 5 + 30;
			if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, (const char *)core->player_info->pl1_slogan + 23, core->text_color)))
				ft_error_ttf();
			ft_strdel(&str);
		} 
		else if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, (const char *)core->player_info->pl1_slogan, core->text_color)))
			ft_error_ttf();
		SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &rect);
		SDL_FreeSurface(core->text_surface);
		core->text_surface = NULL;
	}
	else
	{
		SDL_FillRect(core->screenSurface, &rect, core->game_fon);
		if (core->players_status[0] && ft_strlen(core->player_info->pl1_slogan) > 23)
		{
			rect.y = core->theme->rect0.y + 150 + 30 + 5 + 5 + 30;
			SDL_FillRect(core->screenSurface, &rect, core->game_fon);
		}
	}
		
	rect.x = core->theme->rect2.x - 33;
	rect.y = core->theme->rect2.y + 150 + 30 + 5 + 5;
	// printf("%s\n", core->player_info->pl3_slogan);
	if (core->status_status[2] && core->players_status[2] && core->player_info->pl3_slogan[0] != '\0')
	{
		ft_eql_col(&core->text_color, core->player_info->pl3_col);
		if (ft_strlen(core->player_info->pl3_slogan) > 23)
		{
			str = (char *)malloc(sizeof(char) * 24);
			ft_strncpy(str, core->player_info->pl3_slogan, 23);
			str[23] = '\0';
			if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, (const char *)str, core->text_color)))
				ft_error_ttf();
			SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &rect);
			rect.y = core->theme->rect2.y + 150 + 30 + 5 + 5 + 30;
			if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, (const char *)core->player_info->pl3_slogan + 23, core->text_color)))
				ft_error_ttf();
			ft_strdel(&str);
		}
		
		else if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, (const char *)core->player_info->pl3_slogan, core->text_color)))
				ft_error_ttf();
		SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &rect);
		SDL_FreeSurface(core->text_surface);
		core->text_surface = NULL;
	}
	else
	{
		SDL_FillRect(core->screenSurface, &rect, core->game_fon);
		if (core->players_status[2] && ft_strlen(core->player_info->pl3_slogan) > 23)
		{
			rect.y = core->theme->rect2.y + 150 + 30 + 5 + 5 + 30;
			SDL_FillRect(core->screenSurface, &rect, core->game_fon);
		}
	}

	rect.x = core->theme->rect1.x - 35; 
	rect.y = core->theme->rect1.y - 30 - 30 - 5 - 5;
	if (core->status_status[1] && core->players_status[1] && core->player_info->pl2_slogan[0] != '\0')
	{
		ft_eql_col(&core->text_color, core->player_info->pl2_col);
		if (ft_strlen(core->player_info->pl2_slogan) > 23)
		{
			str = (char *)malloc(sizeof(char) * 24);
			ft_strncpy(str, core->player_info->pl2_slogan, 23);
			str[23] = '\0';
			if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, (const char *)core->player_info->pl2_slogan + 23, core->text_color)))
				ft_error_ttf();
			SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &rect);
			rect.y = core->theme->rect1.y - 30 - 30 - 5 - 5 - 30;
			if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, (const char *)str, core->text_color)))
				ft_error_ttf();
			ft_strdel(&str);
		}
		
		else if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, (const char *)core->player_info->pl2_slogan, core->text_color)))
				ft_error_ttf();
		SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &rect);
		SDL_FreeSurface(core->text_surface);
		core->text_surface = NULL;
	}
	else
	{
		SDL_FillRect(core->screenSurface, &rect, core->game_fon);
		if (core->players_status[1] && ft_strlen(core->player_info->pl2_slogan) > 23)
		{
			rect.y = core->theme->rect1.y - 30 - 30 - 5 - 5 - 30;
			SDL_FillRect(core->screenSurface, &rect, core->game_fon);
		}
	}

	rect.x = core->theme->rect3.x - 33;
	rect.y = core->theme->rect3.y - 30 - 30 - 5 - 5;
	if (core->status_status[3] && core->players_status[3] && core->player_info->pl4_slogan[0] != '\0')
	{
		ft_eql_col(&core->text_color, core->player_info->pl4_col);
		if (ft_strlen(core->player_info->pl4_slogan) > 23)
		{
			str = (char *)malloc(sizeof(char) * 24);
			ft_strncpy(str, core->player_info->pl4_slogan, 23);
			str[23] = '\0';
			if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, (const char *)core->player_info->pl4_slogan + 23, core->text_color)))
				ft_error_ttf();
			SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &rect);
			rect.y = core->theme->rect3.y - 30 - 30 - 5 - 5 - 30;
			if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, (const char *)str, core->text_color)))
				ft_error_ttf();
			ft_strdel(&str);
		}
		
		else if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, (const char *)core->player_info->pl4_slogan, core->text_color)))
				ft_error_ttf();
		SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &rect);
		SDL_FreeSurface(core->text_surface);
		core->text_surface = NULL;
	}
	else
	{
		SDL_FillRect(core->screenSurface, &rect, core->game_fon);
		if (core->players_status[3] && ft_strlen(core->player_info->pl4_slogan) > 23)
		{
			rect.y = core->theme->rect3.y - 30 - 30 - 5 - 5 - 30;
			SDL_FillRect(core->screenSurface, &rect, core->game_fon);
		}
	}
	return (0);
}