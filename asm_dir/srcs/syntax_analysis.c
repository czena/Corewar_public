
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
