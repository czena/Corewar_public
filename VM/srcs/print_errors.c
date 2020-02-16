/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:03:20 by czena             #+#    #+#             */
/*   Updated: 2019/11/19 14:01:44 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_errors2(int n, char *str)
{
	if (n == 9)
		ft_printf("Read error %s\n", str);
	else if (n == 10)
		ft_printf("Invalid magic number in file %s\n", str);
	else if (n == 11)
		ft_printf("Invalid champion name in file %s\n", str);
	else if (n == 12)
		ft_printf("Error of allocate memory in %s\n", str);
	else if (n == 13)
		ft_printf("Invalid champion size in file %s\n", str);
	else if (n == 14)
		ft_printf("Invalid champion comment in file %s\n", str);
	else if (n == 15)
		ft_printf("Invalid champion code in file %s\n", str);
	else if (n == 16)
		ft_printf("Bad num of dump %s\n", str);
	else if (n == 17)
		ft_printf("No champions\n");
	else
		ft_printf("Unknown error: %d\n", n);
}

int			print_errors(int n, char *str, char *str2)
{
	if (n == 1)
		ft_printf("Too many champions\n");
	else if (n == 2)
		ft_printf("Bad format of file: %s\n", str);
	else if (n == 3)
		ft_printf("Need a num after %s\n", str);
	else if (n == 4)
		ft_printf("Bad player ID: %s\n", str);
	else if (n == 5)
		ft_printf("Need a file name after: %s %s\n", str, str2);
	else if (n == 6)
		ft_printf("Flag %s is an active\n", str);
	else if (n == 7)
		ft_printf("ID %s is used\n", str);
	else if (n == 8)
		ft_printf("ID %s more than players\n", str);
	else
		print_errors2(n, str);
	return (-1);
}
