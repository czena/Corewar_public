/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:45:12 by czena             #+#    #+#             */
/*   Updated: 2019/11/19 13:43:15 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

static int	check_flag_dump(t_param *param, char **input, int *i, int n)
{
	*i += 1;
	if (*i >= n)
	{
		print_errors(3, input[*i - 1], NULL);
		return (-1);
	}
	if (check_num(input[*i], &param->dump_flag) == -1)
	{
		ft_printf("%d\n", param->dump_flag);
		print_errors(16, input[*i], NULL);
		return (-1);
	}
	*i += 1;
	return (1);
}

static int	check_flag_v(t_param *param, int *i)
{
	*i += 1;
	param->visual_flag = 1;
	return (1);
}

static int	check_flag_a(t_param *param, int *i)
{
	*i += 1;
	param->aff_flag = 1;
	return (1);
}

int			check_flags(t_param *param, char **input, int *i, int n)
{
	if (ft_strcmp(input[*i], "-n") == 0)
		return (1);
	if (ft_strcmp(input[*i], "-a") == 0)
		return (check_flag_a(param, i));
	if (ft_strcmp(input[*i], "-dump") == 0)
		return (check_flag_dump(param, input, i, n));
	if (ft_strcmp(input[*i], "-v") == 0)
		return (check_flag_v(param, i));
	return (0);
}
