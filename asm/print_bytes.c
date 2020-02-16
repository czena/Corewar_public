/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:23:29 by nharra            #+#    #+#             */
/*   Updated: 2019/11/16 14:46:13 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void	print_char(char c, const int fd, int *cur_byte)
{
	write(fd, &c, 1);
	if (cur_byte != NULL)
		*cur_byte += 1;
}

void	print_int(int int_arg, const int fd, int *cur_byte)
{
	write(fd, ((char *)(&int_arg)) + 3, 1);
	write(fd, ((char *)(&int_arg)) + 2, 1);
	write(fd, ((char *)(&int_arg)) + 1, 1);
	write(fd, ((char *)(&int_arg)), 1);
	if (cur_byte != NULL)
		*cur_byte += 4;
}

void	print_short(short int sh_int_arg, const int fd, int *cur_byte)
{
	write(fd, ((char *)(&sh_int_arg)) + 1, 1);
	write(fd, ((char *)(&sh_int_arg)), 1);
	if (cur_byte != NULL)
		*cur_byte += 2;
}
