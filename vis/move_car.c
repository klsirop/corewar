/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_car.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 18:46:35 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/03 15:54:02 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl2.h"

int		ft_move_car(t_core *core)
{
	//00 to 01
	// core->col = 0xff0000;
	// ft_draw_wall(core, 10);
	// SDL_Delay(50);
	// core->col = 0x0b2852;
	// ft_draw_wall(core, 10);
	// core->col = 0xff0000;
	// ft_draw_wall(core, 11);
	// SDL_Delay(50);
	// core->col = 0x0b2852;
	// ft_draw_wall(core, 11);
	core->col = 0xff0000;
	ft_draw_wall(core, 5);
	// ft_draw_wall(core, 12);
	// ft_draw_letter(core, 11);
	return (0);
}