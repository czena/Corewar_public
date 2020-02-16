#include "asm.h"
#include "op.h"
#include <unistd.h>

static char		*read_str(char **line, t_point *point)
{
	char	*ptr;
	char	*str;
	int		len;

	ptr = *line;
	while (*(++ptr) && *ptr != '"')
	{
		if (*ptr == '\n')
		{
			point->col = 0;
			point->line++;
		}
		else
			point->col++;
	}
	if (*ptr == '\0')
		return (NULL);
	++(*ptr);
	len = ptr - *line - 1;
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	ft_strncpy(str, *line + 1, len);
	str[len] = '\0';
	*line = ptr;
	return (str);
}

int				check_name(t_dlist **lst, char **line, t_point *point)
{
	char		*str;
	t_point		new;
	char		*ptr;

	if (ft_strncmp(*line, NAME_CMD_STRING, LEN_NAME_CMD) == 0)
	{
		new.col = point->col;
		new.line = point->line;
		ptr = *line + LEN_NAME_CMD;
		new.col += skip_spaces(&ptr) + LEN_NAME_CMD;
		if ((*ptr) != '"')
			return (0);
		if ((str = read_str(&ptr, &new)))
		{
			if (create_token(lst, str, &new, T_NAME) == -1)
				return (0);
			point->col = new.col;
			point->line = new.line;
			*line = ptr;
			return (1);
		}
		return (0);
	}
	return (0);
}

int				check_comment(t_dlist **lst, char **line, t_point *point)
{
	char		*str;
	t_point		new;
	char		*ptr;

	if (ft_strncmp(*line, COMMENT_CMD_STRING, LEN_COMMENT_CMD) == 0)
	{
		new.col = point->col;
		new.line = point->line;
		ptr = *line + LEN_COMMENT_CMD;
		new.col += skip_spaces(&ptr) + LEN_COMMENT_CMD;
		if ((*ptr) != '"')
			return (0);
		if ((str = read_str(&ptr, &new)))
		{
			if (create_token(lst, str, &new, T_COM) == -1)
				return (0);
			point->col = new.col;
			point->line = new.line;
			*line = ptr;
			return (1);
		}
		return (0);
	}
	return (0);
}
