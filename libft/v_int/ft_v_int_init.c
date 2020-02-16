/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v_int_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 02:34:21 by nharra            #+#    #+#             */
/*   Updated: 2019/10/26 02:51:12 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_v_int_init(t_v_int *v, size_t size)
{
	if (size == 0)
		return (0);
	if (!(v->beg = ft_memalloc(size * sizeof(*v->beg))))
		return (-1);
	v->after_end = v->beg;
	v->max_size = size;
	return (1);
}
