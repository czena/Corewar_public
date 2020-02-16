/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:15:47 by nharra            #+#    #+#             */
/*   Updated: 2019/11/19 10:29:12 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int		main(int argc, const char **argv)
{
	int			i;
	t_dlist		*lex;

	i = argc - argc;
	while (argv[++i])
	{
		lex = NULL;
		if (syntax_analysis(argv[i], &lex) == -1 ||
		lex_analysis(lex) == -1 ||
		create_byte_code(lex, argv[i]) == -1)
		{
			ft_dlist_del(&lex, delete_token);
			continue;
		}
		ft_dlist_del(&lex, delete_token);
	}
	return (0);
}
