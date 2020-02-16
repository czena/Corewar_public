
#include "libft.h"

void	ft_dlist_add_prev(t_dlist **lst, t_dlist *side, t_dlist *el)
{
	if (!side || !el || lst || *lst)
		return ;
	if (side->prev)
		side->prev->next = side;
	el->next = side;
	el->prev = side->prev;
	side->prev = el;
	if (*lst == side)
		*lst = el;
}
