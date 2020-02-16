
#include "libft.h"

int		ft_tolower(int c)
{
	if ((unsigned)c >= 'A' && (unsigned)c <= 'Z')
		c += 'a' - 'A';
	return (c);
}
