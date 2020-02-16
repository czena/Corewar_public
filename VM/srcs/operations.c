
#include "op.h"
#include "corewar.h"

int			change_operation(t_cursor *cursor, char **arena)
{
	t_op *op;

	op = get_op(arena[0][cursor->position]);
	if (op && op->id != 0)
	{
		cursor->op_code = arena[0][cursor->position];
		cursor->remained_op = op->cost;
		return (1);
	}
	else
	{
		cursor->op_code = arena[0][cursor->position];
		cursor->remained_op = 0;
		return (0);
	}
}

static void	check_operations2(t_cursor *cursor, char **arena, t_param *param)
{
	if (cursor->op_code == 9)
		operation_zjmp(cursor, arena);
	else if (cursor->op_code == 10)
		operation_ldi(cursor, arena);
	else if (cursor->op_code == 11)
		operation_sti(cursor, arena, param);
	else if (cursor->op_code == 12)
		operation_fork(cursor, arena);
	else if (cursor->op_code == 13)
		operation_lld(cursor, arena);
	else if (cursor->op_code == 14)
		operation_lldi(cursor, arena);
	else if (cursor->op_code == 15)
		operation_lfork(cursor, arena);
	else if (cursor->op_code == 16)
		operation_aff(cursor, arena, param);
	else if (cursor->op_code == 0)
		cursor->position += 1;
}

void		check_operations(t_cursor *cursor, char **arena, t_param *param)
{
	if (cursor->op_code == 1)
		operation_live(cursor, param, arena);
	else if (cursor->op_code == 2)
		operation_ld(cursor, arena);
	else if (cursor->op_code == 3)
		operation_st(cursor, arena, param);
	else if (cursor->op_code == 4)
		operation_add(cursor, arena);
	else if (cursor->op_code == 5)
		operation_sub(cursor, arena);
	else if (cursor->op_code == 6)
		operation_and(cursor, arena);
	else if (cursor->op_code == 7)
		operation_or(cursor, arena);
	else if (cursor->op_code == 8)
		operation_xor(cursor, arena);
	else
		check_operations2(cursor, arena, param);
}
