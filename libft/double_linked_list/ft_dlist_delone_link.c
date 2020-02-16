
#include "libft.h"

void	ft_dlist_delone_link(t_dlist **lst, t_dlist *ptr)
{
	if (ptr && lst && *lst)
	{
		if (ptr->prev)
			ptr->prev->next = ptr->next;
		if (ptr->next)
			ptr->next->prev = ptr->prev;
		if (*lst == ptr)
			*lst = ptr->next;
		free(ptr);
	}
}
