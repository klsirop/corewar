/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 12:45:36 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/08 19:09:44 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl2.h"

int		ft_is_ok(t_core *core, int i)
{
	if (core->players_status[i / 10 - 1])
		return (1);
	else
		return (0);
}

int		ft_next_comm(t_core *core)
{
	static int i;
	int j;

	j = 0;
	while (j == 0 || ft_is_ok(core, i) == 0)
	{
		j = 1;
		if (i == 0)
		{
			i = 11;
		}
		else
		{
			if (i / 10 < 4)
			{
				i = ((i / 10) + 1) * 10 + i % 10;
			}
			else
			{
				if (i % 10 == 3)
				{
					i = 11;
				}
				else
				{
					i = 10 + (i % 10) + 1;
				}
			}
		}
	}
	return (i);
}

int		ft_find_rect_sq(t_core *core, SDL_Rect *rect, int pl)
{
	rect->w = 150;
	rect->h = 160;
	if (pl == 1)
	{
		rect->x = core->theme->rect0.x;
		rect->y = core->theme->rect0.y - 10 - 150;//-7
	}
	if (pl == 2)
	{
		rect->x = core->theme->rect1.x;
		rect->y = core->theme->rect1.y + 10 + 150;//+5
	}
	if (pl == 3)
	{
		rect->x = core->theme->rect2.x;
		rect->y = core->theme->rect2.y - 10 - 150;//-7
	}
	if (pl == 4)
	{
		rect->x = core->theme->rect3.x;
		rect->y = core->theme->rect3.y + 10 + 150;//+5
	}
	return (0);
}

int		ft_find_rect_com(t_core *core, SDL_Rect *rect, int pl)
{
	rect->w = 140;
	rect->h = 120;
	if (pl == 1)
	{
		rect->x = core->theme->rect0.x;
		rect->y = core->theme->rect0.y - 5 - 100;
	}
	if (pl == 2)
	{
		rect->x = core->theme->rect1.x;
		rect->y = core->theme->rect1.y + 5 + 150 + 100;
	}
	if (pl == 3)
	{
		rect->x = core->theme->rect2.x;
		rect->y = core->theme->rect2.y - 5 - 100;
	}
	if (pl == 4)
	{
		rect->x = core->theme->rect3.x;
		rect->y = core->theme->rect3.y + 5 + 150 + 100;
	}
	return (0);
}

int		ft_prev_comm(int i, t_core *core)
{
	int j;

	j = 0;
	while (j == 0 || ft_is_ok(core, i) == 0)
	{
		j = 1;
		if (i / 10 > 1)
		{
			i = ((i / 10) - 1) * 10 + (i % 10);
		}
		else
		{
			if (i % 10 == 1)
			{
				i = 43;
			}
			else
			{
				i = 4 * 10 + (i % 10) - 1;
			}
		}
	}
	return (i);
}

int		ft_delete_prev_comm(t_core *core, int j)
{
	SDL_Rect rect;

	if (j / 10 == 1)
	{
		// printf("pl1\n");
		ft_find_rect_sq(core, &rect, 1);
		SDL_FillRect(core->screenSurface, &rect, core->game_fon);
	}
	if (j / 10 == 2)
	{
		// printf("pl2\n");
		ft_find_rect_sq(core, &rect, 2);
		SDL_FillRect(core->screenSurface, &rect, core->game_fon);
	}
	if (j / 10 == 3)
	{
		// printf("pl3\n");
		ft_find_rect_sq(core, &rect, 3);
		SDL_FillRect(core->screenSurface, &rect, core->game_fon);
	}
	if (j / 10 == 4)
	{
		// printf("pl4\n");
		ft_find_rect_sq(core, &rect, 4);
		SDL_FillRect(core->screenSurface, &rect, core->game_fon);
	}
	return (0);
}

char	*ft_cpy_comment(char **comment, int i)
{
	int j;
	int new_len;
	int len;
	char *tmp;
	char *t_tmp;

	len = ft_strlen(*comment);
	new_len = len - i - 1;
	tmp = (char *)malloc(sizeof(char) * (new_len + 1));
	t_tmp = (char *)malloc(sizeof(char) * (i + 2));
	j = 0;
	while (j < new_len)
	{
		tmp[j] = (*comment)[i + 1];
		j++;
		i++;
	}
	tmp[j] = '\0';

	j = 0;
	while (j < i + 1)
	{
		t_tmp[j] = (*comment)[j];
		j++;
	}
	t_tmp[j] = '\0';
	
	ft_strdel(comment);
	*comment = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (t_tmp);
}

int		ft_find_local_end(char **comment, t_core *core)
{
	int i;
	char *tmp;

	i = 0;
	while ((*comment) && (i < ft_strlen(*comment)))
	{
		if (((*comment)[i] == '\0') || ((*comment)[i] == ' ' && i >= 7 && i < 10) || (i == 10))
		{
			if ((*comment)[i] == '\0')
			{
				//
				// printf("comment=%s\n", *comment);
				ft_strdel(comment);
				return (0);
			}
			else
			{
				tmp = ft_cpy_comment(comment, i);
				//
				// printf("i=%d\n", i);
				// printf("tmp=%s\n", tmp);
				ft_strdel(&tmp);
			}
			i = 0;
		}
		i++;
	}
	return (0);
}

// int		ft_cut_comment(t_core *core, int i)
// {
// 	char *comment;
// 	SDL_Rect rect;
// 	int j;

// 	comment = ft_strdup(core->player_info->pl1_comm[(i % 10) - 1]);
// 	if (!comment)
// 		return (0);
// 	if (ft_strlen(comment) <= 10)
// 	{
// 		ft_find_rect_com(core, &rect, i / 10);
// 		if (!(core->text_surface = TTF_RenderText_Blended(core->font, core->player_info->pl1_comm[(i % 10) - 1], core->text_color)))
// 			ft_error_ttf();
// 		ft_strdel(&comment);
// 		return (0);
// 	}
// 	j = 0;
// 	ft_find_local_end(&comment, core);
// 	ft_strdel(&comment);
// 	return (0);
// }

int		ft_part_com(t_core *core, char **tmp, int i, char *comment)
{
	int j;
	int len;
	int ii;

	j = i * 10;
	len = 0;
	while (comment[j] != '\0' && j < (i * 10 + 10))
	{
		len++;
		j++;
	}
	*tmp = (char *)malloc(sizeof(char) * (len + 1));
	ii = 0;
	j = i * 10;
	while (ii < len)
	{
		(*tmp)[ii] = comment[j];
		ii++;
		j++;
	}
	(*tmp)[ii] = '\0';
	return (0);
}

int		ft_part_rect(SDL_Rect *r, SDL_Rect rect, int i, int count)
{
	(*r).y = (*r).y + (rect.h - 10) / count;
	return (0);
}

void	ft_rect_for_text(SDL_Rect * rect_text, SDL_Rect rect, int num)
{
	(*rect_text).w = 150 - 5 - 5;
	(*rect_text).h = 150 - 5 - 5;
	(*rect_text).x = rect.x + 5;
	if (num == 1 || num == 3)
	{
		(*rect_text).y = rect.y + 5;
	}
	if (num == 2 || num == 4)
	{
		(*rect_text).y = rect.y + 10 + 5;
	}
	
}

int		ft_new_hope(t_core *core, SDL_Rect rect, char *comment)// FOR TEXT IN COMMENTS
{
	int count;
	int i;
	char *tmp;
	SDL_Rect r;

	tmp = NULL;
	//count = rect.h / 10;
	count = ft_strlen(comment) / 10 + 1;
	if (ft_strlen(comment) % 10 == 0)
		count--;
	// printf("count=%d\n", count);
	r.x = rect.x + 3;
	r.y = 10 + rect.y - rect.h / count;
	//r.y = r.y - rect.h / count;
	r.w = rect.w - 10;
	r.h = (rect.h - 10) / count;
	while (i < count)
	{
		ft_part_com(core, &tmp, i, comment);
		// printf("tmp=%s\n", tmp);
		ft_part_rect(&r, rect, i, count);
		// printf("x=%d, y=%d, w=%d, h=%d\n", r.x, r.y, r.w, r.h);
		if (!(core->text_surface = TTF_RenderText_Blended(core->font_name, tmp, core->text_color)))
			ft_error_ttf();
		SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &(r));
		SDL_FreeSurface(core->text_surface);
		core->text_surface = NULL;
		ft_strdel(&tmp);
		i++;
	}
	return (0);
}

int		ft_change_comment(t_core *core)
{
	int i;
	int j;
	SDL_Rect rect;
	SDL_Rect rect_text;

	core->text_color.r = 0xf7;
	core->text_color.g = 0x3a;
	core->text_color.b = 0x18;
	i = ft_next_comm(core);
	j = ft_prev_comm(i, core);
	// printf("\t\t\t\t i=%d j=%d\n", i, j);
	// printf("start\n");
	ft_delete_prev_comm(core, j);
	// printf("delete prev com\n");
	// printf("i=%d\n", i);
	if (i / 10 == 1)
	{
		// printf("pl1\n");
		ft_find_rect_sq(core, &rect, 1);// FOR ALL PICTURE
		// printf("rect: %d %d %d %d\n", rect.x, rect.y, rect.w, rect.h);
		SDL_BlitSurface(core->player_info->pic_com1, NULL, core->screenSurface, &(rect));

		// ft_cut_comment(core, i);
		//ft_find_rect_com(core, &rect, 1);
		ft_eql_col(&core->text_color, core->player_info->pl1_col);
		// printf("before\n");
		ft_rect_for_text(&rect_text, rect, i / 10);
		// printf("after\n");
		// printf("new_text: %d %d %d %d\n", rect_text.x, rect_text.y, rect_text.w, rect_text.h);
		ft_new_hope(core, rect_text, core->player_info->pl1_comm[(i % 10) - 1]);
		// if (!(core->text_surface = TTF_RenderText_Blended(core->font, core->player_info->pl1_comm[(i % 10) - 1], core->text_color)))
		// 	ft_error_ttf();

		// SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &(rect));
	}
	if (i / 10 == 2)
	{
		// printf("pl2\n");
		ft_find_rect_sq(core, &rect, 2);
		SDL_BlitSurface(core->player_info->pic_com2, NULL, core->screenSurface, &(rect));
		ft_eql_col(&core->text_color, core->player_info->pl2_col);
		//ft_find_rect_com(core, &rect, 2);
		ft_rect_for_text(&rect_text, rect, i / 10);
		ft_new_hope(core, rect_text, core->player_info->pl2_comm[(i % 10) - 1]);
		// if (!(core->text_surface = TTF_RenderText_Blended(core->font, core->player_info->pl2_comm[i % 10 - 1], core->text_color)))
		// 	ft_error_ttf();
		// SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &(rect));
	}
	if (i / 10 == 3)
	{
		// printf("pl3\n");
		ft_find_rect_sq(core, &rect, 3);
		ft_eql_col(&core->text_color, core->player_info->pl3_col);
		SDL_BlitSurface(core->player_info->pic_com3, NULL, core->screenSurface, &(rect));
		ft_rect_for_text(&rect_text, rect, i / 10);
		ft_new_hope(core, rect_text, core->player_info->pl3_comm[(i % 10) - 1]);
		// ft_find_rect_com(core, &rect, 3);
		// if (!(core->text_surface = TTF_RenderText_Blended(core->font, core->player_info->pl3_comm[i % 10 - 1], core->text_color)))
		// 	ft_error_ttf();
		// SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &(rect));
	}
	if (i / 10 == 4)
	{
		// printf("pl4\n");
		ft_find_rect_sq(core, &rect, 4);
		SDL_BlitSurface(core->player_info->pic_com4, NULL, core->screenSurface, &(rect));
		ft_eql_col(&core->text_color, core->player_info->pl4_col);
		ft_rect_for_text(&rect_text, rect, i / 10);
		ft_new_hope(core, rect_text, core->player_info->pl4_comm[(i % 10) - 1]);
		// ft_find_rect_com(core, &rect, 4);
		// if (!(core->text_surface = TTF_RenderText_Blended(core->font, core->player_info->pl4_comm[i % 10 - 1], core->text_color)))
		// 	ft_error_ttf();
		// SDL_BlitScaled(core->text_surface, NULL, core->screenSurface, &(rect));
	}
	return (0);
}

int		ft_create_file_name_theme(char **file, int theme, int pl)
{
	char *str;
	char *str1;
	char *str2;

	str = ft_itoa(theme);
	str1 = ft_strjoin("theme", str);
	ft_strdel(&str);
	str = ft_itoa(pl);
	str2 = ft_strjoin(str1, "_pl");
	ft_strdel(&str1);
	str1 = ft_strjoin(str2, str);
	ft_strdel(&str);
	ft_strdel(&str2);
	str = ft_strjoin(str1, "_com");
	*file = ft_strjoin("./game/comments/", str);
	ft_strdel(&str);
	ft_strdel(&str1);
	return (0);
}

int		ft_load_i_comment(t_core *core, int theme, int pl)
{
	int fd;
	char *file_name;
	char *str;
	int tr;
	int i;

	ft_create_file_name_theme(&file_name, theme, pl);
	// printf("filename=%s\n", file_name);
	fd = open(file_name, O_RDONLY);
	i = 0;
	while ((tr = get_next_line(fd, &str)) > 0)
	{
		if (pl == 1)
			core->player_info->pl1_comm[i] = ft_strdup(str);
		else if (pl == 2)
			core->player_info->pl2_comm[i] = ft_strdup(str);
		else if (pl == 3)
			core->player_info->pl3_comm[i] = ft_strdup(str);
		else if (pl == 4)
			core->player_info->pl4_comm[i] = ft_strdup(str);
		i++;
		ft_strdel(&str);
	}
	ft_strdel(&file_name);
	close(fd);
	// core->player_info->pl1_comm = (char **)sizeof(char )
	return (0);
}

void	ft_init_arr(char **arr)
{
	int i;

	i = 0;
	while (i < 3)
	{
		arr[i] = NULL;
		i++;
	}
}

int		ft_load_comments(t_core *core)
{
	// printf("core->theme=%d\n", core->number_theme);
	if (core->number_theme == 1)
	{
		// printf("3ok\n");
		if (core->players_status[0])
		{
			// printf("3ok1\n");
			core->player_info->pl1_comm = (char **)malloc(sizeof(char *) * 3);
			ft_init_arr(core->player_info->pl1_comm);
			ft_load_i_comment(core, 1, 1);
			// printf("3ok2\n");
		}
		if (core->players_status[1])
		{
			core->player_info->pl2_comm = (char **)malloc(sizeof(char *) * 3);
			ft_init_arr(core->player_info->pl2_comm);
			ft_load_i_comment(core, 1, 2);
		}
		if (core->players_status[2])
		{
			core->player_info->pl3_comm = (char **)malloc(sizeof(char *) * 3);
			ft_init_arr(core->player_info->pl3_comm);
			ft_load_i_comment(core, 1, 3);
		}
		if (core->players_status[3])
		{
			core->player_info->pl4_comm = (char **)malloc(sizeof(char *) * 3);
			ft_init_arr(core->player_info->pl4_comm);
			ft_load_i_comment(core, 1, 4);
		}
	}

	if (core->number_theme == 2)
	{
		if (core->players_status[0])
		{
			core->player_info->pl1_comm = (char **)malloc(sizeof(char *) * 3);
			ft_init_arr(core->player_info->pl1_comm);
			ft_load_i_comment(core, 2, 1);
		}
		if (core->players_status[1])
		{
			core->player_info->pl2_comm = (char **)malloc(sizeof(char *) * 3);
			ft_init_arr(core->player_info->pl2_comm);
			ft_load_i_comment(core, 2, 2);
		}
		if (core->players_status[2])
		{
			core->player_info->pl3_comm = (char **)malloc(sizeof(char *) * 3);
			ft_init_arr(core->player_info->pl3_comm);
			ft_load_i_comment(core, 2, 3);
		}
		if (core->players_status[3])
		{
			core->player_info->pl4_comm = (char **)malloc(sizeof(char *) * 3);
			ft_init_arr(core->player_info->pl4_comm);
			ft_load_i_comment(core, 2, 4);
		}
	}

	if (core->number_theme == 3)
	{
		if (core->players_status[0])
		{
			core->player_info->pl1_comm = (char **)malloc(sizeof(char *) * 3);
			ft_init_arr(core->player_info->pl1_comm);
			ft_load_i_comment(core, 3, 1);
		}
		if (core->players_status[1])
		{
			core->player_info->pl2_comm = (char **)malloc(sizeof(char *) * 3);
			ft_init_arr(core->player_info->pl2_comm);
			ft_load_i_comment(core, 3, 2);
		}
		if (core->players_status[2])
		{
			core->player_info->pl3_comm = (char **)malloc(sizeof(char *) * 3);
			ft_init_arr(core->player_info->pl3_comm);
			ft_load_i_comment(core, 3, 3);
		}
		if (core->players_status[3])
		{
			core->player_info->pl4_comm = (char **)malloc(sizeof(char *) * 3);
			ft_init_arr(core->player_info->pl4_comm);
			ft_load_i_comment(core, 3, 4);
		}
	}
	return (0);
}

int		ft_load_pic_com(t_core *core)
{
	// core->player_info->pic_com1 = SDL_LoadBMP("./game/com_pic/kom1.bmp");
	// core->player_info->pic_com2 = SDL_LoadBMP("./game/com_pic/kom2.bmp");
	// core->player_info->pic_com3 = SDL_LoadBMP("./game/com_pic/kom3.bmp");
	// core->player_info->pic_com4 = SDL_LoadBMP("./game/com_pic/kom4.bmp");
	core->player_info->pic_com1 = SDL_LoadBMP("./game/com_pic/new_kom1.bmp");
	core->player_info->pic_com2 = SDL_LoadBMP("./game/com_pic/new_kom2.bmp");
	core->player_info->pic_com3 = SDL_LoadBMP("./game/com_pic/new_kom3.bmp");
	core->player_info->pic_com4 = SDL_LoadBMP("./game/com_pic/new_kom4.bmp");
	return (0);
}