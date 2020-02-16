
#include "libft.h"

void	ft_dlist_sort(t_dlist *beg, int (*cmp)(const void *, const void *))
{
	t_dlist *ptr;
	t_dlist *min;
	void	*save;

	if (!beg || !(beg->next))
		return ;
	while (beg->next)
	{
		min = beg;
		ptr = beg->next;
		while (ptr)
		{
			if (cmp(min->content, ptr->content) > 0)
				min = ptr;
			ptr = ptr->next;
		}
		if (min != beg)
		{
			save = beg->content;
			beg->content = min->content;
			min->content = save;
		}
		beg = beg->next;
	}
}
