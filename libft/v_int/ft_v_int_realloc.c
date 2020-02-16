
#include "libft.h"

int		ft_v_int_realloc(t_v_int *v, size_t size)
{
	size_t	min_size;
	int		*new;
	size_t	offset;

	min_size = size < v->max_size ? size : v->max_size;
	if (size == v->max_size)
		return (0);
	if (!(new = (int *)malloc(size * sizeof(*new))))
		return (-1);
	ft_memcpy(v->beg, new, min_size * sizeof(*new));
	offset = v->after_end - v->beg;
	v->after_end = new + (offset < size ? offset : size);
	free(v->beg);
	v->beg = new;
	return (1);
}
