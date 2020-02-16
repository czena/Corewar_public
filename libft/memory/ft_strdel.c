
#include "libft.h"
#include <stdlib.h>

void	ft_strdel(char **as)
{
	if (as)
		if (*as)
			ft_memdel((void**)as);
}
