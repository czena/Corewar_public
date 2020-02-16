/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:32:58 by czena             #+#    #+#             */
/*   Updated: 2019/11/19 13:39:35 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "corewar.h"

int		start_check_types(char **arena, t_cursor *cursor, int dir_size)
{
	int size;

	if ((size = check_types(arena, cursor->op_code, dir_size,
				(cursor->position + cursor->byte_to_next) % MEM_SIZE)) > -1)
	{
		cursor->byte_to_next += 1;
		cursor->position = (cursor->position + size
							+ cursor->byte_to_next) % MEM_SIZE;
		return (-1);
	}
	return (1);
}

void	operation_aff(t_cursor *cursor, char **arena, t_param *param)
{
	int		res;
	char	type;
	t_aff	*aff;

	cursor->byte_to_next = 1;
	if (start_check_types(arena, cursor, 4) == -1)
		return ;
	type = arena[0][(cursor->position + cursor->byte_to_next) % MEM_SIZE];
	if (get_bin_num(type, 1) == 1)
	{
		cursor->byte_to_next += 1;
		res = cursor->reg[get_t_reg(arena, (cursor->position +
						cursor->byte_to_next) % MEM_SIZE)];
		aff = (t_aff*)malloc(sizeof(t_aff));
		aff->n = cursor->creator;
		aff->c = res;
		ft_dlist_push_link(&param->aff, aff, 0);
		cursor->byte_to_next += 1;
	}
	cursor->position = (cursor->position + cursor->byte_to_next) % MEM_SIZE;
}
