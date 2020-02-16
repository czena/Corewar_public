/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:52:30 by nharra            #+#    #+#             */
/*   Updated: 2019/11/19 10:52:56 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int				find_str(void *s1, void *s2)
{
	char		*str1;
	char		*str2;

	str2 = (char *)s2;
	str1 = ((t_token *)(s1))->name;
	return (ft_strcmp(str1, str2));
}
