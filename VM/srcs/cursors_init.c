
#include "corewar.h"
#include "op.h"

int			cursors_init(t_cursor **cursor, t_player *plr)
{
	int	i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (plr[i].connect > 0)
		{
			if (cursor_create(cursor, &plr[i]) == -1)
				return (-1);
		}
		i++;
	}
	return (1);
}
