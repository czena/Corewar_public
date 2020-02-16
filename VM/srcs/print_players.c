/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:40:09 by czena             #+#    #+#             */
/*   Updated: 2019/11/19 20:15:01 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

static void	print_champ_name(char *str)
{
	int i;

	i = 0;
	while (i < 30 && str[i] !='\0')
	{
		if (str[i] == '\t' || str[i] == '\n')
		{
			printw("...");
			return ;
		}
		printw("%c", str[i]);
		i++;
	}
	if (str[i] !='\0')
		printw("...");
}

static void	print_last_live(int last, int y)
{
	move(y + 1, 200);
	printw("Last live: %d       ", last);
}

void		print_winner(t_player *plr, t_param *param)
{
	move(59, 198);
	printw("The winner is :");
	attron(COLOR_PAIR(plr[param->last - 1].n));
	print_champ_name(plr[param->last - 1].name);
	attroff(COLOR_PAIR(plr[param->last - 1].n));
	move(61, 198);
	printw("Press any key to finish");
}

void		print_players(t_player *plr, t_param *param)
{
	int i;

	i = 0;
	while (i < param->n_players)
	{
		move(9 + i * 3, 198);
		attron(COLOR_PAIR(plr[i].n));
		printw("Player %d: ", i + 1);
		print_champ_name(plr[i].name);
		attroff(COLOR_PAIR(plr[i].n));
		print_last_live(plr[i].last_live, 9 + i * 3);
		i++;
	}
}
