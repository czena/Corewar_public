
#include "libft.h"

char	*ft_join_beg(char **s1, const char *s2)
{
	size_t		len1;
	size_t		len2;
	char		*s;
	size_t		i;

	if (!s1 || !s2 || (i = 0))
		return (NULL);
	if (!(*s1))
		return (*s1 = ft_strdup(s2));
	len1 = ft_strlen(*s1);
	if ((len2 = ft_strlen(s2)) == 0)
		return (*s1);
	if (!(s = (char *)malloc(len1 + len2 + 1)))
		return (NULL);
	while (i < len2)
	{
		s[i] = s2[i];
		++i;
	}
	while (i++ <= len1 + len2)
		s[i - 1] = (*s1)[i - 1 - len2];
	free(*s1);
	*s1 = s;
	return (s);
}
