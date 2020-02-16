
#include "libft.h"

char	*ft_str_nsym(int count, char sym)
{
	char	*s;
	size_t	size;

	size = count + 1;
	if (count <= 0)
		return (NULL);
	if (!(s = (char *)malloc(size)))
		return (NULL);
	s[--size] = '\0';
	while (size--)
		s[size] = sym;
	return (s);
}
