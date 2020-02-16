
#include "libft.h"

t_dlist		*ft_dlist_find_content(t_dlist const *lst, void *data,
							int (*f)(void *, void *))
{
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst && f(lst->content, data))
	{
		lst = lst->next;
	}
	return ((t_dlist *)lst);
}
