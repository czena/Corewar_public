
#include "libft.h"

t_dlist		*ft_dlist_create_el(void *el, int tag)
{
	t_dlist *ptr;

	if (!(ptr = (t_dlist *)malloc(sizeof(*ptr))))
		return (NULL);
	ptr->content = el;
	ptr->tag = tag;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}
