
#include "corewar.h"
#include "op.h"

void		check_change_position(char **arena, t_cursor *cursor)
{
	t_op *op;

	while (cursor)
	{
		if (cursor->remained_op <= 0)
		{
			op = get_op(arena[0][cursor->position]);
			if (op)
			{
				cursor->op_code = arena[0][cursor->position];
				cursor->remained_op = op->cost;
			}
			else
			{
				cursor->op_code = 0;
				cursor->remained_op = 0;
			}
		}
		cursor = cursor->next;
	}
}

void		check_current_position(char **arena, t_cursor *cursor)
{
	t_op *op;

	op = get_op(arena[0][cursor->position % MEM_SIZE]);
	if (op)
	{
		cursor->op_code = arena[0][cursor->position % MEM_SIZE];
		cursor->remained_op = op->cost;
	}
	else
	{
		cursor->op_code = 0;
		cursor->remained_op = 0;
	}
}

void		check_cursor_is_ready(char **arena,
								t_cursor **cursor, t_param *param)
{
	t_cursor *temp;

	temp = *cursor;
	while (temp)
	{
		if (temp->remained_op <= 0)
			check_current_position(arena, temp);
		temp->remained_op -= 1;
		if (temp->remained_op <= 0)
			check_operations(temp, arena, param);
		temp = temp->next;
	}
}
