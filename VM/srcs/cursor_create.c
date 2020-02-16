/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:00:07 by czena             #+#    #+#             */
/*   Updated: 2019/11/19 12:01:12 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

static int		last_id(t_cursor *cursor)
{
	int i;

	i = 0;
	while (cursor)
	{
		if (cursor->id > i)
			i = cursor->id;
		cursor = cursor->next;
	}
	return (i + 1);
}

static void		init_reg(int *reg, int n)
{
	int i;

	i = 1;
	reg[0] = -n;
	while (i < REG_NUMBER)
	{
		reg[i] = 0;
		i++;
	}
}

static void		create_dop(t_cursor *temp)
{
	temp->last_live = 0;
	temp->position = 0;
	temp->remained_op = 0;
	temp->op_code = 0;
}

int				cursor_create_empty(t_cursor **cursor)
{
	t_cursor *temp;

	cursor_to_bgn(cursor);
	if (!cursor)
		return (-1);
	if (!(temp = (t_cursor*)malloc(sizeof(t_cursor))))
		return (print_errors(12, "cursor_create", NULL));
	temp->byte_to_next = 0;
	temp->carry = 0;
	temp->id = last_id(*cursor);
	create_dop(temp);
	init_reg(temp->reg, 0);
	temp->position = 0;
	temp->prev = NULL;
	temp->next = NULL;
	if (!*cursor)
		*cursor = temp;
	else
	{
		temp->next = *cursor;
		(*cursor)->prev = temp;
		*cursor = temp;
	}
	return (1);
}

int				cursor_create(t_cursor **cursor, t_player *plr)
{
	t_cursor *temp;

	cursor_to_bgn(cursor);
	if (!cursor)
		return (-1);
	if (!(temp = (t_cursor*)malloc(sizeof(t_cursor))))
		return (print_errors(12, "cursor_create", NULL));
	temp->creator = plr->n;
	temp->byte_to_next = 0;
	temp->carry = 0;
	temp->id = last_id(*cursor);
	create_dop(temp);
	init_reg(temp->reg, plr->n);
	temp->position = plr->start_pos;
	temp->prev = NULL;
	temp->next = NULL;
	if (!*cursor)
		*cursor = temp;
	else
	{
		temp->next = *cursor;
		(*cursor)->prev = temp;
		*cursor = temp;
	}
	return (1);
}
