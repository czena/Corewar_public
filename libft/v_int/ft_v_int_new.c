
#include "libft.h"

t_v_int		*ft_v_int_new(size_t size)
{
	t_v_int *new;

	if (size == 0 || !(new = (t_v_int *)malloc(sizeof(*new))))
		return (NULL);
	if (!(new->beg = ft_memalloc(size * sizeof(*new->beg))))
	{
		free(new);
		return (NULL);
	}
	new->after_end = new->beg;
	new->max_size = size;
	return (new);
}
