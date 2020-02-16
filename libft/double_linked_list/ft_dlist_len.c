
#include "libft.h"

size_t		ft_dlist_len(t_dlist *ptr)
{
	size_t	len;

	len = 0;
	while (ptr)
	{
		++len;
		ptr = ptr->next;
	}
	return (len);
}
