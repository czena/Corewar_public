
#include "libft.h"
#include "disasm.h"

int				read_arg(const int fd, void *arg, unsigned size)
{
	char		str[sizeof(int)];
	unsigned	i;

	if (size == 0)
		return (-1);
	if (read(fd, str, size) != size)
		return (-1);
	i = 0;
	while (i < size)
	{
		*((unsigned char *)arg + size - 1 - i) = str[i];
		++i;
	}
	return (0);
}

static int		read_arg_from_buf(t_buf *buf, void *arg, unsigned size)
{
	unsigned	i;

	if (size == 0)
		return (-1);
	i = 0;
	while (i < size)
	{
		*((unsigned char *)arg + size - 1 - i) = buf->buf[buf->i + i];
		++i;
	}
	buf->i += size;
	return (0);
}

int				read_ch(t_buf *buf, t_dlist **lex, int type)
{
	t_token		*token;

	if (buf->i >= buf->size)
		return (-1);
	if ((token = (t_token *)malloc(sizeof(*token))) == NULL)
		return (-1);
	read_arg_from_buf(buf, &token->ch_op, sizeof(token->ch_op));
	if (ft_dlist_push_link(lex, token, type) == NULL)
	{
		free(token);
		return (-1);
	}
	return (1);
}

int				read_short(t_buf *buf, t_dlist **lex, int type)
{
	t_token		*token;

	if (buf->i + 1 >= buf->size)
		return (-1);
	if ((token = (t_token *)malloc(sizeof(*token))) == NULL)
		return (-1);
	token->dir_size = 2;
	read_arg_from_buf(buf, &token->sh_op, sizeof(token->sh_op));
	if (ft_dlist_push_link(lex, token, type) == NULL)
	{
		free(token);
		return (-1);
	}
	return (1);
}

int				read_int(t_buf *buf, t_dlist **lex, int type)
{
	t_token		*token;

	if (buf->i + 3 >= buf->size)
		return (-1);
	if ((token = (t_token *)malloc(sizeof(*token))) == NULL)
		return (-1);
	token->dir_size = 4;
	read_arg_from_buf(buf, &token->int_op, sizeof(token->int_op));
	if (ft_dlist_push_link(lex, token, type) == NULL)
	{
		free(token);
		return (-1);
	}
	return (1);
}
