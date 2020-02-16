/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_getch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:40:09 by czena             #+#    #+#             */
/*   Updated: 2019/11/19 19:45:13 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

void		print_speed(t_vis *vis)
{
	move(3, 198);
	printw("Cycles/second limit: %d     ", vis->speed);
	move(4, 4);
}

void		check_gecth(t_vis *vis)
{
	char c;

	move(700, 0);
	while ((c = getch()) != -1)
	{
		if (c == ' ')
			vis->play *= -1;
		if (c == 'q')
			vis->speed -= 10;
		if (c == 'w')
			vis->speed -= 1;
		if (c == 'e')
			vis->speed += 1;
		if (c == 'r')
			vis->speed += 10;
		if (vis->speed < 1)
			vis->speed = 1;
		if (vis->speed > 200)
			vis->speed = 200;
		print_speed(vis);
	}
}
