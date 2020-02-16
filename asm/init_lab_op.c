/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lab_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:17:57 by nharra            #+#    #+#             */
/*   Updated: 2019/11/18 17:28:43 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

static void		init_dir(t_dlist *lex, int size_dir, t_dlist *beg, int cur_byte)
{
	int			size_4;
	short int	size_2;
	t_dlist		*label;

	label = ft_dlist_find(beg, ((t_token *)lex->content)->name, T_LAB,
	find_str);
	size_4 = ((t_token *)label->content)->n_byte;
	if (size_dir == 2)
	{
		size_2 = size_4;
		size_4 = size_2;
	}
	((t_token *)lex->content)->byte_code = size_4 - cur_byte;
}

static void		init_ind(t_dlist *lex, t_dlist *beg)
{
	short int	num;
	t_dlist		*label;

	label = ft_dlist_find(beg, ((t_token *)lex->content)->name, T_LAB,
	find_str);
	num = ((t_token *)label->content)->n_byte;
	((t_token *)lex->content)->byte_code = num;
}

static void		init_instr(t_dlist **lex, t_dlist *beg, int *cur_byte)
{
	const t_op		*op;
	int				size_dir;
	int				i;
	int				size_instr;

	op = get_info(((t_token *)(*lex)->content)->name);
	size_dir = get_dir_size(op);
	i = -1;
	size_instr = 0;
	while (++i < op->count_op)
	{
		*lex = (*lex)->next;
		if ((*lex)->tag & T_IND)
			size_instr += IND_SIZE;
		else if ((*lex)->tag & T_DIR)
			size_instr += size_dir;
		else if ((*lex)->tag & T_REG)
			size_instr += 1;
		if ((*lex)->tag == T_DIR_LAB)
			init_dir(*lex, size_dir, beg, *cur_byte);
		else if ((*lex)->tag == T_IND_LAB)
			init_ind(*lex, beg);
		*lex = (*lex)->next;
	}
	*cur_byte += size_instr + 1 + op->type_byte;
}

void			init_lab_op(t_dlist *lex)
{
	t_dlist *begin;
	int		cur_byte;

	cur_byte = 0;
	begin = lex;
	lex = lex->next->next;
	while (lex)
	{
		if (lex->tag == T_INSTR)
			init_instr(&lex, begin, &cur_byte);
		else
			lex = lex->next;
	}
}
