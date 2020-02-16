
#include "libft.h"

int		ft_ll_len_base(long long num, unsigned base)
{
	unsigned long long	u_num;

	u_num = num;
	if (num >= 0)
	{
		return (ft_ull_len_base(u_num, base));
	}
	else
	{
		u_num = -u_num;
		return (ft_ull_len_base(u_num, base));
	}
}
