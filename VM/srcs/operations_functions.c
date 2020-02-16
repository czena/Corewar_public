
#include "op.h"
#include "corewar.h"

int			get_t_dir(char **arena, int start, int dir_size)
{
	int					i;
	int					j;
	short int			sh;
	unsigned char		buffer[dir_size];

	i = dir_size - 1;
	j = 0;
	sh = 0;
	ft_memset(&buffer, 0, dir_size);
	if (start < 0)
		start = MEM_SIZE + start;
	while (j < dir_size)
	{
		buffer[j] = arena[0][(start + i) % MEM_SIZE];
		i--;
		j++;
	}
	if (dir_size == 4)
	{
		ft_memcpy(&i, buffer, dir_size);
		return (i);
	}
	ft_memcpy(&sh, buffer, dir_size);
	return (sh);
}

int			get_t_reg(char **arena, int start)
{
	char	i;

	if (start < 0)
		start = MEM_SIZE + start;
	i = arena[0][(start) % MEM_SIZE];
	return (i - 1);
}

int			get_t_ind(char **arena, int start)
{
	short int		i;
	int				j;
	unsigned char	buffer[IND_SIZE];

	i = IND_SIZE - 1;
	j = 0;
	ft_memset(&buffer, 0, IND_SIZE);
	if (start < 0)
		start = MEM_SIZE + start;
	while (j < IND_SIZE)
	{
		buffer[j] = arena[0][(start + i) % MEM_SIZE];
		i--;
		j++;
	}
	ft_memcpy(&i, buffer, IND_SIZE);
	return (i);
}

void		set_dir_arena(char **arena, int start, int x)
{
	int			i;
	int			j;

	i = DIR_SIZE - 1;
	j = 0;
	if (start < 0)
		start = MEM_SIZE + start;
	while (j < DIR_SIZE)
	{
		arena[0][(start + i) % MEM_SIZE] = ((char*)&x)[j];
		i--;
		j++;
	}
}

void		set_dir_owner(t_cursor *cursor, char **arena,
						int start, t_param *param)
{
	int i;

	i = DIR_SIZE - 1;
	if (start < 0)
		start = MEM_SIZE + start;
	while (i >= 0)
	{
		if (cursor->reg[0] * -1 < 1 || cursor->reg[0] * -1 > param->n_players)
			arena[1][(start + i) % MEM_SIZE] = cursor->creator;
		else
			arena[1][(start + i) % MEM_SIZE] = cursor->reg[0] * -1;
		arena[2][(start + i) % MEM_SIZE] = 50;
		i--;
	}
}
