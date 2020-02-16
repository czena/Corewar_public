
#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t a)
{
	size_t i;

	i = 0;
	while (i < a && src[i])
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		++i;
	}
	while (i < a)
	{
		((unsigned char *)dest)[i] = '\0';
		++i;
	}
	return (dest);
}
