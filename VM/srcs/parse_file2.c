/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:45:12 by czena             #+#    #+#             */
/*   Updated: 2019/11/15 19:13:49 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

int		check_code(int fd, t_player *plr, char *str)
{
	char	*code;

	if (!(code = ft_strnew(plr->champ_size)))
		return (print_errors(12, "check_code", NULL));
	if (read(fd, code, plr->champ_size) != plr->champ_size)
		return (print_errors(15, str, NULL));
	code[plr->champ_size] = '\0';
	plr->code = code;
	return (1);
}
