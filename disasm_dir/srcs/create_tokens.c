
#include "disasm.h"
#include "libft.h"

static int	error_reading(const char *str)
{
	ft_printf(" Error reading %s \n", str);
	return (-1);
}

int			read_dir(t_buf *buf, int dir_size, t_dlist **lex, int type)
{
	if (dir_size == 2)
		return (read_short(buf, lex, type));
	else
		return (read_int(buf, lex, type));
}

static int	init_beg(const int fd, t_header *header)
{
	unsigned	num;

	if (read_arg(fd, &num, sizeof(num)) == -1 || num != COREWAR_EXEC_MAGIC)
	{
		return (error_reading("EXEC_CODE"));
	}
	if (read(fd, header->prog_name, PROG_NAME_LENGTH) != PROG_NAME_LENGTH)
		return (error_reading("PROG_NAME"));
	header->prog_name[PROG_NAME_LENGTH] = '\0';
	if (read_arg(fd, &num, sizeof(num)) == -1 || num != 0)
		return (error_reading("NULL after PROG_NAME"));
	if (read_arg(fd, &(header->prog_size), sizeof(header->prog_size)) == -1)
		return (error_reading("PROG_SIZE"));
	if (read(fd, header->comment, COMMENT_LENGTH) != COMMENT_LENGTH)
		return (error_reading("COMMENT"));
	header->comment[COMMENT_LENGTH] = '\0';
	if (read_arg(fd, &num, sizeof(num)) == -1 || num != 0)
		return (error_reading("NULL after COMMENT"));
	return (0);
}

int			init_op(const int fd, t_header *header, t_dlist **lex)
{
	char			c;
	t_buf			buf;

	if (!(buf.buf = (char *)malloc(sizeof(*buf.buf) * header->prog_size)))
	{
		ft_printf(" Error in malloc %u bytes\n", header->prog_size);
		return (-1);
	}
	if (read(fd, buf.buf, header->prog_size) != header->prog_size)
		return (error_reading("OPERATIONS_BYTE"));
	buf.size = header->prog_size;
	buf.i = 0;
	if (read(fd, &c, 1) != 0)
		return (error_reading("EOF"));
	if (create_token(&buf, lex) == -1)
		return (-1);
	free(buf.buf);
	return (0);
}

int			create_tokens(t_dlist **lex, const char *filename,
			t_header *header)
{
	int		fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_printf(" No such file\n", filename);
		return (-1);
	}
	if (init_beg(fd, header) == -1)
		return (-1);
	if (init_op(fd, header, lex) == -1)
		return (-1);
	return (0);
}
