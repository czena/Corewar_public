
#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*prev;

	if (alst == NULL || del == NULL || *alst == NULL)
		return ;
	next = (*alst)->next;
	prev = (*alst);
	while (next != NULL)
	{
		ft_lstdelone(&prev, del);
		prev = next;
		next = next->next;
	}
	ft_lstdelone(&prev, del);
	*alst = NULL;
}
