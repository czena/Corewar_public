

#include "libft.h"
#include "disasm.h"

int		main(int argc, char **argv)
{
	int			i;
	t_dlist		*lex;
	t_header	header;

	i = argc - argc;
	while (argv[++i])
	{
		lex = NULL;
		ft_printf("%s:", argv[i]);
		if (create_tokens(&lex, argv[i], &header) == -1 ||
		create_file(lex, argv[i], &header) == -1)
		{
			ft_dlist_simple_del(&lex);
			continue;
		}
		ft_dlist_simple_del(&lex);
		ft_printf(" Success\n");
	}
	exit(0);
}
