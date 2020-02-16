
#include "libft.h"

static void		ft_copy(char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		++i;
	}
	s1[i] = '\0';
}

char			*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *s;

	s = s1;
	while (*s != '\0')
		++s;
	ft_copy(s, s2, n);
	return (s1);
}
