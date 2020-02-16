
#include "libft.h"

int		ft_ull_len_base(unsigned long long num, unsigned base)
{
	int count;

	count = 0;
	if (base < 2 || base > 16)
		return (0);
	if (num == 0)
		return (1);
	while (num)
	{
		num /= base;
		++count;
	}
	return (count);
}
