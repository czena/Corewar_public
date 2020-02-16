
#include "libft.h"

void	*ft_stack_pop(t_stack *st)
{
	void	*ptr;

	ptr = NULL;
	if (st && st->beg)
	{
		ptr = st->beg->content;
		ft_dlist_delone_link(&(st->beg), st->beg);
		st->size--;
	}
	return (ptr);
}
