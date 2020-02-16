

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char *buf;

	if (!(buf = (char *)malloc(size)))
		return (NULL);
	ft_bzero(buf, size);
	return (buf);
}
