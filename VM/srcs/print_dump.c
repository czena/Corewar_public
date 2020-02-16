
#include "corewar.h"

void			print_dump(char **arena)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_printf("0x");
	while (i < MEM_SIZE / 32)
	{
		ft_printf("%#.4hx :", i * 32);
		j = 0;
		while (j < 32)
		{
			ft_printf(" %.2hhx", arena[0][i * 32 + j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
