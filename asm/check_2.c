/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:43:46 by nharra            #+#    #+#             */
/*   Updated: 2019/11/16 20:06:19 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

/*
**		instruction
*/

int		check_instruction(t_dlist **lst, char **line, t_point *point)
{
	int		len;
	char	*str;
	char	*ptr;

	ptr = *line;
	len = skip_label(&ptr);
	if (len == 0)
		return (0);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (0);
	ft_strncpy(str, *line, len);
	str[len] = '\0';
	if (create_token(lst, str, point, T_INSTR) == -1)
		return (0);
	point->col += len;
	*line = ptr;
	return (1);
}

/*
**		23 or -34
*/

int		check_ind(t_dlist **lst, char **line, t_point *point)
{
	char	*ptr;
	char	*str;
	int		len;

	ptr = *line;
	if ((ft_isdigit((*line)[0]) || ((*line)[0] == '-' &&
	ft_isdigit((*line)[1]))))
	{
		if (*ptr == '-')
			++ptr;
		while (ft_isdigit(*ptr))
			++ptr;
		len = ptr - *line;
		if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
			return (0);
		ft_strncpy(str, *line, len);
		str[len] = '\0';
		if (create_token(lst, str, point, T_IND) == -1)
			return (0);
		point->col += len;
		*line = ptr;
		return (1);
	}
	return (0);
}

/*
**		\n
*/

int		check_endl(t_dlist **lst, char **line, t_point *point)
{
	if (**line == '\n')
	{
		if (create_token(lst, NULL, point, T_ENDL) == -1)
			return (0);
		point->col = 0;
		point->line++;
		*line += 1;
		return (1);
	}
	return (0);
}

/*
**		:label
*/

int		check_ind_label(t_dlist **lst, char **line, t_point *point)
{
	char	*ptr;
	char	*str;
	int		len;

	if ((*line)[0] == LABEL_CHAR && is_label_char((*line)[1]))
	{
		ptr = *line + 1;
		len = skip_label(&ptr);
		if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
			return (0);
		ft_strncpy(str, *line + 1, len);
		str[len] = '\0';
		if (create_token(lst, str, point, T_IND_LAB) == -1)
			return (0);
		point->col += len;
		*line = ptr;
		return (1);
	}
	return (0);
}
