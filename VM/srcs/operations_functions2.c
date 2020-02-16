
#include "op.h"
#include "corewar.h"

int			get_bin_num(char type, int n)
{
	return ((type & (3 << (6 - 2 * (n - 1)))) >> (6 - 2 * (n - 1)));
}
