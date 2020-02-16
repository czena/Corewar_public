/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:12:40 by nharra            #+#    #+#             */
/*   Updated: 2019/11/19 11:29:13 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "disasm.h"

int		main(int argc, char **argv)
{
	int			i;
	t_dlist		*lex;
	t_header	header;

	i = argc - argc;
	while (argv[++i])
	{
		lex = NULL;
		ft_printf("%s:", argv[i]);
		if (create_tokens(&lex, argv[i], &header) == -1 ||
		create_file(lex, argv[i], &header) == -1)
		{
			ft_dlist_simple_del(&lex);
			continue;
		}
		ft_dlist_simple_del(&lex);
		ft_printf(" Success\n");
	}
	return (0);
}
