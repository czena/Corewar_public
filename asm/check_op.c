/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:15:35 by nharra            #+#    #+#             */
/*   Updated: 2019/11/16 20:07:55 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static int	bad_count(const char *name)
{
	ft_printf("Invalid parameter count for instruction %s\n", name);
	return (-1);
}

static int	invalid_type(int i, int type, const char *instruction)
{
	ft_printf("Invalid parameter %d type ", i);
	if (type & T_REG)
		ft_putstr("register ");
	else if (type & T_DIR)
		ft_putstr("direct ");
	else if (type & T_IND)
		ft_putstr("inderect ");
	ft_putstr("for instruction ");
	ft_putstr(instruction);
	ft_putchar('\n');
	return (-1);
}

static int	check_count_op(const t_op *info, t_dlist **lex)
{
	int i;

	if (*lex == NULL || !((*lex)->tag & (T_REG | T_DIR | T_IND)))
		return (error_at_token(*lex));
	i = 0;
	while (i < info->count_op)
	{
		if (i != 0)
		{
			if (*lex == NULL || (*lex)->tag != T_SEP)
				return (bad_count(info->name));
			*lex = (*lex)->next;
		}
		if (*lex == NULL || !((*lex)->tag & (T_REG | T_DIR | T_IND)))
			return (error_at_token(*lex));
		if (!((*lex)->tag & info->type_params[i]))
			return (invalid_type(i, (*lex)->tag, info->name));
		++i;
		*lex = (*lex)->next;
	}
	return (0);
}

int			check_op(t_dlist **lex)
{
	char		*instruction;
	const t_op	*info;

	instruction = ((t_token *)((*lex)->content))->name;
	if ((info = get_info(instruction)) == NULL)
		return (error_at_token(*lex));
	*lex = (*lex)->next;
	if (check_count_op(info, lex) == -1)
		return (-1);
	return (0);
}
