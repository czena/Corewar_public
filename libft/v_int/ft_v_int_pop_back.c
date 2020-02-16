
#include "libft.h"

int		ft_v_int_pop_back(t_v_int *v, int *c)
{
	if (v->after_end == v->beg)
		return (0);
	--(v->after_end);
	*c = *v->after_end;
	return (1);
}
