/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:26:49 by nharra            #+#    #+#             */
/*   Updated: 2019/11/16 20:03:47 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

/*
**		label
*/

int		check_label(t_dlist **lst, char **line, t_point *point)
{
	char	*ptr;
	char	*str;
	int		len;

	ptr = *line;
	len = skip_label(&ptr);
	if (*ptr == LABEL_CHAR && len != 0)
	{
		if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
			return (0);
		ft_strncpy(str, *line, len);
		str[len] = '\0';
		if (create_token(lst, str, point, T_LAB) == -1)
			return (0);
		point->col += len;
		*line = ptr + 1;
		return (1);
	}
	return (0);
}

/*
**		%:label
*/

int		check_direct_label(t_dlist **lst, char **line, t_point *point)
{
	char	*ptr;
	char	*str;
	int		len;

	ptr = *line + 2;
	if ((*line)[0] == DIRECT_CHAR && (*line)[1] == LABEL_CHAR)
	{
		len = skip_label(&ptr);
		if (len == 0)
			return (0);
		if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
			return (0);
		ft_strncpy(str, *line + 2, len);
		str[len] = '\0';
		if (create_token(lst, str, point, T_DIR_LAB) == -1)
			return (0);
		point->col += len;
		*line = ptr;
		return (1);
	}
	return (0);
}

/*
**		,
*/

int		check_separator(t_dlist **lst, char **line, t_point *point)
{
	if (**line == SEPARATOR_CHAR)
	{
		if (create_token(lst, NULL, point, T_SEP) == -1)
			return (0);
		point->col += 1;
		*line += 1;
		return (1);
	}
	return (0);
}

/*
**		r00
*/

int		check_registor(t_dlist **lst, char **line, t_point *point)
{
	char	*str;
	int		len;
	char	*ptr;

	ptr = *line;
	if (*ptr == 'r')
	{
		if (ptr[1] == '0')
			return (0);
		++ptr;
		while (ft_isdigit(*ptr))
			++ptr;
		len = ptr - *line - 1;
		if (len <= 0 || len >= 3 ||
		!(str = (char *)malloc(sizeof(*str) * (len + 1))))
			return (0);
		ft_strncpy(str, *line + 1, len);
		str[len] = '\0';
		if (create_token(lst, str, point, T_REG) == -1)
			return (0);
		point->col += len;
		*line = ptr;
		return (1);
	}
	return (0);
}

/*
**		%23 or %-56
*/

int		check_direct(t_dlist **lst, char **line, t_point *point)
{
	char	*ptr;
	char	*str;
	int		len;

	ptr = *line;
	if (ptr[0] == DIRECT_CHAR && (ft_isdigit(ptr[1]) ||
	(ptr[1] == '-' && ft_isdigit(ptr[2]))))
	{
		if (*(++ptr) == '-')
			++ptr;
		while (ft_isdigit(*ptr))
			++ptr;
		len = ptr - *line - 1;
		if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
			return (0);
		ft_strncpy(str, *line + 1, len);
		str[len] = '\0';
		if (create_token(lst, str, point, T_DIR) == -1)
			return (0);
		point->col += len;
		*line = ptr;
		return (1);
	}
	return (0);
}
