/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <bsabre-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:26:18 by jmaynard          #+#    #+#             */
/*   Updated: 2020/02/13 20:10:41 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

inline static short	is_invalid_parameters(short types, int arg1, int arg2, \
		int reg)
{
	if ((types >> 2 & 3) != REG_CODE || \
			(types >> 4 & 3) == 0 || (types >> 6) == 0)
		return (1);
	if (reg > REG_NUMBER || reg < 1)
		return (1);
	if ((types >> 6) == REG_CODE && (arg1 > REG_NUMBER || arg1 < 1))
		return (1);
	if ((types >> 4 & 3) == REG_CODE && (arg2 > REG_NUMBER || arg2 < 1))
		return (1);
	return (0);
}

inline static void	log_or(size_t carriage_id, t_arg val, short log_flag)
{
	if (!log_flag)
		return ;
	fprint("P ");
	if (carriage_id < 1000)
		ft_putchar(' ');
	if (carriage_id < 100)
		ft_putchar(' ');
	if (carriage_id < 10)
		ft_putchar(' ');
	fprint("%d | or %d %d r%d\n", carriage_id, val.arg1, val.arg2, val.reg_nbr);
}

/*
**	OPERATION	OR (bitwise OR)
**	OPCODE		ARGUMENT_1			ARGUMENT_2			ARGUMENT_3
**	7			T_REG/T_DIR/T_IND	T_REG/T_DIR/T_IND	T_REG
**
**	Записывает в регистр заданный аргументом 3 результат побитового ИЛИ
**	аргументов 1 и 2. Меняет carry.
*/

void				operation_or(t_car *carriage, t_vm *vm)
{
	int		types;
	t_arg	val;

	types = vm->arena[(carriage->position + 1) % MEM_SIZE];
	carriage->step = 2 + get_arg_size(types >> 6, 6) + \
			get_arg_size(types >> 4 & 3, 6) + \
			get_arg_size(types >> 2 & 3, 6);
	val.reg_nbr = vm->arena[(carriage->position + 2 + \
			get_arg_size(types >> 6, 6) + get_arg_size(types >> 4 & 3, 6)) \
			% MEM_SIZE];
	val.arg1 = get_bytes(vm->arena, carriage->position + 2, \
			get_arg_size(types >> 6, 6), vm);
	val.arg2 = get_bytes(vm->arena, carriage->position + 2 + \
			get_arg_size(types >> 6, 6), get_arg_size(types >> 4 & 3, 6), vm);
	if (is_invalid_parameters(types, val.arg1, val.arg2, val.reg_nbr))
		return ;
	val.arg1 = get_argument(val.arg1, types >> 6, carriage, vm);
	val.arg2 = get_argument(val.arg2, types >> 4 & 3, carriage, vm);
	carriage->reg[val.reg_nbr - 1] = val.arg1 | val.arg2;
	carriage->carry = (carriage->reg[val.reg_nbr - 1]) ? 0 : 1;
	log_or(carriage->id, val, vm->flag & FLAG_LOG);
}
