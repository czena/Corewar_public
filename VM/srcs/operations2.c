/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:32:58 by czena             #+#    #+#             */
/*   Updated: 2019/11/20 08:08:20 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "corewar.h"

void	operation_live(t_cursor *cursor, t_param *param, char **arena)
{
	int i;

	cursor->last_live = param->n_cycle;
	param->n_live += 1;
	i = get_t_dir(arena, (cursor->position + 1) % MEM_SIZE, 4);
	if (i < 0 && i >= param->n_players * -1)
	{
		param->last = i * -1;
		param->plr[(i * -1) - 1].last_live = param->n_cycle + 1;
		arena[3][cursor->position] = 50;
	}
	cursor->position = (cursor->position + 4 + 1) % MEM_SIZE;
}

void	operation_ld(t_cursor *cursor, char **arena)
{
	int		res;
	char	type;

	res = 0;
	if (init_type(&type, cursor, arena, 4) == -1)
		return ;
	if (get_bin_num(type, 1) == 2)
		res = dir_read(cursor, arena, 4);
	else if (get_bin_num(type, 1) == 3)
		res = ind_read(cursor, arena);
	cursor->reg[get_t_reg(arena, (cursor->position + cursor->byte_to_next)
				% MEM_SIZE)] = res;
	cursor->byte_to_next += 1;
	cursor->carry = res == 0 ? 1 : 0;
	cursor->position = (cursor->position + cursor->byte_to_next) % MEM_SIZE;
}

void	operation_st(t_cursor *cursor, char **arena, t_param *param)
{
	char	type;
	int		reg_1;
	int		ind;

	if (init_type(&type, cursor, arena, 4) == -1)
		return ;
	reg_1 = reg_read(cursor, arena);
	if (get_bin_num(type, 2) == 1)
	{
		cursor->reg[get_t_reg(arena, (cursor->position
						+ cursor->byte_to_next) % MEM_SIZE)] = reg_1;
		cursor->byte_to_next += 1;
	}
	else if (get_bin_num(type, 2) == 3)
	{
		ind = get_t_ind(arena, (cursor->position
							+ cursor->byte_to_next) % MEM_SIZE);
		set_dir_arena(arena, (cursor->position
							+ ind % IDX_MOD) % MEM_SIZE, reg_1);
		set_dir_owner(cursor, arena, (cursor->position
							+ ind % IDX_MOD) % MEM_SIZE, param);
		cursor->byte_to_next += 2;
	}
	cursor->position = (cursor->position + cursor->byte_to_next) % MEM_SIZE;
}

void	operation_add(t_cursor *cursor, char **arena)
{
	unsigned int res;

	cursor->byte_to_next = 1;
	if (start_check_types(arena, cursor, 4) == -1)
		return ;
	cursor->byte_to_next += 1;
	res = cursor->reg[get_t_reg(arena, (cursor->position
					+ cursor->byte_to_next) % MEM_SIZE)];
	cursor->byte_to_next += 1;
	res += cursor->reg[get_t_reg(arena, (cursor->position
					+ cursor->byte_to_next) % MEM_SIZE)];
	cursor->byte_to_next += 1;
	cursor->reg[get_t_reg(arena, (cursor->position
					+ cursor->byte_to_next) % MEM_SIZE)] = res;
	cursor->byte_to_next += 1;
	cursor->position = (cursor->position + cursor->byte_to_next) % MEM_SIZE;
	cursor->carry = res == 0 ? 1 : 0;
}

void	operation_sub(t_cursor *cursor, char **arena)
{
	unsigned int res;

	cursor->byte_to_next = 1;
	if (start_check_types(arena, cursor, 4) == -1)
		return ;
	cursor->byte_to_next += 1;
	res = cursor->reg[get_t_reg(arena, (cursor->position
					+ cursor->byte_to_next) % MEM_SIZE)];
	cursor->byte_to_next += 1;
	res -= cursor->reg[get_t_reg(arena, (cursor->position
					+ cursor->byte_to_next) % MEM_SIZE)];
	cursor->byte_to_next += 1;
	cursor->reg[get_t_reg(arena, (cursor->position
					+ cursor->byte_to_next) % MEM_SIZE)] = res;
	cursor->byte_to_next += 1;
	cursor->position = (cursor->position + cursor->byte_to_next) % MEM_SIZE;
	cursor->carry = res == 0 ? 1 : 0;
}
