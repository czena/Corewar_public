
#include "libft.h"

void	ft_swap_int(int *a, int *b)
{
	int c;

	if (!a || !b)
		return ;
	c = *a;
	*a = *b;
	*b = c;
}
