
#include "libft.h"

char			*ft_join_nsym(char **s, int to_end, int count, char c)
{
	char *tmp;

	tmp = ft_str_nsym(count, c);
	if (to_end == 0)
		ft_join_beg(s, tmp);
	else
		ft_join(s, tmp);
	free(tmp);
	return (*s);
}
