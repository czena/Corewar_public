/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_byte_code.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharra <nharra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:03:23 by nharra            #+#    #+#             */
/*   Updated: 2019/11/19 10:51:13 by nharra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

char	*create_filename(const char *filename)
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
		len += 4;
	else
		len = ptr - filename + 4;
	if (!(new_file = (char *)malloc(sizeof(*new_file) * (len + 1))))
		return (NULL);
	ft_strcpy(new_file, filename);
	ft_strcpy(new_file + len - 4, ".cor");
	return (new_file);
}

void	print_name_and_comment(t_dlist *lex, const int fd, const int size)
{
	char	*name;
	char	*comment;
	char	str[COMMENT_LENGTH];

	print_int(COREWAR_EXEC_MAGIC, fd, NULL);
	name = (((t_token *)ft_dlist_find_tag(lex, T_NAME)->content)->name);
	comment = (((t_token *)ft_dlist_find_tag(lex, T_COM)->content)->name);
	ft_strncpy(str, name, PROG_NAME_LENGTH);
	write(fd, str, PROG_NAME_LENGTH);
	print_int(0, fd, NULL);
	print_int(size, fd, NULL);
	ft_strncpy(str, comment, COMMENT_LENGTH);
	write(fd, str, COMMENT_LENGTH);
	print_int(0, fd, NULL);
}

int		write_bytes(t_dlist *lex, const char *filename, int size)
{
	int		fd;
	char	*str;

	if (!(str = create_filename(filename)))
		return (-1);
	if ((fd = open(str, O_WRONLY | O_TRUNC | O_CREAT, 0666)) == -1)
		return (-1);
	print_name_and_comment(lex, fd, size);
	print_commands_byte(lex, fd);
	close(fd);
	ft_printf("Writing output program to %s\n", str);
	free(str);
	return (0);
}

int		create_byte_code(t_dlist *lex, const char *filename)
{
	t_dlist		*byte_code;
	int			size;

	byte_code = NULL;
	size = init_labels(lex);
	init_lab_op(lex);
	if (write_bytes(lex, filename, size) == -1)
		return (-1);
	return (0);
}
