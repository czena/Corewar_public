
#include "libft.h"

void	ft_dlist_delone(t_dlist **lst, t_dlist *ptr, void (*del)(void *))
{
	if (ptr && lst && *lst)
	{
		if (ptr->prev)
			ptr->prev->next = ptr->next;
		if (ptr->next)
			ptr->next->prev = ptr->prev;
		if (*lst == ptr)
			*lst = ptr->next;
		del(ptr->content);
		free(ptr);
	}
}
