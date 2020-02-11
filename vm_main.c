/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:16:17 by bsabre-c          #+#    #+#             */
/*   Updated: 2020/02/11 20:59:25 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_vm	*create_vm_struct(short *tab)
{
	t_vm	*vm;

	if (!tab)
		error_exit(NULL, "create_vm_struct - empty ptr found");
	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		error_exit(NULL, "create_vm_struct - malloc (vm) returned null");
	vm->max_pl = tab[0];
	if (!(vm->player = (t_pl *)ft_memalloc(sizeof(t_pl) * vm->max_pl)))
		error_exit(vm, "create_vm_struct - malloc (player arr) returned null");
	if (!(vm->arena = (unsigned char *)ft_memalloc(sizeof(unsigned char) * \
			MEM_SIZE)))
		error_exit(vm, "create_vm_struct - malloc (arena) returned null");
	if (!(vm->arena_owner = (short *)ft_memalloc(sizeof(short) * MEM_SIZE)))
		error_exit(vm, "create_vm_struct - malloc (arena owner) returned null");
	vm->tab = tab;
	return (vm);
}

void	print_usage(int ac)
{
	if (ac < 2)
		ft_putstr("Too FEW parameters.\n");
	if (ac > MAX_ARGS_NUMBER)
		ft_putstr("Too MANY parameters.\n");
	ft_putstr("Usage: ./corewar [[-flag] ...] [[-n number ]champion] ...\n");
	ft_putstr("Flags:\n\t-graf\t\t: grafix mode\n");
	ft_putstr("\t-aff\t\t: Prints output from \"aff\" ");
	ft_putstr("(Default is to hide it)\n");
	ft_putstr("\t-v\t\t: Verbose (log) of all operations\n");
	ft_putstr("\t-n N <player>\t: Set current number as id to player\n");
	ft_putstr("\t-dump N \t: dumps at cycle N\n");
	ft_putstr("\t-colordump N \t: dumps in color at cycle N\n");
	ft_putstr("\t-infodump N \t: dumps with additional info at cycle N\n");
	ft_putstr("\t-fulldump N \t: dumps in color with additional info ");
	ft_putstr("at cycle N\n");
	exit(0);
}

void	introduce(short max_pl, t_vm *vm)
{
	short	nbr;
	t_pl	player;

	nbr = 0;
	ft_putstr("Introducing contestants...\n");
	while (nbr < max_pl)
	{
		player = vm->player[nbr];
		fprint("* Player %d, weighing %d bytes, ", nbr + 1, player.codesize);
		fprint("\"%s\" (\"%s\") !\n", player.name, player.comment);
		nbr++;
	}
}

int			main(int ac, char **av)
{
	t_vm	*vm;

	if (ac < 2 || ac > MAX_ARGS_NUMBER)
		print_usage(ac);
	if (!(vm = create_vm_struct(preliminary_parse_flags(ac, av))))
		error_exit(vm, "main - null ptr returned");
	initialize_all(ac, av, vm);
	introduce(vm->max_pl, vm);
	if (vm->flag && FLAG_GRAF)
		main_vis(vm);
	else
		corewar(vm);
	free_exit(vm, NULL);
	return (0);
}
