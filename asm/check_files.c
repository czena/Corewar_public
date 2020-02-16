/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:36:15 by nharra            #+#    #+#             */
/*   Updated: 2019/11/16 19:47:28 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int fd1, fd2;
	char c1, c2;
	int	ret1, ret2;
	char s[10000];
	int		i;

	if (argc != 3)
	{
		printf("bad args\n");
		return (0);
	}
	if ((fd1 = open(argv[1], O_RDONLY)) == -1 ||
	(fd2 = open(argv[2], O_RDONLY)) == -1 )
	{
		printf("bad args\n");
		return (0);
	}
	i = 0;
	while(1)
	{
		ret1 = read(fd1, &c1, 1);
		ret2 = read(fd2, &c2, 1);
		if (ret1 != ret2)
		{
			break;
		}
		if (ret1 == 0)
		{
			close(fd1);
			close(fd2);
			return(0);
		}
		if (c1 != c2 /*|| (i > 134 && i < 140) || i >= 16 * 9 + 2048*/)
			printf("byte №%d: file1 %#hhx, file2 %#hhx\n", i, c1, c2);
		++i;
	}
	printf("Diff length\n");
	printf("size_file1 - size_file2 = %ld\n", ret1 + read(fd1, s, 10000) - ret2 - read(fd2, s, 10000));
	close(fd1);
	close(fd2);
	return(0);
}
