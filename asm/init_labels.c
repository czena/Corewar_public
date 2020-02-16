/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_labels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:26:41 by nharra            #+#    #+#             */
/*   Updated: 2019/11/19 10:27:59 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

static int		init_reg(t_dlist *lex, int *cur_byte, int type_shift)
{
	((t_token *)lex->content)->n_byte = *cur_byte;
	*cur_byte += 1;
	((t_token *)lex->content)->byte_code =
	ft_atoi(((t_token *)lex->content)->name);
	return (type_shift);
}

static int		init_dir(t_dlist *lex, int size_dir, int *cur_byte,
				int type_shift)
{
	int			size_4;
	short int	size_2;

	((t_token *)lex->content)->n_byte = *cur_byte;
	*cur_byte += size_dir;
	if (lex->tag == T_DIR)
	{
		size_4 = ft_atoi(((t_token *)lex->content)->name);
		if (size_dir == 2)
		{
			size_2 = size_4;
			size_4 = size_2;
		}
		((t_token *)lex->content)->byte_code = size_4;
	}
	return (type_shift);
}

static int		init_ind(t_dlist *lex, int *cur_byte, int type_shift)
{
	short int	num;

	((t_token *)lex->content)->n_byte = *cur_byte;
	*cur_byte += 2;
	if (lex->tag == T_IND)
	{
		num = ft_atoi(((t_token *)lex->content)->name);
		((t_token *)lex->content)->byte_code = num;
	}
	return (type_shift);
}

static void		init_instr(t_dlist **lex, int *cur_byte)
{
	const t_op		*op;
	int				size_dir;
	int				i;
	int				*type;

	op = get_info(((t_token *)(*lex)->content)->name);
	size_dir = get_dir_size(op);
	((t_token *)(*lex)->content)->byte_code = op->id;
	((t_token *)(*lex)->content)->n_byte = *cur_byte;
	*cur_byte += op->type_byte + 1;
	type = &(((t_token *)(*lex)->content)->types_op);
	i = 0;
	while (i < op->count_op)
	{
		*lex = (*lex)->next;
		if ((*lex)->tag & T_REG)
			*type = *type | init_reg(*lex, cur_byte, REG_CODE << (6 - 2 * i));
		else if ((*lex)->tag & T_DIR)
			*type = *type | init_dir(*lex, size_dir, cur_byte,
			DIR_CODE << (6 - 2 * i));
		else if ((*lex)->tag & T_IND)
			*type = *type | init_ind(*lex, cur_byte, IND_CODE << (6 - 2 * i));
		++i;
		*lex = (*lex)->next;
	}
}

int				init_labels(t_dlist *lex)
{
	int		cur_byte;

	cur_byte = 0;
	lex = lex->next->next;
	while (lex)
	{
		if (lex->tag == T_LAB)
		{
			((t_token *)(lex->content))->n_byte = cur_byte;
			lex = lex->next;
		}
		else if (lex->tag == T_INSTR)
			init_instr(&lex, &cur_byte);
		else
			lex = lex->next;
	}
	return (cur_byte);
}
