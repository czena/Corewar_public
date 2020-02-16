
#include "libft.h"
#include <stdlib.h>

static int		ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static size_t	ft_space_len(char const *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (ft_isspace(s[i]))
		++i;
	if (s[i] == 0)
		return (1);
	j = i;
	while (s[j])
		++j;
	--j;
	while (ft_isspace(s[j]))
		--j;
	return (j - i + 2);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_space_len(s);
	if (!(str = (char *)malloc(len)))
		return (NULL);
	str[len - 1] = '\0';
	if (len == 1)
		return (str);
	i = 0;
	j = 0;
	while (ft_isspace(s[i]))
		++i;
	while (j < len - 1)
	{
		str[j] = s[i + j];
		++j;
	}
	return (str);
}
