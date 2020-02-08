/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:32:03 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/08 19:10:08 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl2.h"

int		ft_get_rect(SDL_Rect *rect, int flag)
{
	static int	i;
	
	if (flag == 1)
	{
		i = 0;
		return (0);
	}
		if (i == 192)
		{
			i = 0;
			rect->y += 15;//24
			rect->x = 228;
		}
		rect->x += 8;//8
		i++;
	return (0);
}

int		ft_get_symb(t_core *core, char **str, int flag)
{
	static int i;

	if (flag == 1)
	{
		i = 0;
		return (0);
	}
	if (!(*str))
		ft_strdel(str);
	*str = (char *)malloc(sizeof(char) * 2);
	(*str)[0] = (core->game->field)[i];
	// printf("|%c| ", (core->game->field)[i]);
	(*str)[1] = '\0';
	i++;
	return (0);
}

void	ft_eql_col(SDL_Color *col1, SDL_Color col2)
{
	col1->r = col2.r;
	col1->g = col2.g;
	col1->b = col2.b;
}

//core->players_status[0]
int ft_find_owner_col(t_core *core, short pl, short max_pl)
{
	int a;

	a = 0;
	if (pl == 0)
	{
		ft_get_col(&core->text_color, 0xb5b5b5);
		return (0);
	}
	if (max_pl == 4)
	{
		if (pl == 1)
			a = 1;
		if (pl == 2)
			a = 2;
		if (pl == 3)
			a = 3;
		if (pl == 4)
			a = 4;
	}
	if (max_pl == 1)
	{
		if (core->players_status[0])
			a = 1;
		if (core->players_status[1])
			a = 2;
		if (core->players_status[2])
			a = 3;
		if (core->players_status[3])
			a = 4;
	}
	if (max_pl == 2)
	{
		if (core->players_status[0] && (pl == 1))
			a = 1;
		else if (!core->players_status[0])
		{
			if (core->players_status[1] && (pl == 1))
				a = 2;
			else if (!core->players_status[1])
			{
				if (pl == 1)
					a = 3;
				if (pl == 2)
					a = 4;
			}
			else if (pl == 2)
			{
				if (core->players_status[2])
					a = 3;
				if (core->players_status[3])
					a = 4;
			}
		}
		else if (pl == 2)
		{
			if (core->players_status[1])
				a = 2;
			if (core->players_status[2])
				a = 3;
			if (core->players_status[3])
				a = 4;
		}
	}
	if (max_pl == 3)
	{
		// printf("ok\n");
		if (core->players_status[0] && (pl == 1))
			a = 1;
		else if (!core->players_status[0])
		{
			if (pl == 1)
				a = 2;
			if (pl == 2)
				a = 3;
			if (pl == 3)
				a = 4;
		}
		else if (core->players_status[1] && pl == 2)
			a = 2;
		else if (!core->players_status[1])
		{
			if (pl == 2)
				a = 3;
			if (pl == 3)
				a = 4;
		}
		else if (pl == 3)
		{
			if (core->players_status[2])
				a = 3;
			else if (core->players_status[3])
				a = 4;
		}
	}
	if (a == 1)
		ft_eql_col(&core->text_color, core->player_info->pl1_col);
	else if (a == 2)
		ft_eql_col(&core->text_color, core->player_info->pl2_col);
	else if (a == 3)
		ft_eql_col(&core->text_color, core->player_info->pl3_col);
	else if (a == 4)
		ft_eql_col(&core->text_color, core->player_info->pl4_col);
	return (a);
}

// int ft_find_owner_col(t_core *core, t_vm *vm, int num)
// {
// 	int a1, a2, a3, a4;
// 	int a;

// 	if (vm->arena_owner[num] == 0)
// 	{
// 		ft_get_col(&core->text_color, 0xb5b5b5);
// 		return (0);
// 	}
// 	// printf("core->players_status0=%d\n", core->players_status[0]);
// 	// printf("core->players_status0=%d\n", core->players_status[1]);
// 	// printf("core->players_status0=%d\n", core->players_status[2]);
// 	// printf("core->players_status0=%d\n", core->players_status[3]);
// 	if (vm->max_pl == 4)
// 	{
// 	if (vm->arena_owner[num] == 1)
// 		ft_eql_col(&core->text_color, core->player_info->pl1_col);
// 	if (vm->arena_owner[num] == 2)
// 		ft_eql_col(&core->text_color, core->player_info->pl2_col);
// 	if (vm->arena_owner[num] == 3)
// 		ft_eql_col(&core->text_color, core->player_info->pl3_col);
// 	if (vm->arena_owner[num] == 4)
// 		ft_eql_col(&core->text_color, core->player_info->pl4_col);
// 	}
// 	if (vm->max_pl == 1)
// 	{
// 		if (core->players_status[0])
// 			ft_eql_col(&core->text_color, core->player_info->pl1_col);
// 		if (core->players_status[1])
// 			ft_eql_col(&core->text_color, core->player_info->pl2_col);
// 		if (core->players_status[2])
// 			ft_eql_col(&core->text_color, core->player_info->pl3_col);
// 		if (core->players_status[3])
// 			ft_eql_col(&core->text_color, core->player_info->pl4_col);
// 	}
// 	if (vm->max_pl == 2)
// 	{
// 		if (core->players_status[0] && (vm->arena_owner[num] == 1)) 
// 			ft_eql_col(&core->text_color, core->player_info->pl1_col);
// 		else if (!core->players_status[0])
// 		{
// 			if (core->players_status[1] && (vm->arena_owner[num] == 1))
// 				ft_eql_col(&core->text_color, core->player_info->pl2_col);
// 			else if (!core->players_status[1])
// 			{
// 				if (vm->arena_owner[num] == 1)
// 					ft_eql_col(&core->text_color, core->player_info->pl3_col);
// 				if (vm->arena_owner[num] == 2)
// 					ft_eql_col(&core->text_color, core->player_info->pl4_col);
// 			}
// 			else if (vm->arena_owner[num] == 2)
// 			{
// 				if (core->players_status[2])
// 					ft_eql_col(&core->text_color, core->player_info->pl3_col);
// 				if (core->players_status[3])
// 					ft_eql_col(&core->text_color, core->player_info->pl4_col);
// 			}
// 		}
// 		else if (vm->arena_owner[num] == 2)
// 		{
// 			if (core->players_status[1])
// 				ft_eql_col(&core->text_color, core->player_info->pl2_col);
// 			if (core->players_status[2])
// 				ft_eql_col(&core->text_color, core->player_info->pl3_col);
// 			if (core->players_status[3])
// 				ft_eql_col(&core->text_color, core->player_info->pl4_col);
// 		}
		
// 	}
// 	if (vm->max_pl == 3)
// 	{
// 		// printf("ok\n");
// 		if (core->players_status[0] && (vm->arena_owner[num] == 1)) 
// 			ft_eql_col(&core->text_color, core->player_info->pl1_col);
// 		else if (!core->players_status[0])
// 		{
// 			if (vm->arena_owner[num] == 1)
// 				ft_eql_col(&core->text_color, core->player_info->pl2_col);
// 			if (vm->arena_owner[num] == 2)
// 				ft_eql_col(&core->text_color, core->player_info->pl3_col);
// 			if (vm->arena_owner[num] == 3)
// 				ft_eql_col(&core->text_color, core->player_info->pl4_col);
// 		}
// 		else if (core->players_status[1] && vm->arena_owner[num] == 2)
// 			ft_eql_col(&core->text_color, core->player_info->pl2_col);
// 		else if (!core->players_status[1])
// 		{
// 			if (vm->arena_owner[num] == 2)
// 				ft_eql_col(&core->text_color, core->player_info->pl3_col);
// 			if (vm->arena_owner[num] == 3)
// 				ft_eql_col(&core->text_color, core->player_info->pl4_col);
// 		}
// 		else if (vm->arena_owner[num] == 3)
// 		{
// 			if (core->players_status[2])
// 				ft_eql_col(&core->text_color, core->player_info->pl3_col);
// 			else if (core->players_status[3])
// 				ft_eql_col(&core->text_color, core->player_info->pl4_col);
// 		}
// 	}
	
// 	return (0);
// }


int		ft_draw_field(t_core *core, t_vm *vm, int flag)
{
	SDL_Rect rect;
	char *str;
	int		num;
	int pr;
	
	// printf ("start\n");
	str = NULL;
	rect.x = 228;
	rect.y = 2;
	rect.w = 6;
	rect.h = 13;//22
	num = 0;
	pr = 0;
	// core->text_color.r = 0xb5;
	// core->text_color.g = 0xb5;
	// core->text_color.b = 0xb5;
	
	while (num < MEM_SIZE * 2)
	{
		ft_get_col(&core->text_color, 0xb5b5b5);
		core->text_color.a = 0;
		ft_find_owner_col(core, vm->arena_owner[num / 2], vm->max_pl);

		ft_get_rect(&rect, 0);
		ft_get_symb(core, &str, 0);

		// printf("%s ", str);
		// printf("rect.x=%d rect.y=%d", rect.x, rect.y);
		if ((core->game->prev_owner && (vm->arena_owner[num / 2] != core->game->prev_owner[num / 2])) || (flag == 1) || (!core->game->prev_field || (core->game->prev_field && core->game->field[num] != core->game->prev_field[num])))
		{
			if (vm->arena_owner[num / 2] == 0)
				core->text_color.a = 60;
			SDL_FillRect(core->screenSurface, &rect, core->game_fon);
			if (!(core->text_surface = TTF_RenderText_Blended(core->font_field, (const char *)str, core->text_color)))
				ft_error_ttf();
		//printf("ok\n");
			SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &rect);
			SDL_FreeSurface(core->text_surface);
			core->text_surface = NULL;
		}
		ft_strdel(&str);
		core->text_color.a = 0;
		ft_get_rect(&rect, 0);
		ft_get_symb(core, &str, 0);
		// printf("%s ", str);
		//printf("rect.x=%d rect.y=%d", rect.x, rect.y);
		if ((core->game->prev_owner && (vm->arena_owner[num / 2] != core->game->prev_owner[num / 2])) || (flag == 1) || (!core->game->prev_field || (core->game->prev_field && core->game->field[num + 1] != core->game->prev_field[num + 1])))
		{
			if (vm->arena_owner[num / 2] == 0)
				core->text_color.a = 60;
			SDL_FillRect(core->screenSurface, &rect, core->game_fon);
		if (!(core->text_surface = TTF_RenderText_Blended(core->font_field, (const char *)str, core->text_color)))
			ft_error_ttf();
		SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &rect);
		SDL_FreeSurface(core->text_surface);
		core->text_surface = NULL;
		}
		ft_strdel(&str);
		core->text_color.a = 0;
		num += 2;
		// if (num % 2 == 0)
		// if (pr % 2 == 0)
		// {
			ft_get_rect(&rect, 0);
			// if (!(core->text_surface = TTF_RenderText_Blended(core->font1, (const char *)" ", core->text_color)))
			// 	ft_error_ttf();
			// SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &rect);
		// }
		// pr++;
	}
	ft_get_symb(core, &str, 1);
	ft_get_rect(&rect, 1);

	return (0);
}