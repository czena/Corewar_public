/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_cut.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:32:58 by czena             #+#    #+#             */
/*   Updated: 2019/11/19 18:44:24 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "corewar.h"

int		reg_read(t_cursor *cursor, char **arena)
{
	int res;

	res = cursor->reg[get_t_reg(arena, (cursor->position +
						cursor->byte_to_next) % MEM_SIZE)];
	cursor->byte_to_next += 1;
	return (res);
}

int		dir_read(t_cursor *cursor, char **arena, int dir_size)
{
	int res;

	res = get_t_dir(arena, (cursor->position + cursor->byte_to_next) %
					MEM_SIZE, dir_size);
	cursor->byte_to_next += dir_size;
	return (res);
}

int		ind_read(t_cursor *cursor, char **arena)
{
	int res;
	int ind;
	int address;

	ind = get_t_ind(arena, (cursor->position + cursor->byte_to_next) %
						MEM_SIZE);
	if (cursor->position + ind % IDX_MOD < 0)
		address = MEM_SIZE + cursor->position + ind % IDX_MOD;
	else
		address = cursor->position + ind % IDX_MOD;
	res = get_t_dir(arena, (address) % MEM_SIZE, 4);
	cursor->byte_to_next += 2;
	return (res);
}

int		init_type(char *type, t_cursor *cursor, char **arena, int dir_size)
{
	cursor->byte_to_next = 1;
	if (start_check_types(arena, cursor, dir_size) == -1)
		return (-1);
	*type = arena[0][(cursor->position + cursor->byte_to_next) % MEM_SIZE];
	cursor->byte_to_next += 1;
	return (1);
}
