
#include "libft.h"

void	ft_dlist_del(t_dlist **lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	while (*lst)
	{
		ft_dlist_delone(lst, *lst, del);
	}
	*lst = NULL;
}
