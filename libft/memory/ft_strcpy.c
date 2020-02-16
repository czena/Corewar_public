
#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*save;
	size_t	i;

	i = 0;
	save = dest;
	while (src[i])
	{
		*dest = src[i];
		++dest;
		++i;
	}
	*dest = '\0';
	return (save);
}
