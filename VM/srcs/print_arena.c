
#include "corewar.h"
#include "op.h"

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

int			set_delta(t_cursor *cursor, int res, char **arena)
{
	int delta;

	delta = 0;
	if (arena[3][res] > 0)
		delta = 16;
	else if (check_cursor(cursor, res) > 0)
		delta = 5;
	else if (arena[2][res] > 0)
		delta = 10;
	else if (arena[1][res] == 0)
		delta = 21;
	if (arena[3][res] > 0)
		arena[3][res] -= 1;
	if (arena[2][res] > 0)
		arena[2][res] -= 1;
	return (delta);
}

void		print_arena2(t_cursor *cursor, char **arena)
{
	int		i;
	int		j;
	int		delta;
	int		res;

	i = 0;
	j = 0;
	delta = 0;
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
}

void		print_arena(char **arena, t_cursor *cursor, t_param *param,
						t_vis *vis)
{
	if (param->n_cycle + 1 <= 0)
		return ;
	check_gecth(vis);
	move(0, 0);
	printw("\n\n");
	print_arena2(cursor, arena);
	print_border_horizontal();
	print_status(param->plr, vis, param, cursor);
	print_speed(vis);
	print_last_period(param);
	while (vis->play == -1)
		check_gecth(vis);
	usleep(1000000 / vis->speed);
}
