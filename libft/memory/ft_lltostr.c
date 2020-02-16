
#include "libft.h"

char			*ft_lltostr(long long num, unsigned base)
{
	unsigned long long	u_num;

	u_num = num;
	if (num >= 0)
	{
		return (ft_ulltostr(u_num, base));
	}
	else
	{
		u_num = -u_num;
		return (ft_ulltostr(u_num, base));
	}
}
