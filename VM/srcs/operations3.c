/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:32:58 by czena             #+#    #+#             */
/*   Updated: 2019/11/19 19:10:45 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "corewar.h"

void	operation_and(t_cursor *cursor, char **arena)
{
	int		res;
	char	type;

	res = 0;
	if (init_type(&type, cursor, arena, 4) == -1)
		return ;
	if (get_bin_num(type, 1) == 1)
		res = reg_read(cursor, arena);
	else if (get_bin_num(type, 1) == 2)
		res = dir_read(cursor, arena, 4);
	else if (get_bin_num(type, 1) == 3)
		res = ind_read(cursor, arena);
	if (get_bin_num(type, 2) == 1)
		res &= reg_read(cursor, arena);
	else if (get_bin_num(type, 2) == 2)
		res &= dir_read(cursor, arena, 4);
	else if (get_bin_num(type, 2) == 3)
		res &= ind_read(cursor, arena);
	cursor->reg[get_t_reg(arena, (cursor->position
						+ cursor->byte_to_next) % MEM_SIZE)] = res;
	cursor->byte_to_next += 1;
	cursor->carry = res == 0 ? 1 : 0;
	cursor->position = (cursor->position + cursor->byte_to_next) % MEM_SIZE;
}

void	operation_or(t_cursor *cursor, char **arena)
{
	int		res;
	char	type;

	res = 0;
	if (init_type(&type, cursor, arena, 4) == -1)
		return ;
	if (get_bin_num(type, 1) == 1)
		res = reg_read(cursor, arena);
	else if (get_bin_num(type, 1) == 2)
		res = dir_read(cursor, arena, 4);
	else if (get_bin_num(type, 1) == 3)
		res = ind_read(cursor, arena);
	if (get_bin_num(type, 2) == 1)
		res |= reg_read(cursor, arena);
	else if (get_bin_num(type, 2) == 2)
		res |= dir_read(cursor, arena, 4);
	else if (get_bin_num(type, 2) == 3)
		res |= ind_read(cursor, arena);
	cursor->reg[get_t_reg(arena, (cursor->position
				+ cursor->byte_to_next) % MEM_SIZE)] = res;
	cursor->byte_to_next += 1;
	cursor->carry = res == 0 ? 1 : 0;
	cursor->position = (cursor->position + cursor->byte_to_next) % MEM_SIZE;
}

void	operation_xor(t_cursor *cursor, char **arena)
{
	int		res;
	char	type;

	res = 0;
	if (init_type(&type, cursor, arena, 4) == -1)
		return ;
	if (get_bin_num(type, 1) == 1)
		res = reg_read(cursor, arena);
	else if (get_bin_num(type, 1) == 2)
		res = dir_read(cursor, arena, 4);
	else if (get_bin_num(type, 1) == 3)
		res = ind_read(cursor, arena);
	if (get_bin_num(type, 2) == 1)
		res ^= reg_read(cursor, arena);
	else if (get_bin_num(type, 2) == 2)
		res ^= dir_read(cursor, arena, 4);
	else if (get_bin_num(type, 2) == 3)
		res ^= ind_read(cursor, arena);
	cursor->reg[get_t_reg(arena, (cursor->position
				+ cursor->byte_to_next) % MEM_SIZE)] = res;
	cursor->byte_to_next += 1;
	cursor->carry = res == 0 ? 1 : 0;
	cursor->position = (cursor->position + cursor->byte_to_next) % MEM_SIZE;
}

void	operation_zjmp(t_cursor *cursor, char **arena)
{
	int	i;
	int	dir_size;
	int	res;

	dir_size = 2;
	if (cursor->carry == 1)
	{
		i = get_t_dir(arena, (cursor->position + 1) % MEM_SIZE, 2);
		res = (cursor->position + i % IDX_MOD) % MEM_SIZE;
		if (res < 0)
			res = MEM_SIZE + res;
		cursor->position = res % MEM_SIZE;
	}
	else
	{
		res = ((cursor->position + dir_size + 1)) % MEM_SIZE;
		if (res < 0)
			res = MEM_SIZE + res;
		cursor->position = res % MEM_SIZE;
	}
}

void	operation_ldi(t_cursor *cursor, char **arena)
{
	int		res;
	char	type;
	int		address;

	res = 0;
	if (init_type(&type, cursor, arena, 2) == -1)
		return ;
	if (get_bin_num(type, 1) == 1)
		res = reg_read(cursor, arena);
	else if (get_bin_num(type, 1) == 2)
		res = dir_read(cursor, arena, 2);
	else if (get_bin_num(type, 1) == 3)
		res = ind_read(cursor, arena);
	if (get_bin_num(type, 2) == 1)
		res += reg_read(cursor, arena);
	else if (get_bin_num(type, 2) == 2)
		res += dir_read(cursor, arena, 2);
	if (cursor->position + (res % IDX_MOD) < 0)
		address = (cursor->position + (res % IDX_MOD) + MEM_SIZE) % MEM_SIZE;
	else
		address = (cursor->position + (res % IDX_MOD)) % MEM_SIZE;
	cursor->reg[get_t_reg(arena, (cursor->position + cursor->byte_to_next) %
		MEM_SIZE)] = get_t_dir(arena, address, 4);
	cursor->byte_to_next += 1;
	cursor->position = (cursor->position + cursor->byte_to_next) % MEM_SIZE;
}
