/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:45:12 by czena             #+#    #+#             */
/*   Updated: 2019/11/19 14:30:05 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

int				check_num(char *str, int *num)
{
	int		n;
	long	res;

	n = 0;
	res = ft_atol(str);
	while (((*str) >= 2 && (*str) <= 32) && (*str) != 27)
		str++;
	if (((*str) == '+') && ft_isdigit((str[1])) == 1)
		str++;
	while (*str == '0')
		str++;
	while ((*str) != '\0')
	{
		if (ft_isdigit((*str)) == 0)
			return (-1);
		else
			n++;
		str++;
	}
	if (n > 11 || res > 2147483647 || res < 0)
		return (-1);
	*num = res;
	return (1);
}

int				check_flag_n(t_player *plr, char **input, int *i, int n)
{
	*i += 1;
	if (*i >= n)
	{
		print_errors(3, input[*i - 1], NULL);
		return (-1);
	}
	if (check_num(input[*i], &plr->n) == -1 || plr->n < 0 ||
		plr->n > 4)
	{
		print_errors(4, input[*i], NULL);
		return (-1);
	}
	*i += 1;
	if (*i >= n)
	{
		print_errors(5, input[*i - 2], input[*i - 1]);
		return (-1);
	}
	return (0);
}

static int		check_name(char *input, t_player *plr, int n)
{
	char	*temp;

	temp = input;
	temp = temp + ft_strlen(input) - 4;
	if (ft_strcmp(temp, ".cor") != 0)
	{
		print_errors(2, input, NULL);
		return (-1);
	}
	plr[n].file = input;
	plr[n].connect = 1;
	return (1);
}

int				check_input(char **input, int n, t_player *plr, t_param *param)
{
	int		i;
	int		n_plr;
	int		check;

	i = 0;
	n_plr = 0;
	while (i < n)
	{
		while ((check = check_flags(param, input, &i, n)) == 1)
		{
			if (i >= n)
				return (players_id(plr));
			if (ft_strcmp(input[i], "-n") == 0 && check_flag_n(&plr[n_plr],
								input, &i, n) == -1)
				return (-1);
		}
		if (n_plr == MAX_PLAYERS)
			return (print_errors(1, NULL, NULL));
		if (check == -1 || check_name(input[i], plr, n_plr) == -1)
			return (-1);
		i++;
		n_plr++;
	}
	return (players_id(plr));
}
