
#include "corewar.h"
#include "op.h"

static void		print_usage(void)
{
	ft_printf("./corewar [-a] [-dump <num>] [-v] [-n <num>] <champion.cor>  ");
	ft_printf("<...>\n-a          : Print output from");
	ft_printf("\"aff\" (Default is off)\n-v          : Run visualizer\n");
	ft_printf("-n    <num> : Set <num> of the next player\n");
}

int				main(int argc, char **argv)
{
	t_player	plr[MAX_PLAYERS];
	t_param		param;

	players_init(plr);
	new_param(&param);
	if (argc == 1)
		print_usage();
	else
	{
		if (check_input(&argv[1], argc - 1, plr, &param) < 1 ||
			check_file(plr) == -1 ||
			arena_init(plr, &param) == -1)
		{
			players_delete(plr);
			return (-1);
		}
		print_winners(plr, &param);
		players_delete(plr);
	}
	exit(1);
}
