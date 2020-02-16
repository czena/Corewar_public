/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:20:04 by czena             #+#    #+#             */
/*   Updated: 2019/11/19 19:50:08 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

static	void	place_code(t_player *plr, char **arena, int start)
{
	int i;

	i = 0;
	plr->start_pos = start;
	while (i < plr->champ_size)
	{
		arena[0][start + i] = plr->code[i];
		arena[1][start + i] = plr->n;
		i++;
	}
}

static	void	place_players(t_player *plr, char **arena)
{
	int		n;
	int		start;
	int		delta;
	int		i;

	start = 0;
	i = 0;
	n = 0;
	while (n < MAX_PLAYERS && plr[n].connect > 0)
		n++;
	delta = MEM_SIZE / n;
	while (i < n)
	{
		place_code(&plr[i], arena, start);
		start += delta;
		i++;
	}
}

static void		delete_arena(char **arena, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		free(arena[j]);
		j++;
	}
	free(arena);
}

int				arena_init(t_player *plr, t_param *param)
{
	char	**arena;
	int		i;

	i = 0;
	if (!(arena = ft_memalloc(sizeof(char*) * 4)))
		return (print_errors(12, "arena_init", NULL));
	while (i < 4)
	{
		if (!(arena[i] = ft_memalloc(MEM_SIZE)))
		{
			delete_arena(arena, i);
			return (print_errors(12, "arena_init", NULL));
		}
		i++;
	}
	place_players(plr, arena);
	init_param(param, plr, &plr[0]);
	if (start_battle(plr, arena, param) == -1)
	{
		delete_arena(arena, 4);
		return (-1);
	}
	delete_arena(arena, 4);
	return (1);
}
