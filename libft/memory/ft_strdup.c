
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char *str;

	if (!(str = (char *)malloc(ft_strlen(s1) + 1)))
	{
		return (NULL);
	}
	else
	{
		ft_strcpy(str, s1);
		return (str);
	}
}
