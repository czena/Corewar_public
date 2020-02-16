
#include "libft.h"

t_dlist		*ft_dlist_find_tag(t_dlist const *lst, const int tag)
{
	if (lst == NULL)
		return (NULL);
	while (lst && (lst->tag != tag))
	{
		lst = lst->next;
	}
	return ((t_dlist *)lst);
}
