/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:45:12 by czena             #+#    #+#             */
/*   Updated: 2019/11/19 13:42:51 by czena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

static int	check_comment(int fd, t_player *plr, char *str)
{
	char	*comment;
	char	buffer[4];

	if (!(comment = ft_strnew(COMMENT_LENGTH)))
		return (print_errors(12, "check_comment", NULL));
	if (read(fd, comment, COMMENT_LENGTH) != COMMENT_LENGTH)
		return (print_errors(14, str, NULL));
	comment[COMMENT_LENGTH] = '\0';
	plr->comment = comment;
	read(fd, &buffer, 4);
	return (1);
}

static int	check_champ_size(int fd, t_player *plr, char *str)
{
	int		size;
	char	buffer[1];
	char	number[sizeof(CHAMP_MAX_SIZE)];
	int		i;

	i = sizeof(CHAMP_MAX_SIZE);
	while (i > 0)
	{
		if (read(fd, &buffer, 1) != 1)
			return (print_errors(13, str, NULL));
		number[i - 1] = buffer[0];
		i--;
	}
	ft_memcpy(&size, &number, sizeof(CHAMP_MAX_SIZE));
	if (size > CHAMP_MAX_SIZE)
		return (print_errors(13, str, NULL));
	plr->champ_size = size;
	return (1);
}

static int	check_name(int fd, t_player *plr, char *str)
{
	char	*name;
	char	buffer[4];

	if (!(name = ft_strnew(PROG_NAME_LENGTH)))
		return (print_errors(12, "check_name", NULL));
	if (read(fd, name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		return (print_errors(11, str, NULL));
	name[PROG_NAME_LENGTH] = '\0';
	plr->name = name;
	read(fd, &buffer, 4);
	return (1);
}

static int	check_magic_header(int fd, char *str)
{
	int		magic;
	char	buffer[1];
	char	number[sizeof(COREWAR_EXEC_MAGIC)];
	int		i;

	i = sizeof(COREWAR_EXEC_MAGIC);
	while (i > 0)
	{
		if (read(fd, &buffer, 1) != 1)
			return (print_errors(10, str, NULL));
		number[i - 1] = buffer[0];
		i--;
	}
	ft_memcpy(&magic, &number, sizeof(COREWAR_EXEC_MAGIC));
	if (magic != COREWAR_EXEC_MAGIC)
		return (print_errors(10, str, NULL));
	return (1);
}

int			check_file(t_player *plr)
{
	int i;
	int fd;

	i = 0;
	while (i < MAX_PLAYERS && plr[i].connect != -1)
	{
		if ((fd = open(plr[i].file, O_RDONLY)) == -1)
			return (print_errors(9, plr[i].file, NULL));
		if (check_magic_header(fd, plr[i].file) == -1 ||
			check_name(fd, &plr[i], plr[i].file) == -1 ||
			check_champ_size(fd, &plr[i], plr[i].file) == -1 ||
			check_comment(fd, &plr[i], plr[i].file) == -1 ||
			check_code(fd, &plr[i], plr[i].file) == -1)
		{
			close(fd);
			return (-1);
		}
		close(fd);
		i++;
	}
	return (1);
}
