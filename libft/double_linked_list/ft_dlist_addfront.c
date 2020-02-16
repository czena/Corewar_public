
#include "libft.h"

t_dlist		*ft_dlist_addfront(t_dlist **lst, void *data, size_t size, int tag)
{
	t_dlist		*ptr;

	if (!lst || !(ptr = (t_dlist *)malloc(sizeof(*ptr))))
		return (NULL);
	if (!(ptr->content = (void *)malloc(size)))
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(ptr->content, data, size);
	ptr->tag = tag;
	ptr->prev = NULL;
	ptr->next = *lst;
	if ((*lst) != NULL)
		(*lst)->prev = ptr;
	*lst = ptr;
	return (*lst);
}
