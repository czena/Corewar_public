/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 08:43:36 by nharra            #+#    #+#             */
/*   Updated: 2019/10/26 00:53:32 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

char			*num_base(unsigned long long num, unsigned base,
							t_print_info *info)
{
	unsigned long long	rank;
	char				*base_str;
	int					len_num;
	int					i;
	char				*s;

	base_str = "0123456789abcdef";
	if (info->type == type_X)
		base_str = "0123456789ABCDEF";
	len_num = ft_ull_len_base(num, base);
	if (!(s = (char *)malloc(sizeof(*s) * (len_num + 1))))
		return (NULL);
	rank = 1;
	while (num / rank >= base)
		rank *= base;
	i = 0;
	while (rank)
	{
		s[i++] = *(base_str + (num / rank) % base);
		rank /= base;
	}
	s[i] = '\0';
	return (s);
}

char			*ull_base(unsigned long long num, t_print_info *info)
{
	int		base;

	if (info->type == type_X || info->type == type_x)
		base = 16;
	else if (info->type == type_o)
		base = 8;
	else
		base = 10;
	return (num_base(num, base, info));
}

char			*ll_base(long long num, t_print_info *info)
{
	unsigned long long	u_num;
	char				*num_str;

	u_num = num;
	if (num >= 0)
	{
		num_str = num_base(u_num, 10, info);
	}
	else
	{
		u_num = -u_num;
		num_str = num_base(u_num, 10, info);
	}
	return (num_str);
}
