
#include "libft.h"

void	ft_queque_del_link(t_queue **queue)
{
	if (queue && *queue)
	{
		ft_dlist_del_link(&((*queue)->beg));
		free(*queue);
	}
	if (queue)
		*queue = NULL;
}
