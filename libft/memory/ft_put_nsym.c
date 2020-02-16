
#include "libft.h"

void			ft_put_nsym(int count, char c)
{
	char *s;

	if (!(s = ft_str_nsym(count, c)))
		return ;
	write(1, s, ft_strlen(s));
	free(s);
}
