/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:59:24 by nharra            #+#    #+#             */
/*   Updated: 2019/11/16 19:52:01 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static int	add_token(t_dlist **lst, char **line, t_point *point)
{
	if (check_endl(lst, line, point) || check_comment(lst, line, point)
	|| check_name(lst, line, point) || check_label(lst, line, point)
	|| check_direct_label(lst, line, point) || check_ind(lst, line, point)
	|| check_separator(lst, line, point) || check_registor(lst, line, point)
	|| check_direct(lst, line, point) || check_instruction(lst, line, point)
	|| check_ind_label(lst, line, point))
	{
		return (1);
	}
	return (-1);
}

int			add_tokens(t_dlist **lst, char *line)
{
	t_point point;

	point.col = 0;
	point.line = 0;
	while (*line)
	{
		point.col += skip_spaces(&line);
		if (*line == COMMENT_CHAR)
		{
			while (*(++line) && *line != '\n')
				point.col++;
			if (*line == '\0')
				break ;
		}
		if (add_token(lst, &line, &point) == -1)
		{
			ft_printf("Syntax error at [%d,%d]\n", point.line + 1,
			point.col + 1);
			ft_dlist_del(lst, delete_token);
			return (-1);
		}
	}
	return (0);
}
