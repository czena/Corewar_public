
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		result;
	size_t		i;

	i = 0;
	result = ft_strlen(src);
	while ((size > 0) && *dest)
	{
		--size;
		++dest;
		++result;
	}
	if (size > 1)
	{
		while (src[i] && (size > 1))
		{
			--size;
			*dest = src[i];
			++dest;
			++i;
		}
		*dest = '\0';
	}
	return (result);
}
