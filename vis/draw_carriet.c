/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_carriet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:01:32 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/08 18:47:10 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl2.h"

void	ft_reget_col(SDL_Color col, int *mycol)
{
	*mycol = col.r * 0x10000 + col.g * 0x100 + col.b;
}

int		ft_delete_list(t_lis *list, t_core *core, t_vm *vm)
{
	t_lis *tmp;

	tmp = list;
	while (list)
	{
		//ft_find_owner_col(core, vm, tmp->posi);
		ft_get_col(&core->text_color, core->game_fon);
		ft_reget_col(core->text_color, &core->col);
		ft_draw_wall(core, tmp->posi * 2);
		// ft_draw_wall(core, car->position * 2 + 1);

		ft_find_owner_col(core, vm->arena_owner[tmp->posi], vm->max_pl);
		ft_draw_letter(core, tmp->posi * 2, vm);

		tmp = list->next;
		free(list);
		list = tmp;
	}
	list = NULL;
	return (0);
}

// int		ft_redraw_carriets(t_core *core, t_vm *vm)
// {
// 	t_lis *tmp;

// 	tmp = core->game->posi;
// 	while (tmp)
// 	return (0);
// }

int		ft_draw_carriet(t_core *core, t_vm *vm)
{
	t_car *car;
	t_lis *tmp;

	if (core->game->posi)
	{
		//ft_redraw_carriets(core, vm);
		ft_delete_list(core->game->posi, core, vm);
		core->game->posi = NULL;
	}
	car = vm->car;
	while (car)
	{
		tmp = (t_lis *)malloc(sizeof(t_lis));
		tmp->posi = car->position;
		tmp->next = core->game->posi;
		core->game->posi = tmp;
		ft_find_owner_col(core, vm->arena_owner[car->position], vm->max_pl);
		ft_reget_col(core->text_color, &core->col);
		ft_draw_wall(core, car->position * 2);
		// ft_draw_wall(core, car->position * 2 + 1);

	//a5a5a5
		if (core->number_theme == 1)
			ft_get_col(&core->text_color, 0x000000);
		if (core->number_theme == 2)
			ft_get_col(&core->text_color, 0x989a9d);
		ft_draw_letter(core, car->position * 2, vm);
		//ft_draw_letter(core, car->position * 2 + 1);
		car = car->next;
	}
	return (0);
}