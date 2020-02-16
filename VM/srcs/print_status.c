
#include "corewar.h"
#include "op.h"

static void		print_params(t_param *param)
{
	move(36, 198);
	printw("CYCLE_TO_DIE: %d/%d             ", param->n_cycles_to_die,
			param->cycles_to_die);
	move(38, 198);
	printw("CYCLE_DELTA: %d", CYCLE_DELTA);
	move(40, 198);
	printw("NBR_LIVE: %d/%d", param->n_live, NBR_LIVE);
	move(42, 198);
	printw("MAX_CHECKS: %d/%d", param->n_check, MAX_CHECKS);
	move(52, 198);
	printw("HELP");
	move(54, 198);
	printw("*space*: pause/play");
	move(56, 198);
	printw("*q*: speed down 10");
	move(58, 198);
	printw("*w*: speed down 1");
	move(60, 198);
	printw("*e*: speed up 1");
	move(62, 198);
	printw("*r*: speed up 10");
}

static void		print_cursors(int cursors)
{
	move(7, 198);
	printw("Cursors: %d          ", cursors);
}

static void		print_cycle(int cycle)
{
	move(5, 198);
	printw("Cycle: %d          ", cycle);
}

static void		print_flag(int play)
{
	move(2, 198);
	if (play == -1)
		printw("** PAUSED ** ");
	else
		printw("** RUNNING **");
}

void			print_status(t_player *player, t_vis *vis,
						t_param *param, t_cursor *cursor)
{
	print_flag(vis->play);
	print_cycle(param->n_cycle);
	print_cursors(cursors_count(cursor));
	print_players(player, param);
	print_cur_period(param);
	print_params(param);
}
