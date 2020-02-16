/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:54:42 by nharra            #+#    #+#             */
/*   Updated: 2019/11/19 11:01:22 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "asm.h"

char	*read_file(const char *filename)
{
	int		fd;
	char	buf[SIZE_BUF + 1];
	char	*file;
	int		ret_read;

	file = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_printf("%s: No such file\n", filename);
		return (NULL);
	}
	while ((ret_read = read(fd, buf, SIZE_BUF)) > 0)
	{
		buf[ret_read] = '\0';
		if (ft_join(&file, buf) == NULL)
		{
			free(file);
			return (NULL);
		}
	}
	return (file);
}
