
#include "libft.h"

void	ft_dlist_del_link(t_dlist **lst)
{
	if (lst == NULL)
		return ;
	while (*lst)
	{
		ft_dlist_delone_link(lst, *lst);
	}
	*lst = NULL;
}
