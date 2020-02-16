
#include "corewar.h"
#include "op.h"

void			print_cursors(t_cursor *cursor)
{
	while (cursor)
	{
		ft_printf("id=%ld, op_code=%d, position=%d, remined_op=%ld\n",
		cursor->id, cursor->op_code, cursor->position, cursor->remained_op);
		cursor = cursor->next;
	}
	ft_printf("\n");
}

static void		check_live_cursors(t_param *param, t_cursor **cursor)
{
	while (*cursor)
	{
		if (param->cycles_to_die <= 0 || param->n_cycle - (*cursor)->last_live
			>= param->cycles_to_die)
		{
			cursor_delete(cursor);
			if (cursor)
				continue ;
		}
		if (!(*cursor) || !(*cursor)->next)
			break ;
		*cursor = (*cursor)->next;
	}
	cursor_to_bgn(cursor);
}

static void		check_live(t_param *param, t_cursor **cursor)
{
	int		i;

	if (param->visual_flag == 1)
		save_cur_live(param->plr);
	param->n_cycles_to_die = 0;
	check_live_cursors(param, cursor);
	param->n_check++;
	if (param->n_live >= NBR_LIVE || param->n_check == MAX_CHECKS)
	{
		param->cycles_to_die -= CYCLE_DELTA;
		param->n_check = 0;
	}
	param->n_live = 0;
	i = 0;
	while (i < param->n_players)
	{
		param->plr[i].cur_live = 0;
		++i;
	}
}

static void		battle(t_cursor **cursor, char **arena, t_param *param,
						WINDOW *w)
{
	static t_vis vis;

	vis.play = -1;
	vis.speed = 10;
	while (*cursor)
	{
		if (param->dump_flag == param->n_cycle && param->visual_flag == 0)
			return (print_dump(arena));
		if (param->visual_flag == 1)
			print_arena(arena, *cursor, param, &vis);
		cursor_to_bgn(cursor);
		check_cursor_is_ready(arena, cursor, param);
		cursor_to_bgn(cursor);
		param->n_cycles_to_die += 1;
		param->n_cycle += 1;
		if (param->n_cycles_to_die >= param->cycles_to_die)
			check_live(param, cursor);
	}
	if (param->visual_flag == 1)
	{
		print_arena(arena, *cursor, param, &vis);
		print_winner(param->plr, param);
		nodelay(w, 0);
		getch();
	}
}

int				start_battle(t_player *plr, char **arena, t_param *param)
{
	t_cursor	*cursor;
	WINDOW		*w;

	w = NULL;
	cursor = NULL;
	if (cursors_init(&cursor, plr) == -1)
		return (-1);
	print_introduction(plr, param);
	if (param->visual_flag == 1)
	{
		w = initscr();
		nodelay(w, 1);
		create_colors();
		curs_set(0);
		noecho();
	}
	battle(&cursor, arena, param, w);
	cursor_delete_all(&cursor);
	if (param->visual_flag == 1)
	{
		erase();
		endwin();
	}
	return (1);
}
