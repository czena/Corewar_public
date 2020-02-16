
#include "op.h"
#include "corewar.h"

static void	operation_sti2(int *res, char type, t_cursor *cursor,
							char **arena)
{
	if (get_bin_num(type, 2) == 1)
		*res = reg_read(cursor, arena);
	else if (get_bin_num(type, 2) == 2)
		*res = dir_read(cursor, arena, 2);
	else if (get_bin_num(type, 2) == 3)
		*res = ind_read(cursor, arena);
	if (get_bin_num(type, 3) == 1)
		*res += reg_read(cursor, arena);
	else if (get_bin_num(type, 3) == 2)
		*res += dir_read(cursor, arena, 2);
}

void		operation_sti(t_cursor *cursor, char **arena, t_param *param)
{
	int		reg;
	int		res;
	char	type;
	int		address;

	res = 0;
	if (init_type(&type, cursor, arena, 2) == -1)
		return ;
	reg = get_t_reg(arena, (cursor->position + cursor->byte_to_next) %
		MEM_SIZE);
	cursor->byte_to_next += 1;
	operation_sti2(&res, type, cursor, arena);
	if (cursor->position + (res % IDX_MOD) < 0)
		address = (cursor->position + (res % IDX_MOD) + MEM_SIZE) % MEM_SIZE;
	else
		address = (cursor->position + (res % IDX_MOD)) % MEM_SIZE;
	set_dir_arena(arena, address, cursor->reg[reg]);
	set_dir_owner(cursor, arena, address, param);
	cursor->position = (cursor->position + cursor->byte_to_next) % MEM_SIZE;
}

void		operation_lld(t_cursor *cursor, char **arena)
{
	int		ind;
	int		res;
	char	type;

	res = 0;
	if (init_type(&type, cursor, arena, 4) == -1)
		return ;
	if (get_bin_num(type, 1) == 2)
		res = dir_read(cursor, arena, 4);
	else if (get_bin_num(type, 1) == 3)
	{
		ind = get_t_ind(arena, (cursor->position + cursor->byte_to_next) %
						MEM_SIZE);
		res = get_t_dir(arena, (cursor->position + ind) % MEM_SIZE, 4);
		cursor->byte_to_next += 2;
	}
	cursor->reg[get_t_reg(arena, (cursor->position + cursor->byte_to_next) %
					MEM_SIZE)] = res;
	cursor->byte_to_next += 1;
	cursor->carry = res == 0 ? 1 : 0;
	cursor->position = (cursor->position + cursor->byte_to_next) % MEM_SIZE;
}

void		operation_lldi(t_cursor *cursor, char **arena)
{
	int		res;
	char	type;
	int		address;

	res = 0;
	if (init_type(&type, cursor, arena, 2) == -1)
		return ;
	if (get_bin_num(type, 1) == 1)
		res = reg_read(cursor, arena);
	else if (get_bin_num(type, 1) == 2)
		res = dir_read(cursor, arena, 2);
	else if (get_bin_num(type, 1) == 3)
		res = ind_read(cursor, arena);
	if (get_bin_num(type, 2) == 1)
		res += reg_read(cursor, arena);
	else if (get_bin_num(type, 2) == 2)
		res += dir_read(cursor, arena, 2);
	if ((cursor->position + res) % MEM_SIZE < 0)
		address = (cursor->position + res) % MEM_SIZE + MEM_SIZE;
	else
		address = (cursor->position + res) % MEM_SIZE;
	cursor->reg[get_t_reg(arena, (cursor->position + cursor->byte_to_next) %
		MEM_SIZE)] = get_t_dir(arena, address, 4);
	cursor->byte_to_next += 1;
	cursor->position = (cursor->position + cursor->byte_to_next) % MEM_SIZE;
}

void		operation_lfork(t_cursor *cursor, char **arena)
{
	int			res;
	t_cursor	*temp;
	int			i;

	i = 0;
	temp = cursor;
	cursor->byte_to_next = 1;
	res = dir_read(cursor, arena, 2);
	cursor_create_empty(&cursor);
	cursor_to_bgn(&cursor);
	cursor->carry = temp->carry;
	while (i < REG_NUMBER)
	{
		cursor->reg[i] = temp->reg[i];
		i++;
	}
	cursor->last_live = temp->last_live;
	if ((res % IDX_MOD + temp->position) % MEM_SIZE < 0)
		res = MEM_SIZE + (res % IDX_MOD + temp->position) % MEM_SIZE;
	cursor->position = (res + temp->position) % MEM_SIZE;
	cursor->remained_op = 0;
	cursor->creator = temp->creator;
	temp->position = (temp->position + temp->byte_to_next) % MEM_SIZE;
}
