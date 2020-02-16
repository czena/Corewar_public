/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_nsym.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 00:39:11 by nharra            #+#    #+#             */
/*   Updated: 2019/10/26 02:57:55 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_join_nsym(char **s, int to_end, int count, char c)
{
	char *tmp;

	tmp = ft_str_nsym(count, c);
	if (to_end == 0)
		ft_join_beg(s, tmp);
	else
		ft_join(s, tmp);
	free(tmp);
	return (*s);
}
