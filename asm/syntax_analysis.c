/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:04:04 by nharra            #+#    #+#             */
/*   Updated: 2019/11/18 17:35:15 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

int			syntax_analysis(const char *filename, t_dlist **lst)
{
	char		*line;

	if ((line = read_file(filename)) == NULL)
		return (-1);
	if (add_tokens(lst, line) == -1)
	{
		free(line);
		return (-1);
	}
	free(line);
	return (0);
}
