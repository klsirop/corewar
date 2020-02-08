/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:05:35 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/08 17:10:57 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl2.h"

void	ft_error()
{
	fprint("Error: %s\n", SDL_Error);
	exit(EXIT_FAILURE);
}

void	ft_error_ttf()
{
	fprint("Error: %s\n", TTF_GetError());
	exit(EXIT_FAILURE);
}

// void	ft_success(t_core *core)
// {
// 	fprint("suc% %s\n", SDL_Error);
// 	SDL_DestroyWindow(core->window);
// 	SDL_Quit();
// 	exit(EXIT_SUCCESS);
// }
