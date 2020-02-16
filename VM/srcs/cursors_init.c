/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursors_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:53:03 by czena             #+#    #+#             */
/*   Updated: 2019/11/19 11:23:47 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

int			cursors_init(t_cursor **cursor, t_player *plr)
{
	int	i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (plr[i].connect > 0)
		{
			if (cursor_create(cursor, &plr[i]) == -1)
				return (-1);
		}
		i++;
	}
	return (1);
}
