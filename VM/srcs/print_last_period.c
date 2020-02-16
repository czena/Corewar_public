
#include "corewar.h"
#include "op.h"

static int		live_count(t_param *param)
{
	int		i;
	int		all_live;

	i = 0;
	all_live = 0;
	while (i < param->n_players)
	{
		all_live += param->plr[i].prev_live;
		++i;
	}
	return (all_live);
}

static void		print_last(t_param *param, int i, int k)
{
	while (param->plr[i].prev_live == 0)
		--i;
	attron(COLOR_PAIR(param->plr[i].n));
	while (k < 44)
	{
		printw("-");
		++k;
	}
	attroff(COLOR_PAIR(param->plr[i].n));
}

static void		print_status_line(t_param *param)
{
	int		i;
	int		j;
	int		k;
	int		all_live;

	i = -1;
	k = 0;
	if ((all_live = live_count(param)) == 0)
	{
		printw("--------------------------------------------");
		return ;
	}
	while (++i < param->n_players)
	{
		attron(COLOR_PAIR(param->plr[i].n));
		j = 0;
		while (j < (44 * param->plr[i].prev_live) / all_live)
		{
			printw("-");
			++j;
			++k;
		}
		attroff(COLOR_PAIR(param->plr[i].n));
	}
	print_last(param, MAX_ARGS_NUMBER - 1, k);
}

void			print_last_period(t_param *param)
{
	move(29, 198);
	printw("Live breakdown for last period :");
	move(30, 198);
	printw("[");
	print_status_line(param);
	printw("]");
}
