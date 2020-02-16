
#include "libft.h"

void	ft_stack_del_link(t_stack **st)
{
	if (st && *st)
	{
		ft_dlist_del_link(&((*st)->beg));
		free(*st);
	}
	if (st)
		*st = NULL;
}
