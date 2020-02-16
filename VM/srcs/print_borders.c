/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:40:09 by czena             #+#    #+#             */
/*   Updated: 2019/11/20 00:18:32 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

static void		print_border_vertical(void)
{
	int i;

	i = 0;
	while (i < 68)
	{
		move(i, 0);
		printw("*");
		move(i, 195);
		printw("*");
		move(i, 246);
		printw("*");
		i++;
	}
}

void			print_border_horizontal(void)
{
	int i;

	i = 0;
	attron(COLOR_PAIR(10));
	while (i < 246)
	{
		move(0, i);
		printw("*");
		move(67, i);
		printw("*");
		i++;
	}
	print_border_vertical();
	attroff(COLOR_PAIR(10));
}
