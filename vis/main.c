/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:06:23 by volyvar-          #+#    #+#             */
/*   Updated: 2020/02/08 19:25:43 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl2.h"

int			main(int ac, char **av)
{
	t_vm	*vm;

	if (ac < 2 || ac > MAX_ARGS_NUMBER)
		print_usage(ac);
	if (!(vm = create_vm_struct(preliminary_parse_flags(ac, av))))
		error_exit(vm, "main - null ptr returned");
	initialize_all(ac, av, vm);
	introduce(vm->max_pl, vm);
	// if (vm->flag && FLAG_GRAF)
		main_vis(vm);
	// else
	// 	corewar(vm);
	free_exit(vm, NULL);
	return (0);
}

int main_vis(t_vm *vm)
{
	t_core *core;
	int quit;

	core = (t_core *)malloc(sizeof(t_core));
	ft_empty_core(core);
	ft_init_core(core, vm);
	
	quit = 1;
	ft_create_instruments(core);
	
	// while (quit)
	// { 
	// 	printf("while\n");
	// 		if ((core->event.key.keysym.sym == SDLK_ESCAPE) || (core->event.type == SDL_QUIT)) //escape
	// 			quit = 0;
			while ((quit) && core->status == 0)
			{
				if ((core->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (core->event.type == SDL_QUIT)) //escape
				{
					quit = 0;
					break;
				}
				if (ft_choose_theme(core) == 1)
					quit = 0;
			}
				if (quit)
					SDL_Delay(1000);
			while ((quit) && core->status == 1)
			{
				if ((core->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (core->event.type == SDL_QUIT)) //escape
				{
					quit = 0;
					break;
				}
				if (ft_choose_players(core) == 1)
					quit = 0;
			}
			ft_delete_players(core);
			if (quit)
				SDL_Delay(1000);
			while ((quit) && core->status == 2)
			{
				if ((core->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (core->event.type == SDL_QUIT)) //escape
				{
					quit = 0;
					break;
				}
				if (ft_game(core, vm) == 1)
					quit = 0;
			}
			if ((quit) && core->game)
				core->game->status = 8;
			while ((quit) && core->status == 3)
			{
				
				if ((core->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (core->event.type == SDL_QUIT)) //escape
				{
					quit = 0;
					break;
				}
				if (ft_end_game(core, vm) == 1)
					quit = 0;
			}
	// }
	ft_free_core(core);
	SDL_Quit();
	TTF_Quit();
	return (0);
}
