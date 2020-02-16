
#include "libft.h"

t_dlist		*ft_dlist_push_link(t_dlist **lst, void *data, int tag)
{
	t_dlist		*ptr;
	t_dlist		*end;

	if (!data || !lst || !(ptr = (t_dlist *)malloc(sizeof(*ptr))))
		return (NULL);
	ptr->content = data;
	ptr->tag = tag;
	ptr->next = NULL;
	if (*lst == NULL)
	{
		ptr->prev = NULL;
		*lst = ptr;
		return (*lst);
	}
	end = *lst;
	while (end->next)
		end = end->next;
	end->next = ptr;
	ptr->prev = end;
	return (*lst);
}
