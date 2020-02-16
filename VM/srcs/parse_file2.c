
#include "corewar.h"
#include "op.h"

int		check_code(int fd, t_player *plr, char *str)
{
	char	*code;
	char	c[1];

	if (!(code = ft_strnew(plr->champ_size)))
		return (print_errors(12, "check_code", NULL));
	if (read(fd, code, plr->champ_size) != plr->champ_size)
		return (print_errors(15, str, NULL));
	code[plr->champ_size] = '\0';
	plr->code = code;
	if (read(fd, c, 1) == 1)
		return (print_errors(15, str, NULL));
	return (1);
}

int		check_null(char *buffer)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (buffer[i] != 0)
			return (print_errors(18, NULL, NULL));
		i++;
	}
	return (1);
}
