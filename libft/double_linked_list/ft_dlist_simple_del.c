
#include "libft.h"

void	ft_dlist_simple_del(t_dlist **lst)
{
	ft_dlist_del(lst, free);
}
