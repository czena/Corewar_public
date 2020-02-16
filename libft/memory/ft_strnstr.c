
#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && (i + j < len)
				&& needle[j])
		{
			++j;
		}
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		++i;
	}
	if (needle[0] == '\0')
		return ((char *)haystack);
	return (NULL);
}
