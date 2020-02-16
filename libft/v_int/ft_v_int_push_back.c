/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v_int_push_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 02:27:42 by nharra            #+#    #+#             */
/*   Updated: 2019/10/26 02:52:24 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_v_int_push_back(t_v_int *v, int value)
{
	if ((size_t)(v->after_end - v->beg) >= v->max_size)
		if (ft_v_int_realloc(v, v->max_size * 2) == -1)
			return (-1);
	*v->after_end = value;
	++(v->after_end);
	return (0);
}
