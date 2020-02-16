
#include "libft.h"

void	ft_dlist_add_after(t_dlist *after, t_dlist *el)
{
	if (!after || !el)
		return ;
	if (after->next)
		after->next->prev = el;
	el->next = after->next;
	el->prev = after;
	after->next = el;
}
