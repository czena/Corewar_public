/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:40:09 by czena             #+#    #+#             */
/*   Updated: 2019/11/20 00:45:01 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

void		create_colors(void)
{
	start_color();
	init_pair(1, 25, COLOR_BLACK);
	init_pair(2, 22, COLOR_BLACK);
	init_pair(3, 142, COLOR_BLACK);
	init_pair(4, 88, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, 8);
	init_pair(6, COLOR_BLACK, 25);
	init_pair(7, COLOR_BLACK, 22);
	init_pair(8, COLOR_BLACK, 142);
	init_pair(9, COLOR_BLACK, 88);
	init_pair(10, 8, 8);
	init_pair(11, 12, 0);
	init_pair(12, 10, 0);
	init_pair(13, 11, 0);
	init_pair(14, 9, 0);
	init_pair(16, 0, 8);
	init_pair(17, 15, 12);
	init_pair(18, 15, 10);
	init_pair(19, 15, 11);
	init_pair(20, 15, 9);
	init_pair(21, 8, 0);
}

static int	check_cursor(t_cursor *cursor, int n)
{
	while (cursor)
	{
		if (cursor->position == n)
			return (1);
		cursor = cursor->next;
	}
	return (0);
}

void	printf_cursors(t_cursor *cursor)
{
	while (cursor)
	{
		printw("id=%d, player=%d, last live = %ld, op = %d, position = %d, remind_op = %d, creator=%d\n", cursor->id, cursor->reg[0] * -1, cursor->last_live, cursor->op_code, cursor->position, cursor->remained_op, cursor->creator);
		cursor = cursor->next;
	}
}

void		str_add(int *n, char buffer[100000], char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		buffer[*n] = str[i];
		*n += 1;
		i++;
	}
}

int		set_delta(t_cursor *cursor, int res, char **arena)
{
	int delta;

	delta = 0;
	if (arena[3][res] > 0)
	{
		arena[3][res] -= 1;
		arena[2][res] -= 1;
		delta = 16;
	}
	else if (check_cursor(cursor, res) > 0)
	{
		arena[2][res] -= 1;
		delta = 5;
	}
	else if (arena[2][res] > 0)
	{
		arena[2][res] -= 1;
		delta = 10;
	}
	else if (arena[1][res] == 0)
		delta = 21;
	return (delta);
}

void		print_arena(char **arena, t_cursor *cursor, t_param *param, t_vis *vis)
{
	int		i;
	int		j;
	int		delta;
	int		res;

	i = 0;
	j = 0;
	delta = 0;
	if (param->n_cycle + 1 <= 0)
		return ;
	check_gecth(vis);
	move(0, 0);
	printw("\n\n");
	while (i < MEM_SIZE / 64)
	{
		j = 0;
		printw(" ");
		while (j < 64)
		{
			res = i * 64 + j;
			delta = set_delta(cursor, res, arena);
			printw(" ");
			attron(COLOR_PAIR((arena[1][res]) + delta));
			printw("%.2x", (unsigned char)arena[0][res]);
			attroff(COLOR_PAIR((arena[1][res]) + delta));
			j++;
		}
		printw("\n");
		i++;
	}
	print_border_horizontal();
	print_status(param->plr, vis, param, cursor);
	print_speed(vis);
	refresh();
	while (vis->play == -1)
		check_gecth(vis);
	usleep(1000000 / vis->speed);
}
