/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands_byte.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 20:09:20 by nharra            #+#    #+#             */
/*   Updated: 2019/11/17 15:11:56 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

static void		print_op(t_dlist **lex, const int fd, const t_op *op)
{
	static int		cur_byte = 0;
	int				i;
	int				byte_code;

	i = 0;
	while (i < op->count_op)
	{
		*lex = (*lex)->next;
		byte_code = ((t_token *)(*lex)->content)->byte_code;
		if ((*lex)->tag & T_IND)
		{
			print_short(byte_code, fd, &cur_byte);
		}
		else if ((*lex)->tag & T_DIR)
		{
			if (get_dir_size(op) == 2)
				print_short(byte_code, fd, &cur_byte);
			else
				print_int(byte_code, fd, &cur_byte);
		}
		else if ((*lex)->tag & T_REG)
			print_char(byte_code, fd, &cur_byte);
		++i;
		*lex = (*lex)->next;
	}
}

void			print_commands_byte(t_dlist *lex, const int fd)
{
	int				cur_byte;
	int				i;
	const t_op		*op;

	cur_byte = 0;
	while (lex)
	{
		if (lex->tag == T_INSTR)
		{
			print_char(((t_token *)lex->content)->byte_code, fd, &cur_byte);
			op = get_info(((t_token *)lex->content)->name);
			if (op->type_byte)
				print_char(((t_token *)lex->content)->types_op, fd, &cur_byte);
			i = 0;
			print_op(&lex, fd, op);
		}
		else
			lex = lex->next;
	}
}
