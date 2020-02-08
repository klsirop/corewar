int ft_find_owner_col(t_core *core, t_vm *vm, int num)
{
	int a1, a2, a3, a4;
	int a;

	if (vm->arena_owner[num] == 0)
	{
		ft_get_col(&core->text_color, 0xb5b5b5);
		return (0);
	}
	// printf("core->players_status0=%d\n", core->players_status[0]);
	// printf("core->players_status0=%d\n", core->players_status[1]);
	// printf("core->players_status0=%d\n", core->players_status[2]);
	// printf("core->players_status0=%d\n", core->players_status[3]);
	if (vm->max_pl == 4)
	{
	if (vm->arena_owner[num] == 1)
		ft_eql_col(&core->text_color, core->player_info->pl1_col);
	if (vm->arena_owner[num] == 2)
		ft_eql_col(&core->text_color, core->player_info->pl2_col);
	if (vm->arena_owner[num] == 3)
		ft_eql_col(&core->text_color, core->player_info->pl3_col);
	if (vm->arena_owner[num] == 4)
		ft_eql_col(&core->text_color, core->player_info->pl4_col);
	}
	if (vm->max_pl == 1)
	{
		if (core->players_status[0])
			ft_eql_col(&core->text_color, core->player_info->pl1_col);
		if (core->players_status[1])
			ft_eql_col(&core->text_color, core->player_info->pl2_col);
		if (core->players_status[2])
			ft_eql_col(&core->text_color, core->player_info->pl3_col);
		if (core->players_status[3])
			ft_eql_col(&core->text_color, core->player_info->pl4_col);
	}
	if (vm->max_pl == 2)
	{
		if (core->players_status[0] && (vm->arena_owner[num] == 1)) 
			ft_eql_col(&core->text_color, core->player_info->pl1_col);
		else if (!core->players_status[0])
		{
			if (core->players_status[1] && (vm->arena_owner[num] == 1))
				ft_eql_col(&core->text_color, core->player_info->pl2_col);
			else if (!core->players_status[1])
			{
				if (vm->arena_owner[num] == 1)
					ft_eql_col(&core->text_color, core->player_info->pl3_col);
				if (vm->arena_owner[num] == 2)
					ft_eql_col(&core->text_color, core->player_info->pl4_col);
			}
			else if (vm->arena_owner[num] == 2)
			{
				if (core->players_status[2])
					ft_eql_col(&core->text_color, core->player_info->pl3_col);
				if (core->players_status[3])
					ft_eql_col(&core->text_color, core->player_info->pl4_col);
			}
		}
		else if (vm->arena_owner[num] == 2)
		{
			if (core->players_status[1])
				ft_eql_col(&core->text_color, core->player_info->pl2_col);
			if (core->players_status[2])
				ft_eql_col(&core->text_color, core->player_info->pl3_col);
			if (core->players_status[3])
				ft_eql_col(&core->text_color, core->player_info->pl4_col);
		}
		
	}
	if (vm->max_pl == 3)
	{
		// printf("ok\n");
		if (core->players_status[0] && (vm->arena_owner[num] == 1)) 
			ft_eql_col(&core->text_color, core->player_info->pl1_col);
		else if (!core->players_status[0])
		{
			if (vm->arena_owner[num] == 1)
				ft_eql_col(&core->text_color, core->player_info->pl2_col);
			if (vm->arena_owner[num] == 2)
				ft_eql_col(&core->text_color, core->player_info->pl3_col);
			if (vm->arena_owner[num] == 3)
				ft_eql_col(&core->text_color, core->player_info->pl4_col);
		}
		else if (core->players_status[1] && vm->arena_owner[num] == 2)
			ft_eql_col(&core->text_color, core->player_info->pl2_col);
		else if (!core->players_status[1])
		{
			if (vm->arena_owner[num] == 2)
				ft_eql_col(&core->text_color, core->player_info->pl3_col);
			if (vm->arena_owner[num] == 3)
				ft_eql_col(&core->text_color, core->player_info->pl4_col);
		}
		else if (vm->arena_owner[num] == 3)
		{
			if (core->players_status[2])
				ft_eql_col(&core->text_color, core->player_info->pl3_col);
			else if (core->players_status[3])
				ft_eql_col(&core->text_color, core->player_info->pl4_col);
		}
	}
	
	return (0);
}