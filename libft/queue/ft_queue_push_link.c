
#include "libft.h"

int		ft_queue_push_link(t_queue *queue, void *el, int tag)
{
	if (!queue)
		return (-1);
	if (!ft_dlist_addfront_link(&(queue->beg), el, tag))
		return (-1);
	if (queue->size == 0)
		queue->end = queue->beg;
	queue->size += 1;
	return (0);
}
