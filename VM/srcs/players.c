
#include "corewar.h"
#include "op.h"

void		players_init(t_player *plr)
{
	int i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		plr[i].connect = -1;
		plr[i].n = -1;
		plr[i].file = NULL;
		plr[i].name = NULL;
		plr[i].comment = NULL;
		plr[i].code = NULL;
		plr[i].champ_size = 0;
		plr[i].start_pos = -1;
		plr[i].last_live = 0;
		plr[i].cur_live = 0;
		plr[i].prev_live = 0;
		i++;
	}
}

void		players_delete(t_player *plr)
{
	int i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		free(plr[i].name);
		free(plr[i].comment);
		free(plr[i].code);
		i++;
	}
}

static void	sort_players(t_player *plr)
{
	int		i;
	int		temp_n;
	char	*temp;
	int		k;

	i = 0;
	while (i < MAX_PLAYERS && plr[i].connect != -1)
	{
		if (plr[i].n != i + 1)
		{
			k = i + 1;
			while (plr[k].connect == 1 && plr[k].n != i + 1)
				k++;
			temp_n = plr[i].n;
			temp = plr[i].file;
			plr[i].n = plr[k].n;
			plr[i].file = plr[k].file;
			plr[k].n = temp_n;
			plr[k].file = temp;
		}
		i++;
	}
	return ;
}

static int	set_id(t_player *plr, int *n, int max)
{
	int i;
	int j;

	i = 0;
	while (i < max)
	{
		if (plr[i].n > max)
			return (print_errors(8, ft_itoa(plr[i].n), NULL));
		if (plr[i].n == -1)
		{
			j = 0;
			while (j < MAX_PLAYERS)
			{
				if (n[j] == 0)
				{
					n[j] = 1;
					plr[i].n = j + 1;
					break ;
				}
				j++;
			}
		}
		i++;
	}
	return (1);
}

int			players_id(t_player *plr)
{
	int	i;
	int	n[MAX_PLAYERS];

	i = 0;
	if (plr[0].connect == -1)
		return (print_errors(17, NULL, NULL));
	ft_memset(&n, 0, MAX_PLAYERS * 4);
	while (i < MAX_PLAYERS && plr[i].connect > 0)
	{
		if (plr[i].n > 0 && n[plr[i].n - 1] == 0)
			n[plr[i].n - 1] = 1;
		else if (plr[i].n > 0)
		{
			print_errors(7, ft_itoa(plr[i].n), NULL);
			return (-1);
		}
		i++;
	}
	if (set_id(plr, &n[0], i) == -1)
		return (-1);
	sort_players(plr);
	return (1);
}
