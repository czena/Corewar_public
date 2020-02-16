/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:50:51 by nharra            #+#    #+#             */
/*   Updated: 2019/10/26 00:54:17 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include "libft.h"

int			print_percent(t_print_info *info)
{
	if (info->width <= 1)
		write(1, "%", 1);
	else
	{
		if (info->flags & flag_minus)
		{
			write(1, "%", 1);
			ft_put_nsym(info->width - 1, ' ');
		}
		else
		{
			if (info->flags & flag_zero)
				ft_put_nsym(info->width - 1, '0');
			else
				ft_put_nsym(info->width - 1, ' ');
			write(1, "%", 1);
		}
	}
	return (info->width <= 1 ? 1 : info->width);
}
