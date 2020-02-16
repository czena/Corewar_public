
#include "libft.h"

t_queue		*ft_queue_new(void)
{
	t_queue *ptr;

	if (!(ptr = (t_queue *)malloc(sizeof(*ptr))))
		return (NULL);
	ptr->size = 0;
	ptr->beg = NULL;
	ptr->end = NULL;
	return (ptr);
}
