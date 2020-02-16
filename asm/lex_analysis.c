/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_analysis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:01:31 by nharra            #+#    #+#             */
/*   Updated: 2019/11/19 11:00:08 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static void		error_at_token_2(t_dlist *lst)
{
	if (lst->tag == T_IND)
		ft_printf("INDEX %s\n", ((t_token *)lst->content)->name);
	else if (lst->tag == T_IND_LAB)
		ft_printf("INDEX_LABEL %s\n", ((t_token *)lst->content)->name);
	else if (lst->tag == T_LAB)
		ft_printf("LABEL %s\n", ((t_token *)lst->content)->name);
	else if (lst->tag == T_INSTR)
		ft_printf("INSTRUCTION %s\n", ((t_token *)lst->content)->name);
	else if (lst->tag == T_DIR_LAB)
		ft_printf("DIRECT_LABEL %s\n", ((t_token *)lst->content)->name);
	else if (lst->tag == T_SEP)
		ft_printf("SEPARATOR\n");
	else if (lst->tag == T_COM)
		ft_printf("COMMENT %s\n", ((t_token *)lst->content)->name);
	else if (lst->tag == T_NAME)
		ft_printf("NAME %s\n", ((t_token *)lst->content)->name);
}

int				error_at_token(t_dlist *lst)
{
	ft_printf("Syntax error at token [TOKEN] ");
	if (lst == NULL)
	{
		ft_putstr("EOF\n");
		return (-1);
	}
	ft_printf("[%03d:%03d] ", ((t_token *)lst->content)->line + 1,
	((t_token *)lst->content)->col + 1);
	if (lst->tag == T_ENDL)
		ft_printf("%s\n", "ENDLINE");
	else if (lst->tag == T_REG)
		ft_printf("REGISTER %s\n", ((t_token *)lst->content)->name);
	else if (lst->tag == T_DIR)
		ft_printf("DIRECT %s\n", ((t_token *)lst->content)->name);
	else
		error_at_token_2(lst);
	return (-1);
}

static int		check_last(t_dlist *lex)
{
	if (lex == NULL)
		return (0);
	while (lex->next)
		lex = lex->next;
	if (lex->tag != T_ENDL)
	{
		ft_putstr("Syntax error - unexpected end of input");
		ft_putstr(" (Perhaps you forgot to end with a newline ?)\n");
		return (-1);
	}
	else
		return (0);
}

static int		check_tokens(t_dlist *lex)
{
	t_dlist			*beg;

	beg = lex;
	while (lex)
	{
		if (lex->tag == T_NAME || lex->tag == T_COM)
			return (error_at_token(lex));
		else if (lex->tag == T_INSTR)
		{
			if (check_op(&lex) == -1)
				return (-1);
		}
		else if (lex->tag == T_DIR_LAB &&
		!ft_dlist_find(beg, ((t_token *)(lex->content))->name, T_LAB, find_str))
			return (error_at_token(lex));
		else if (lex->tag == T_IND_LAB &&
		!ft_dlist_find(beg, ((t_token *)(lex->content))->name, T_LAB, find_str))
			return (error_at_token(lex));
		lex = lex->next;
	}
	return (0);
}

int				lex_analysis(t_dlist *lex)
{
	int			ret;

	if (check_last(lex) == -1)
		return (-1);
	ret = lex_check_begin(&lex);
	if (ret == -2)
		return (-1);
	if (ret == -1)
		return (error_at_token(lex));
	if (check_tokens(lex) == -1)
		return (-1);
	return (0);
}
