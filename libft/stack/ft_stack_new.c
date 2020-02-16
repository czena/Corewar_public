
#include "libft.h"

t_stack		*ft_stack_new(void)
{
	t_stack *st;

	if (!(st = (t_stack *)malloc(sizeof(*st))))
		return (NULL);
	st->beg = NULL;
	st->size = 0;
	return (st);
}
