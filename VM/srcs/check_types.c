
#include "op.h"
#include "corewar.h"

static void		check_reg(char **arena, int start, int *flag)
{
	int reg;

	reg = get_t_reg(arena, start);
	if (reg < 0 || reg > REG_NUMBER - 1)
		*flag = 1;
}

int				check_types(char **arena, int n_op, int size_dir, int start)
{
	int i;
	int t;
	int size;
	int flag;

	flag = 0;
	size = 0;
	i = 0;
	while (i < get_op(n_op)->count_op)
	{
		t = get_bin_num(arena[0][start], i + 1);
		t = (t == 3 ? 4 : t);
		flag = !(t & get_op(n_op)->type_params[i]) ? 1 : flag;
		if (t == 1)
		{
			check_reg(arena, (start + size + 1) % MEM_SIZE, &flag);
			size += 1;
		}
		else if (t == 2)
			size += size_dir;
		else if (t == 4)
			size += 2;
		i++;
	}
	return (flag == 1 ? size : -1);
}
