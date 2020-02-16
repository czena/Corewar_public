
#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*s;
	size_t	i;

	i = 0;
	s = dest;
	while (*s)
		++s;
	while (src[i])
	{
		*s = src[i];
		++s;
		++i;
	}
	*s = '\0';
	return (dest);
}
