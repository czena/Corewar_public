
#include "libft.h"

int		ft_v_int_init(t_v_int *v, size_t size)
{
	if (size == 0)
		return (0);
	if (!(v->beg = ft_memalloc(size * sizeof(*v->beg))))
		return (-1);
	v->after_end = v->beg;
	v->max_size = size;
	return (1);
}
