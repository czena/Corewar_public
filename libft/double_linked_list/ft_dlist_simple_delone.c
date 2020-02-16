
#include "libft.h"

void	ft_dlist_simple_delone(t_dlist **lst, t_dlist *ptr)
{
	ft_dlist_delone(lst, ptr, free);
}
