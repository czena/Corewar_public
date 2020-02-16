
#include "libft.h"

void		*ft_queue_pop(t_queue *queue)
{
	void	*ptr;
	t_dlist	*del;

	ptr = NULL;
	if (queue && queue->end)
	{
		ptr = queue->end->content;
		del = queue->end;
		queue->end = queue->end->prev;
		ft_dlist_delone_link(&(queue->beg), del);
		queue->size--;
	}
	return (ptr);
}
