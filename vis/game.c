/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:49:37 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/08 19:19:12 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl2.h"

int		ft_draw_lines(t_core *core)
{
	SDL_Rect rect;
	
	// core->text_color.r = 0xac;
	// core->text_color.g = 0x75;
	// core->text_color.b = 0x4c;
	rect.x = 220;
	rect.y = 0;
	rect.w = 2;
	rect.h = core->SCREEN_HEIGHT;
	if (SDL_FillRect(core->screenSurface, &rect, 0x060b0d) < 0)
			ft_error();
	rect.x = 1780;
	if (SDL_FillRect(core->screenSurface, &rect, 0x060b0d) < 0)
			ft_error();
	rect.x = 220;
	rect.y = 960;//897
	rect.w = core->SCREEN_WIDTH - 440;
	rect.h = 2;
	if (SDL_FillRect(core->screenSurface, &rect, 0x060b0d) < 0)
			ft_error();
	return (0);
}

int		ft_put_players_name(t_core *core, SDL_Rect rect, int num, char *str)
{
	SDL_Rect new_rect;

	// printf("ok11\n");
	new_rect.x = rect.x - 35;//+30
	// printf("ok2\n");
	if (num % 2 != 0)
		new_rect.y = rect.y + 5 + 150;
	else
		new_rect.y = rect.y - 35;
	new_rect.w = 220;
	new_rect.h = 30;
	// printf("str=%s\n", str);
	// printf("ok3\n");
	// core->text_color.r = 0xf7;
	// core->text_color.g = 0x3a;
	// core->text_color.b = 0x18;
	if (num == 1)
		ft_eql_col(&core->text_color, core->player_info->pl1_col);
	if (num == 2)
		ft_eql_col(&core->text_color, core->player_info->pl2_col);
	if (num == 3)
		ft_eql_col(&core->text_color, core->player_info->pl3_col);
	if (num == 4)
		ft_eql_col(&core->text_color, core->player_info->pl4_col);
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, (const char *)str, core->text_color)))
			ft_error_ttf();
	// printf("ok4\n");
		SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &new_rect);
		SDL_FreeSurface(core->text_surface);
		core->text_surface = NULL;
	// printf("ok5\n");
	return (0);
}

int		ft_put_players(t_core *core)
{
	core->theme->rect0.x = 35;
	core->theme->rect0.y = 200;
	core->theme->rect0.w = 150;
	core->theme->rect0.h = 150;
	if (core->players_status[0])
	{
		SDL_BlitSurface(core->players->pl1, NULL, core->screenSurface, &(core->theme->rect0));
		// printf("ok1\n");
		ft_put_players_name(core, core->theme->rect0, 1, core->player_info->pl1_name);
		// printf("ok8\n");
	}

	core->theme->rect1.x = 35;
	core->theme->rect1.y = 600;
	core->theme->rect1.w = 150;
	core->theme->rect1.h = 150;
	if (core->players_status[1])
	{
		SDL_BlitSurface(core->players->pl2, NULL, core->screenSurface, &(core->theme->rect1));
		ft_put_players_name(core, core->theme->rect1, 2, core->player_info->pl2_name);
	}

	core->theme->rect2.x = 1815;
	core->theme->rect2.y = 200;
	core->theme->rect2.w = 150;
	core->theme->rect2.h = 150;
	if (core->players_status[2])
	{
		SDL_BlitSurface(core->players->pl3, NULL, core->screenSurface, &(core->theme->rect2));
		ft_put_players_name(core, core->theme->rect2, 3, core->player_info->pl3_name);
	}


	core->theme->rect3.x = 1815;
	core->theme->rect3.y = 600;
	core->theme->rect3.w = 150;
	core->theme->rect3.h = 150;
	if (core->players_status[3])
	{
		SDL_BlitSurface(core->players->pl4, NULL, core->screenSurface, &(core->theme->rect3));
		ft_put_players_name(core, core->theme->rect3, 4, core->player_info->pl4_name);
	}
	return (0);
}

int		ft_reload_players(t_core *core)
{
	if (core->number_theme == 1)
	{
		core->players->pl1 = SDL_LoadBMP("./game/players_game/t1_p1.bmp");
		core->players->pl2 = SDL_LoadBMP("./game/players_game/t1_p2.bmp");
		core->players->pl3 = SDL_LoadBMP("./game/players_game/t1_p3.bmp");
		core->players->pl4 = SDL_LoadBMP("./game/players_game/t1_p4.bmp");
	}
	if (core->number_theme == 2)
	{
		core->players->pl1 = SDL_LoadBMP("./game/players_game/t2_p1.bmp");
		core->players->pl2 = SDL_LoadBMP("./game/players_game/t2_p2.bmp");
		core->players->pl3 = SDL_LoadBMP("./game/players_game/t2_p3.bmp");
		core->players->pl4 = SDL_LoadBMP("./game/players_game/t2_p4.bmp");
	}
	if (core->number_theme == 3)
	{
		core->players->pl1 = SDL_LoadBMP("./game/players_game/t3_p1.bmp");
		core->players->pl2 = SDL_LoadBMP("./game/players_game/t3_p2.bmp");
		core->players->pl3 = SDL_LoadBMP("./game/players_game/t3_p3.bmp");
		core->players->pl4 = SDL_LoadBMP("./game/players_game/t3_p4.bmp");
	}
	return (0);
}

int		ft_put_defines(t_core *core, t_vm *vm)
{
	core->game->cycle = vm->cw->cycle;
	core->game->processes = 0;//
	core->game->cycle_to_die = vm->cw->cycles_to_die;
	core->game->cycle_delta = CYCLE_DELTA;//macros
	core->game->nbr_live = vm->cw->lives_for_cycle;//lives for cycle
	core->game->max_checks = MAX_CHECKS;//macros
	core->game->status = 1;
	return (0);
}

int		ft_draw_word(t_core *core, char *str, SDL_Rect rect0)
{
	if (core->number_theme == 1)
		ft_get_col(&core->text_color, 0xf53a18);
	if (core->number_theme == 2)
		ft_get_col(&core->text_color, 0x000000);
	if (core->number_theme == 3)
		ft_get_col(&core->text_color, 0x000000);
	printf("str=%s\n", str);
	if (!(core->text_surface = TTF_RenderText_Blended(core->font_menu, (const char *)str, core->text_color)))
		ft_error_ttf();
	printf("Astr=%s\n", str);
	SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &rect0);
	SDL_FreeSurface(core->text_surface);
	core->text_surface = NULL;
	return (0);
}

int		ft_draw_defines(t_core *core)
{
	SDL_Rect rect0;
	char *str;
	char *num;
	//f73a18
	core->text_color.r = 0xf7;
	core->text_color.g = 0x3a;
	core->text_color.b = 0x18;
	
	rect0.x = 555;
	rect0.y = 965;
	rect0.w = 200;
	rect0.h = 35;
	num = ft_itoa(core->game->cycle);
	str = ft_strjoin("Cycle: ", num);
	SDL_FillRect(core->screenSurface, &rect0, core->game_fon);
	ft_draw_word(core, str, rect0);
	ft_strdel(&str);
	ft_strdel(&num);

	// rect0.y = 955;
	// num = ft_itoa(core->game->processes);
	// str = ft_strjoin("Processes: ", num);
	// SDL_FillRect(core->screenSurface, &rect0, core->game_fon);
	// ft_draw_word(core, str, rect0);
	// ft_strdel(&str);
	// ft_strdel(&num);

	rect0.x = 780;
	// rect0.y = 905;
	num = ft_itoa(core->game->cycle_to_die);
	str = ft_strjoin("Cycle to die: ", num);
	SDL_FillRect(core->screenSurface, &rect0, core->game_fon);
	ft_draw_word(core, str, rect0);
	ft_strdel(&str);
	ft_strdel(&num);

	// rect0.y = 955;
	// num = ft_itoa(core->game->cycle_delta);
	// str = ft_strjoin("Cycle delta: ", num);
	// SDL_FillRect(core->screenSurface, &rect0, core->game_fon);
	// ft_draw_word(core, str, rect0);
	// ft_strdel(&str);
	// ft_strdel(&num);

	rect0.x = 1015;
	// rect0.y = 905;
	num = ft_itoa(core->game->nbr_live);
	str = ft_strjoin("NBR live: ", num);
	SDL_FillRect(core->screenSurface, &rect0, core->game_fon);
	ft_draw_word(core, str, rect0);
	ft_strdel(&str);
	ft_strdel(&num);

	rect0.x = 1245;
	// rect0.y = 955;
	num = ft_itoa(core->game->max_checks);
	str = ft_strjoin("Max checks: ", num);
	SDL_FillRect(core->screenSurface, &rect0, core->game_fon);
	ft_draw_word(core, str, rect0);
	ft_strdel(&str);
	ft_strdel(&num);

	// if (core->game->status == 1)
	// {
	// 	rect0.x = 950;
	// 	rect0.y = 850;
	// 	rect0.w = 150;
	// 	rect0.h = 100;
	// 	SDL_FillRect(core->screenSurface, &rect0, core->game_fon);
	// 	ft_draw_word(core, "PLAY", rect0);
	// }
	// else
	// {
	// 	rect0.x = 950;
	// 	rect0.y = 850;
	// 	rect0.w = 150;
	// 	rect0.h = 100;
	// 	SDL_FillRect(core->screenSurface, &rect0, core->game_fon);
	// 	ft_draw_word(core, "PAUSED", rect0);
	// }
	return (0);
}

int		ft_nastya_ask(t_core *core)
{
	SDL_Rect rect0;
	
	//868fad 1a2139  1f5d2f  38515b  e0f2ff
	// core->text_color.r = 0xe0;
	// core->text_color.g = 0xf2;
	// core->text_color.b = 0xff;

	rect0.x = 1815;
	rect0.y = 760;
	rect0.w = 150;
	rect0.h = 5;
	if (SDL_FillRect(core->screenSurface, &rect0, 0x060b0d) < 0)
			ft_error();
	// if (!(core->text_surface = TTF_RenderText_Blended(core->font, (const char *)"01 23 45 67 89 09 87 65 43 21 23 45 67 89", core->text_color)))
	// 	ft_error_ttf();
	// SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &rect0);
	return (0);
}

static unsigned char	hex_char(int nbr)
{
	if (nbr == 0)
		return ('0');
	else
	{
		if (nbr > 0 && nbr < 10)
			return (nbr + '0');
		else if (nbr == 10)
			return ('a');
		else if (nbr == 11)
			return ('b');
		else if (nbr == 12)
			return ('c');
		else if (nbr == 13)
			return ('d');
		else if (nbr == 14)
			return ('e');
		else if (nbr == 15)
			return ('f');
		else
	{
		printf("%d\n", nbr);
		return ('-');
	}
			
	}
	return ('+');
}

unsigned char	*ft_strdup_bit(unsigned char *s1)
{
	size_t	len;
	size_t	i;
	size_t	k;
	unsigned char	*dst;

	len = 0;
	i = 0;
	k = 0;
	if (!(dst = (unsigned char *)malloc(sizeof(unsigned char) * (2 * MEM_SIZE + 1))))
		return (NULL);
	while (i < MEM_SIZE)
	{
		// printf("%s ", ft_itoa_base((int)s1[i], 16));
		dst[k] = hex_char((s1[i] >> 4));
		dst[k + 1] = hex_char((s1[i] & 0xF));
		k += 2;
		i++;
		// printf("strdup_bit : k %d k+1 %d\n", s1[i] >> 4, s1[i] & 0xF);
	}
	// printf("\n\n");
	dst[k] = '\0';
	return (dst);
}

int		ft_put_field(t_core *core, t_vm *vm)
{

	// core->game->field = "asdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytkrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdasdfghjklasdfghjksdfghjkdfghjkldfghjkldfghjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkdhjklytrertyklkjhgfghjklkjhgfdfghjklkjhgfdsdfghjklkjhgfdyjkd2345678uytrdfghjkkjhgfdertyuikjhtyui";
	SDL_Rect rect;

	if (core->game->prev_field)
	{
		free (core->game->prev_field);
		core->game->prev_field = NULL;
	}
	if (core->game->field)
	{
		core->game->prev_field = (unsigned char *)ft_strdup((char *)core->game->field);
	}
	if (core->game->field)
	{
		free (core->game->field);
		core->game->field = NULL;
	}
	rect.x = 250;
	rect.y = 0;
	rect.h = 800;
	rect.w = 1500;
	// SDL_FillRect(core->screenSurface, &rect, 0x000000);
	core->game->field = ft_strdup_bit(vm->arena);
	// printf("put field |%s|\n", core->game->field);
	return (0);
}

int		ft_game_fon(t_core *core, t_vm *vm)
{
	core->status_status = (int *)malloc(sizeof(int) * 4);
	core->status_status[0] = 0;
	core->status_status[1] = 0;
	core->status_status[2] = 0;
	core->status_status[3] = 0;
	core->theme->rect0.x = 0;
	core->theme->rect0.y = 0;
	core->theme->rect0.w = core->SCREEN_WIDTH;
	core->theme->rect0.h = core->SCREEN_HEIGHT;
	// printf("game fon\n");//0x2f7190
	//b5b5b5
	//1a2139
	if (SDL_FillRect(core->screenSurface, &(core->theme->rect0), core->game_fon) < 0)
			ft_error();
	core->game = (t_game *)malloc(sizeof(t_game));
	core->game->field = NULL;
	core->game->prev_field = NULL;
	core->game->posi = NULL;
	core->game->prev_owner = NULL;
	ft_load_players_info(core, vm);
	
	ft_draw_lines(core);
	ft_reload_players(core);
	ft_put_players(core);
	
	// ft_put_field(core, vm);
	ft_put_defines(core, vm);
	ft_draw_defines(core);
	// ft_nastya_ask(core);
	// ft_draw_field(core);
	// printf("\ndraw \n");
	ft_load_comments(core);
	ft_load_pic_com(core);

	// ft_draw_letter(core, 0, 0);
	// ft_draw_letter(core, 1, 0);
	// ft_draw_letter(core, 2, 0);
	// ft_draw_letter(core, 3, 0);
	// ft_draw_letter(core, 10, 0);

	// ft_move_car(core);
	
	// ft_draw_letter(core, 0, 1);
	// ft_draw_letter(core, 1, 1);
	// ft_draw_letter(core, 2, 1);
	// ft_draw_letter(core, 3, 1);
	// ft_draw_letter(core, 10, 1);
	SDL_UpdateWindowSurface(core->window);
	return (0);
}

Uint32 my_callbackfunc(Uint32 interval, void *param)
{
	t_core *core;

	core = (t_core *)param;
	// printf("timer\n");
	ft_change_comment(core);
	return (interval);
}

int		ft_copy(short **mas1, short *mas2)
{
	int i;

	*mas1 = (short *)malloc(sizeof(short) * MEM_SIZE);
	i = 0;
	while (i < MEM_SIZE)
	{
		(*mas1)[i] = mas2[i];
		i++;
	}
	return (0);
}

int		ft_game(t_core *core, t_vm *vm)
{
	static int fl;
	int schet = 0;
	t_corewar	cw;
	int a;

	// printf("game\n");
	if (fl == 0)
	{
		cw = initialize_variables(vm);
		vm->cw = &cw;

		ft_game_fon(core, vm);
		fl = 1;
		ft_put_field(core, vm);
		ft_draw_field(core, vm, 0);
		ft_draw_carriet(core, vm);
	}
	a = 0;
	while (vm->car)
	{
		// ft_put_field(core, vm);
		// ft_draw_field(core);

		// printf("stat=%d\n", core->game->status);
		// if (core->game->status == 1)
		// {
			if ((core->game->status == 1) || (core->game->status == -1))
			{
				// printf("sStat=%d\n", core->game->status);
				if (core->game->status == 1)
				{
				if (core->game->prev_owner)
				{
					free(core->game->prev_owner);
				}
				ft_copy(&core->game->prev_owner, vm->arena_owner);
				}
				if (vm->flag & FLAG_DUMP && vm->dump <= cw.cycle)
					dump(vm);
				cw.cycle++;
				if (vm->flag & FLAG_LOG)
					fprint("It is now cycle %d\n", (int)cw.cycle);
				exe_carriages(vm);
				if (cw.cycle == cw.next_check || cw.cycles_to_die <= 0)
					cycles_to_die_check(vm);
			}

			if (core->game->status == 1)
			{
			ft_put_defines(core, vm);
			ft_draw_defines(core);
			}

			if (core->game->status == 1)
			{
			ft_put_field(core, vm);
			ft_draw_field(core, vm, 0);
			ft_draw_carriet(core, vm);
			}

			if (core->game->status == 1)
			{
				schet++;
				if (schet == 50)
				{
					ft_change_comment(core);
					schet = 0;
				}
			}
			if (SDL_PollEvent(&(core->event)) != 0)
			{
				
				if ((core->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (core->event.type == SDL_QUIT)) //escape
				{
					// printf("keysum %d\n", core->event.key.keysym.sym == SDLK_ESCAPE);
					// printf("event %d\n", (core->event.type == SDL_QUIT));
					return (1);
				}


				if (core->event.key.keysym.scancode == SDL_SCANCODE_F) //escape
					a = 1;
				if ((core->event.key.keysym.scancode == SDL_SCANCODE_U) && (a == 1)) //escape
					a = 2;
				if ((core->event.key.keysym.scancode == SDL_SCANCODE_N) && (a == 2)) //escape
					core->game->status = -1;



				if (core->game->status == 1)
				{
				if (ft_see_stat1(core, core->event.button.x, core->event.button.y, 1))
				{
					ft_fill_status_array(core, 10, 0);
				}
				else if (ft_see_stat1(core, core->event.button.x, core->event.button.y, 2))
				{
					ft_fill_status_array(core, 1, 0);
				}
				else if (ft_see_stat1(core, core->event.button.x, core->event.button.y, 3))
				{
					ft_fill_status_array(core, 0, 10);
				}
				else if (ft_see_stat1(core, core->event.button.x, core->event.button.y, 4))
				{
					ft_fill_status_array(core, 0, 1);
				}
				else
				{
					ft_fill_status_array(core, 0, 0);
				}
				ft_present_status(core);
				}
				if ((core->event.key.keysym.scancode == SDL_SCANCODE_SPACE && core->game->status == 1) && (core->game->status != -1))
				{
					// printf("keysum %d\n", core->event.key.keysym.sym == SDLK_SPACE);
					// printf("core->event.key.keysym.sym => %d\n", core->event.key.keysym.sym);
					// printf("SDLK_SPACE  %d\n", SDLK_SPACE);
					// printf("event %d\n", (core->event.type == SDL_QUIT));
					ft_draw_pause(core);
					core->game->status = 0;
					// core->event.key.keysym.sym = 0;
				}
				if ((core->event.key.keysym.scancode == SDL_SCANCODE_RETURN && core->game->status == 0) && (core->game->status != -1))
				{
					ft_redraw_pause(core, vm);
					core->game->status = 1;
				}
				
			}
			if (core->game->status != -1)
				SDL_UpdateWindowSurface(core->window);
		// }
	}
	if (!vm->car)
	{
		fprint("Contestant %d, \"%s\", has won !\n", cw.last_alive, \
			vm->player[cw.last_alive - 1].name);
		core->status = 3;
	}
	return (0);
}