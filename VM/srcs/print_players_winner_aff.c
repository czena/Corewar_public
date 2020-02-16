/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_players_winner_aff.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:15:01 by czena             #+#    #+#             */
/*   Updated: 2019/11/19 13:48:26 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			printf_aff(t_param *param)
{
	t_dlist *temp;

	temp = param->aff;
	while (temp)
	{
		ft_printf("Aff: %c\n", ((t_aff*)(temp->content))->c);
		temp = temp->next;
	}
}

void				print_introduction(t_player *plr, t_param *param)
{
	int i;

	if (param->visual_flag == 1)
		return ;
	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < MAX_PLAYERS && plr[i].connect > 0)
	{
		ft_printf("* Player %d, weighing %d bytes, \" %s\" (\"%s\") !\n",
				plr[i].n, plr[i].champ_size, plr[i].name, plr[i].comment);
		i++;
	}
}

void				print_winners(t_player *plr, t_param *param)
{
	if (param->visual_flag == 1)
	{
		ft_dlist_simple_del(&param->aff);
		return ;
	}
	if (param->aff_flag == 1)
		printf_aff(param);
	ft_printf("Contestant %d, \"%s\", has won !\n",
			plr[param->last - 1].n, plr[param->last - 1].name);
	ft_dlist_simple_del(&param->aff);
}
