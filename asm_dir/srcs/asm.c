#include "asm.h"
#include "libft.h"

int		main(int argc, const char **argv)
{
	int			i;
	t_dlist		*lex;

	i = argc - argc;
	while (argv[++i])
	{
		lex = NULL;
		if (syntax_analysis(argv[i], &lex) == -1 ||
		lex_analysis(lex) == -1 ||
		create_byte_code(lex, argv[i]) == -1)
		{
			ft_dlist_del(&lex, delete_token);
			continue;
		}
		ft_dlist_del(&lex, delete_token);
	}
	exit(0);
}
