/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:16:10 by nharra            #+#    #+#             */
/*   Updated: 2019/11/18 17:15:51 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "disasm.h"

int			error(const char *str)
{
	ft_printf("%s\n", str);
	return (-1);
}

static int	get_type(const char *type, int i)
{
	int		k;

	k = (*type & (3 << (6 - 2 * i))) >> (6 - 2 * i);
	if (k == 3)
		++k;
	return (k);
}

static int	get_op(t_buf *buf, int type, const t_op *op, t_dlist **lex)
{
	if (type == T_REG)
	{
		if (read_ch(buf, lex, T_REG) == -1)
			return (error("Error reading REGISTOR"));
	}
	else if (type == T_IND)
	{
		if (read_short(buf, lex, T_IND) == -1)
			return (error("Error reading INDEX"));
	}
	else if (type == T_DIR)
	{
		if (read_dir(buf, get_dir_size(op), lex, T_DIR) == -1)
			return (error("Error reading DIRECT"));
	}
	else
		return (error("invalid arg in get_op"));
	return (0);
}

static int	create_ops(t_dlist **lex, t_buf *buf, const char *types,
			const t_op *op)
{
	int			i;
	int			code;

	i = 0;
	while (i < op->count_op)
	{
		if (types != NULL)
		{
			if (((code = get_type(types, i)) & op->type_params[i]) == 0)
				return (error("Invalid type in types_byte"));
			if (get_op(buf, code, op, lex) == -1)
				return (-1);
		}
		else
		{
			if (get_op(buf, op->type_params[i], op, lex) == -1)
				return (-1);
		}
		++i;
	}
	return (0);
}

int			create_token(t_buf *buf, t_dlist **lex)
{
	const t_op		*op;

	while (buf->i < buf->size)
	{
		if ((op = get_info_id(buf->buf[buf->i++])) == NULL)
		{
			ft_printf("INSTURCTION %d not found", buf->buf[buf->i - 1]);
			return (-1);
		}
		if (ft_dlist_push_link(lex, ft_strdup(op->name), T_INSTR) == NULL)
			return (error("Error in create element"));
		if (buf->i == buf->size && op->type_byte)
			return (error("No TYPE_BYTE"));
		if (op->type_byte)
		{
			if (create_ops(lex, buf, &(buf->buf[(++buf->i) - 1]), op) == -1)
				return (-1);
		}
		else
		{
			if (create_ops(lex, buf, NULL, op) == -1)
				return (-1);
		}
	}
	return (0);
}
