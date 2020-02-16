
#include "corewar.h"
#include "op.h"

void		new_param(t_param *param)
{
	param->cycles_to_die = CYCLE_TO_DIE;
	param->last = 0;
	param->n_check = 0;
	param->n_live = 0;
	param->n_cycle = 0;
	param->n_players = 0;
	param->aff = NULL;
	param->n_cycles_to_die = 0;
	param->aff_flag = -1;
	param->dump_flag = -1;
	param->visual_flag = -1;
}

void		init_param(t_param *param, t_player *plr, t_player *first)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS && plr[i].connect > 0)
		i++;
	param->last = i;
	param->plr = first;
	param->n_players = i;
}
