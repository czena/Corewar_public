
#include "libft.h"

int		ft_v_int_push_back(t_v_int *v, int value)
{
	if ((size_t)(v->after_end - v->beg) >= v->max_size)
		if (ft_v_int_realloc(v, v->max_size * 2) == -1)
			return (-1);
	*v->after_end = value;
	++(v->after_end);
	return (0);
}
