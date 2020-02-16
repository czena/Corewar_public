/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:02:31 by nharra            #+#    #+#             */
/*   Updated: 2019/11/19 11:25:19 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"
#include "libft.h"
#include <fcntl.h>

static char		*create_filename(const char *filename)
{
	char		*new_file;
	size_t		len;
	const char	*ptr;

	ptr = filename;
	while (*ptr)
		++ptr;
	len = ptr - filename;
	while (*ptr != '.' && ptr != filename)
		--ptr;
	if (ptr == filename)
		len += 2;
	else
		len = ptr - filename + 2;
	if (!(new_file = (char *)malloc(sizeof(*new_file) * (len + 1))))
		return (NULL);
	ft_strncpy(new_file, filename, len - 2);
	ft_strcpy(new_file + len - 2, ".s");
	return (new_file);
}

static void		print_params(t_dlist *lex, const int fd)
{
	if (lex->tag == T_REG)
	{
		ft_putchar_fd('r', fd);
		ft_putnbr_fd(((t_token *)lex->content)->ch_op, fd);
	}
	else if (lex->tag == T_IND)
	{
		ft_putnbr_fd(((t_token *)lex->content)->sh_op, fd);
	}
	else if (lex->tag == T_DIR)
	{
		ft_putchar_fd('%', fd);
		if (((t_token *)lex->content)->dir_size == 2)
			ft_putnbr_fd(((t_token *)lex->content)->sh_op, fd);
		else
			ft_putnbr_fd(((t_token *)lex->content)->int_op, fd);
	}
}

static void		print_lex(t_dlist *lex, const int fd)
{
	int i;

	while (lex)
	{
		ft_putchar_fd('\t', fd);
		write(fd, lex->content, ft_strlen((char *)lex->content));
		ft_putchar_fd(' ', fd);
		lex = lex->next;
		i = 0;
		while (lex && lex->tag != T_INSTR)
		{
			if (i++ != 0)
				ft_putstr_fd(", ", fd);
			print_params(lex, fd);
			lex = lex->next;
		}
		ft_putchar_fd('\n', fd);
	}
}

int				create_file(t_dlist *lex, const char *filename,
				t_header *header)
{
	char	*new_filename;
	int		fd;

	if ((new_filename = create_filename(filename)) == NULL ||
	(fd = open(new_filename, O_CREAT | O_WRONLY, 0666)) == -1)
		return (error("Error creating new file"));
	write(fd, ".name \"", ft_strlen(".name \""));
	write(fd, header->prog_name, ft_strlen(header->prog_name));
	write(fd, "\"\n.comment \"", ft_strlen("\"\n.comment \""));
	write(fd, header->comment, ft_strlen(header->comment));
	write(fd, "\"\n\n", ft_strlen("\"\n\n"));
	print_lex(lex, fd);
	free(new_filename);
	return (0);
}
