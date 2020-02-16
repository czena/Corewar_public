
#include "libft.h"
#include "asm.h"

int		is_label_char(char c)
{
	const char		*label_chars;
	int				i;

	label_chars = LABEL_CHARS;
	i = 0;
	while (label_chars[i])
	{
		if (c == label_chars[i])
			return (1);
		++i;
	}
	return (0);
}

int		skip_label(char **line)
{
	char *beg;

	beg = *line;
	while (is_label_char(**line))
		++(*line);
	return (*line - beg);
}

int		skip_spaces(char **line)
{
	char *beg;

	beg = *line;
	while (**line != '\0' && (**line == ' ' || **line == '\t'))
		++(*line);
	return (*line - beg);
}
