
#include "libft.h"

t_dlist		*ft_dlist_find(t_dlist const *lst, void *data, int tag,
							int (*f)(void *, void *))
{
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->tag != tag)
		{
			lst = lst->next;
			continue;
		}
		if (f(lst->content, data) == 0)
			break ;
		lst = lst->next;
	}
	return ((t_dlist *)lst);
}
