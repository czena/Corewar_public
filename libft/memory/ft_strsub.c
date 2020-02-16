
#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!s || !(str = (char *)malloc(len + 1)))
		return (NULL);
	str[len] = '\0';
	return ((char *)ft_memcpy(str, s + start, len));
}
