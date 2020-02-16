
#include "libft.h"

t_dlist		*ft_dlist_addfront_link(t_dlist **lst, void *data, int tag)
{
	t_dlist		*ptr;

	if (!lst || !(ptr = (t_dlist *)malloc(sizeof(*ptr))))
		return (NULL);
	ptr->content = data;
	ptr->tag = tag;
	ptr->prev = NULL;
	ptr->next = *lst;
	if (*lst != NULL)
		(*lst)->prev = ptr;
	*lst = ptr;
	return (*lst);
}
