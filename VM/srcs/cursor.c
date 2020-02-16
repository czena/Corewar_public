/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:00:07 by czena             #+#    #+#             */
/*   Updated: 2019/11/19 12:01:08 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

int				cursors_count(t_cursor *cursor)
{
	int i;

	i = 0;
	while (cursor)
	{
		i++;
		cursor = cursor->next;
	}
	return (i);
}

void			cursor_delete_all(t_cursor **cursor)
{
	cursor_to_bgn(cursor);
	while (*cursor)
	{
		cursor_delete(cursor);
	}
}

void			cursor_to_bgn(t_cursor **cursor)
{
	if (!cursor || !*cursor)
		return ;
	while ((*cursor)->prev)
		*cursor = (*cursor)->prev;
}

void			cursor_delete(t_cursor **cursor)
{
	t_cursor *temp;

	temp = NULL;
	if (!(*cursor))
		return ;
	if ((*cursor)->prev)
	{
		(*cursor)->prev->next = (*cursor)->next;
		temp = (*cursor)->prev;
	}
	if ((*cursor)->next)
	{
		(*cursor)->next->prev = (*cursor)->prev;
		temp = (*cursor)->next;
	}
	free(*cursor);
	*cursor = temp;
}
