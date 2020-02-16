
#include "libft.h"

int		ft_dlist_is_tagsort(t_dlist *lst, int is_ascending)
{
	if (!lst)
		return (1);
	if (is_ascending)
	{
		while (lst->next)
		{
			if (lst->tag > lst->next->tag)
				return (0);
			lst = lst->next;
		}
	}
	else
	{
		while (lst->next)
		{
			if (lst->tag < lst->next->tag)
				return (0);
			lst = lst->next;
		}
	}
	return (1);
}
