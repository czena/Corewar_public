/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v_int_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 02:06:22 by nharra            #+#    #+#             */
/*   Updated: 2019/10/26 02:51:23 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_v_int		*ft_v_int_new(size_t size)
{
	t_v_int *new;

	if (size == 0 || !(new = (t_v_int *)malloc(sizeof(*new))))
		return (NULL);
	if (!(new->beg = ft_memalloc(size * sizeof(*new->beg))))
	{
		free(new);
		return (NULL);
	}
	new->after_end = new->beg;
	new->max_size = size;
	return (new);
}
