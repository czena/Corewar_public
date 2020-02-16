/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:42:06 by czena             #+#    #+#             */
/*   Updated: 2019/11/19 13:57:30 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

static void		print_usage(void)
{
	ft_putendl("Usage: ");
}

int				main(int argc, char **argv)
{
	t_player	plr[MAX_PLAYERS];
	t_param		param;

	players_init(plr);
	new_param(&param);
	if (argc == 1)
		print_usage();
	else
	{
		if (check_input(&argv[1], argc - 1, plr, &param) < 1 ||
			check_file(plr) == -1 ||
			arena_init(plr, &param) == -1)
		{
			players_delete(plr);
			return (-1);
		}
		print_winners(plr, &param);
		players_delete(plr);
	}
	return (1);
}
