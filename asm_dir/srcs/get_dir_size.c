#include "asm.h"
#include "libft.h"

int				get_dir_size(const t_op *op)
{
	static int		g_dir_size[17] =
	{
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		4,
		2,
		2,
		2,
		2,
		4,
		2,
		2,
		4,
		0
	};
	return (g_dir_size[op->id - 1]);
}
