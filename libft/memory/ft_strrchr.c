
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		*save;

	save = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			save = (char*)s + i;
		++i;
	}
	if (s[i] == c)
		return ((char*)s + i);
	else
		return (save);
}
