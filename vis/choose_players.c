/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:37:16 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/08 19:37:18 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl2.h"

int		ft_find_str_players(t_core *core, char **str)
{
	char *str1;
	char *str2;

	str1 = ft_itoa(core->number_players);
	str2 = ft_strjoin("Choose ", str1);
	ft_strdel(&str1);
	*str = ft_strjoin(str2, " Avatar(s):");
	ft_strdel(&str2);
	return (0);
}

int		ft_create_theme_players(t_core *core)
{
	core->theme->rect0.x = 450;
	core->theme->rect0.y = 200;
	core->theme->rect0.w = 150;
	core->theme->rect0.h = 150;

	core->theme->rect1.x = 450;
	core->theme->rect1.y = 600;
	core->theme->rect1.w = 150;
	core->theme->rect1.h = 150;

	core->theme->rect2.x = 1200;
	core->theme->rect2.y = 200;
	core->theme->rect2.w = 150;
	core->theme->rect2.h = 150;

	core->theme->rect3.x = 1200;
	core->theme->rect3.y = 600;
	core->theme->rect3.w = 150;
	core->theme->rect3.h = 150;
	return (0);
}

int		ft_clear_fon(t_core *core)
{
	SDL_FillRect(core->screenSurface, &(core->theme->rect0), 0x2f7190);
	SDL_FillRect(core->screenSurface, &(core->theme->rect1), 0x2f7190);
	SDL_FillRect(core->screenSurface, &(core->theme->rect2), 0x2f7190);
	SDL_FillRect(core->screenSurface, &(core->theme->rect3), 0x2f7190);
	return (0);
}

int		ft_present_players(t_core *core)
{
	ft_clear_fon(core);
	// if (core->number_theme == 1)
	// {
		// printf("theme 1\n");
		if (core->players_status[0] == 0)
			SDL_BlitSurface(core->players->pl1_sh, NULL, core->screenSurface, &(core->theme->rect0));
		else
			SDL_BlitSurface(core->players->pl1, NULL, core->screenSurface, &(core->theme->rect0));
		// SDL_BlitSurface(core->image_surface, NULL, core->screenSurface, &(core->theme->rect0));
		// SDL_FreeSurface(core->image_surface);

		if (core->players_status[1] == 0)
			SDL_BlitSurface(core->players->pl2_sh, NULL, core->screenSurface, &(core->theme->rect1));
		else
			SDL_BlitSurface(core->players->pl2, NULL, core->screenSurface, &(core->theme->rect1));
		// SDL_BlitSurface(core->image_surface, NULL, core->screenSurface, &(core->theme->rect1));
		// SDL_FreeSurface(core->image_surface);

		if (core->players_status[2] == 0)
			SDL_BlitSurface(core->players->pl3_sh, NULL, core->screenSurface, &(core->theme->rect2));
		else
			SDL_BlitSurface(core->players->pl3, NULL, core->screenSurface, &(core->theme->rect2));
		// SDL_BlitSurface(core->image_surface, NULL, core->screenSurface, &(core->theme->rect2));
		// SDL_FreeSurface(core->image_surface);

		if (core->players_status[3] == 0)
			SDL_BlitSurface(core->players->pl4_sh, NULL, core->screenSurface, &(core->theme->rect3));
		else
			SDL_BlitSurface(core->players->pl4, NULL, core->screenSurface, &(core->theme->rect3));
		// SDL_BlitSurface(core->image_surface, NULL, core->screenSurface, &(core->theme->rect3));
		// SDL_FreeSurface(core->image_surface);
	// }
	SDL_UpdateWindowSurface(core->window);
	return (0);
}

int		ft_load_players(t_core *core)
{
	core->players = (t_players *)malloc(sizeof(t_players));
	ft_init_players(core);
	core->strelochka = SDL_LoadBMP("./game/winner/strelochka.bmp");
	core->winner_frame = SDL_LoadBMP("./game/winner/winner.bmp");
	// printf("number_theme=%d\n", core->number_theme);
	if (core->number_theme == 1)
	{
		core->players->pl1 = SDL_LoadBMP("./game/players_begin/t1_p1.bmp");
		core->players->pl1_sh = SDL_LoadBMP("/game/players_begin/t1_p1_sh.bmp");
		core->players->pl2 = SDL_LoadBMP("/game/players_begin/t1_p2.bmp");
		core->players->pl2_sh = SDL_LoadBMP("/game/players_begin/t1_p2_sh.bmp");
		core->players->pl3 = SDL_LoadBMP("/game/players_begin/t1_p3.bmp");
		core->players->pl3_sh = SDL_LoadBMP("/game/players_begin/t1_p3_sh.bmp");
		core->players->pl4 = SDL_LoadBMP("/game/players_begin/t1_p4.bmp");
		core->players->pl4_sh = SDL_LoadBMP("/game/players_begin/t1_p4_sh.bmp");
	}
	if (core->number_theme == 2)
	{
		core->players->pl1 = SDL_LoadBMP("./game/players_begin/t2_p1.bmp");
		core->players->pl1_sh = SDL_LoadBMP("./game/players_begin/t2_p1_sh.bmp");
		core->players->pl2 = SDL_LoadBMP("./game/players_begin/t2_p2.bmp");
		core->players->pl2_sh = SDL_LoadBMP("./game/players_begin/t2_p2_sh.bmp");
		core->players->pl3 = SDL_LoadBMP("./game/players_begin/t2_p3.bmp");
		core->players->pl3_sh = SDL_LoadBMP("./game/players_begin/t2_p3_sh.bmp");
		core->players->pl4 = SDL_LoadBMP("./game/players_begin/t2_p4.bmp");
		core->players->pl4_sh = SDL_LoadBMP("./game/players_begin/t2_p4_sh.bmp");
	}
	if (core->number_theme == 3)
	{
		core->players->pl1 = SDL_LoadBMP("./game/players_begin/t3_p1.bmp");
		core->players->pl1_sh = SDL_LoadBMP("./game/players_begin/t3_p1_sh.bmp");
		core->players->pl2 = SDL_LoadBMP("./game/players_begin/t3_p2.bmp");
		core->players->pl2_sh = SDL_LoadBMP("./game/players_begin/t3_p2_sh.bmp");
		core->players->pl3 = SDL_LoadBMP("./game/players_begin/t3_p3.bmp");
		core->players->pl3_sh = SDL_LoadBMP("./game/players_begin/t3_p3_sh.bmp");
		core->players->pl4 = SDL_LoadBMP("./game/players_begin/t3_p4.bmp");
		core->players->pl4_sh = SDL_LoadBMP("./game/players_begin/t3_p4_sh.bmp");
	}
	return (0);
}

int ft_cmp_vm(t_core *core, t_vm *vm, int orig)
{
	if (ft_find_owner_col(core, 1, vm->max_pl) == orig)
		return (0);
	else if (ft_find_owner_col(core, 2, vm->max_pl) == orig)
		return (1);
	else if (ft_find_owner_col(core, 3, vm->max_pl) == orig)
		return (2);
	else if (ft_find_owner_col(core, 4, vm->max_pl) == orig)
		return (3);
	return (0);
}

void	ft_get_col(SDL_Color *col, int mycol)
{
	col->r = mycol / 0x10000;
	col->g = (mycol / 0x100) % 0x100;
	col->b = mycol % 0x100;
}

int		ft_load_players_info(t_core *core, t_vm *vm)
{
	// printf("stat\n");
	t_pl player;

	core->player_info = (t_player_info *)malloc(sizeof(t_player_info));
	ft_init_players_info(core);
	if (core->number_theme == 1)
	{
		if (core->players_status[0])
		{
			// printf("stat1\n");
			core->player_info->pl1_name = ft_strdup("    Knife    ");
			core->player_info->pl1_slogan = ft_strdup("Wish to kill you <3");
		}
		if (core->players_status[1])
		{
			core->player_info->pl2_name = ft_strdup("    BUD    ");
			core->player_info->pl2_slogan = ft_strdup("I LOVE BUD!!!");
		}
		if (core->players_status[2])
		{
			core->player_info->pl3_name = ft_strdup("    HEAD    ");
			core->player_info->pl3_slogan = ft_strdup("where is my head?");
		}
		if (core->players_status[3])
		{
			core->player_info->pl4_name = ft_strdup("  i-go-go  ");
			core->player_info->pl4_slogan = ft_strdup("i-go-go..shen'ki");
		}
		ft_get_col(&core->player_info->pl1_col, 0xff335c);//red
		ft_get_col(&core->player_info->pl2_col, 0xb57900);//yellow
		ft_get_col(&core->player_info->pl3_col, 0xba66ff);//violet
		ft_get_col(&core->player_info->pl4_col, 0x2effaf);//green
	}
	if (core->number_theme == 2)
	{
		if (core->players_status[0])
		{
			// printf("stat1\n");
			core->player_info->pl1_name = ft_strdup("     Don     ");
			core->player_info->pl1_slogan = ft_strdup("Let's build a wall!");
		}
		if (core->players_status[1])
		{
			core->player_info->pl2_name = ft_strdup("    Vovan    ");
			core->player_info->pl2_slogan = ft_strdup("Ona ytonyla");
		}
		if (core->players_status[2])
		{
			core->player_info->pl3_name = ft_strdup("    Kim 5+    ");
			core->player_info->pl3_slogan = ft_strdup("I love CoreWar");
		}
		if (core->players_status[3])
		{
			core->player_info->pl4_name = ft_strdup("    Homer    ");
			core->player_info->pl4_slogan = ft_strdup("    D'oh    ");
		}
		ft_get_col(&core->player_info->pl1_col, 0x4649bd);//blue
		ft_get_col(&core->player_info->pl2_col, 0x5526659);//green
		ft_get_col(&core->player_info->pl3_col, 0x521c59);//red
		ft_get_col(&core->player_info->pl4_col, 0x993366);//pink
	}
		if (core->number_theme == 3)
	{
		int *avatar;

		if (core->players_status[0])
		{
			// printf("ft_cmp_vm(core, vm, 0) %d\n", ft_cmp_vm(core, vm, 0));
			player = vm->player[ft_cmp_vm(core, vm, 1)];
			core->player_info->pl1_name = ft_strdup(player.name);
			core->player_info->pl1_slogan = ft_strdup(player.comment);
		}
		if (core->players_status[1])
		{
			// player = vm->player[ft_find_owner_col(core, vm, 1)];
			// printf("comm %s\n", player.comment);
			player = vm->player[ft_cmp_vm(core, vm, 2)];
			core->player_info->pl2_name = ft_strdup(player.name);
			core->player_info->pl2_slogan = ft_strdup(player.comment);
		}
		if (core->players_status[2])
		{
			player = vm->player[ft_cmp_vm(core, vm, 3)];
			core->player_info->pl3_name = ft_strdup(player.name);
			core->player_info->pl3_slogan = ft_strdup(player.comment);
		}
		if (core->players_status[3])
		{
			// printf("ft_cmp_vm(core, vm, 3) %d\n", ft_cmp_vm(core, vm, 3));
			player = vm->player[ft_cmp_vm(core, vm, 4)];
			core->player_info->pl4_name = ft_strdup(player.name);
			core->player_info->pl4_slogan = ft_strdup(player.comment);
		}
		ft_get_col(&core->player_info->pl1_col, 0xe6e5e3);//green
		ft_get_col(&core->player_info->pl2_col, 0x89a9a9);//red
		ft_get_col(&core->player_info->pl3_col, 0x956249);//orange
		ft_get_col(&core->player_info->pl4_col, 0x6885be);//yellow
		//e6e5e3
	}
	return (0);
}

int		ft_players_fon(t_core *core)
{
	char *str;

	// printf("fon\n");
	core->players_status = (int *)malloc(sizeof(int) * 4);
	core->players_status[0] = 0;
	core->players_status[1] = 0;
	core->players_status[2] = 0;
	core->players_status[3] = 0;
	if (SDL_FillRect(core->screenSurface, &(core->theme->rect0), 0x2f7190) < 0)
			ft_error();
	str = NULL;
	ft_find_str_players(core, &str);
	ft_text_theme(core, str);
	ft_strdel(&str);
	ft_create_theme_players(core);
	ft_load_players(core);
	ft_present_players(core);
	
	SDL_UpdateWindowSurface(core->window);
	return (0);
}

int		ft_point_in_round(int x, int y, int r)
{
	if (r == 0)
	{
		// if ((x - 614) * (x - 614) + (y - 412) * (y - 412) <= 164 * 164)
		if (((float)x - 612.5) * ((float)x - 612.5) + ((float)y - 362.5) * ((float)y - 362.5) <= 162.5 * 162.5)
			return (1);
		else
			return (0);
	}
	if (r == 1)
	{
		if (((float)x - 612.5) * ((float)x - 612.5) + ((float)y - 762.5) * ((float)y - 762.5) <= 162.5 * 162.5)
			return (1);
		else
			return (0);
	}
	if (r == 2)
	{
		if (((float)x - 1362.5) * ((float)x - 1362.5) + ((float)y - 362.5) * ((float)y - 362.5) <= 162.5 * 162.5)
			return (1);
		else
			return (0);
	}
	if (r == 3)
	{
		if (((float)x - 1362.5) * ((float)x - 1362.5) + ((float)y - 762.5) * ((float)y - 762.5) <= 162.5 * 162.5)
			return (1);
		else
			return (0);
	}
	if (r == -1)
		return (1);
	return (0);
}

int		ft_fill_players_array(t_core *core, int a, int b)
{
	if (core->players_status[0] != 2)
		core->players_status[0] = a / 10;
	if (core->players_status[1] != 2)
		core->players_status[1] = a % 10;
	if (core->players_status[2] != 2)
		core->players_status[2] = b / 10;
	if (core->players_status[3] != 2)
		core->players_status[3] = b % 10;
	return (0);
}

int		ft_right_players_number(t_core *core)
{
	int i;
	int kol;

	i = 0;
	kol = 0;
	while (i < 4)
	{
		if (core->players_status[i] == 2)
			kol++;
		i++;
	}
	if (kol == core->number_players)
		return (1);
	else
		return (0);
}

int		ft_choose_players(t_core *core)
{
	static int fl;

	// printf("fl=%d\n", fl);
	if (fl == 0)
	{
		ft_players_fon(core);//цбрать чтобы не поторялось
		// ft_present_players(core);
		fl = 1;
	}
	while (1)
	{
		if (SDL_PollEvent(&(core->event)) != 0)
		{
			if ((core->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (core->event.type == SDL_QUIT)) //escape
			{
				// printf("QUIT\n");
				return (1);
			}
			// printf("fill\n");
			if (ft_right_players_number(core))
			{
				core->status = 2;
				// return (0);
				break;
			}
			if (ft_point_in_round(core->event.motion.x, core->event.motion.y, 0))
			{
				if (core->event.button.button == SDL_BUTTON_LEFT)
					core->players_status[0] = 2;

				ft_fill_players_array(core, 10, 0);
			}
			else if (ft_point_in_round(core->event.button.x, core->event.button.y, 1))
			{
				if (core->event.button.button == SDL_BUTTON_LEFT)
					core->players_status[1] = 2;

				ft_fill_players_array(core, 1, 0);
			}
			else if (ft_point_in_round(core->event.button.x, core->event.button.y, 2))
			{
				if (core->event.button.button == SDL_BUTTON_LEFT)
					core->players_status[2] = 2;

				ft_fill_players_array(core, 0, 10);
			}
			else if (ft_point_in_round(core->event.button.x, core->event.button.y, 3))
			{
				if (core->event.button.button == SDL_BUTTON_LEFT)
					core->players_status[3] = 2;

				ft_fill_players_array(core, 0, 1);
			}
			else if (ft_point_in_round(core->event.button.x, core->event.button.y, -1) == 1)
			{
				ft_fill_players_array(core, 0, 0);
			}
			ft_present_players(core);
		}
	}

	return (0);
}