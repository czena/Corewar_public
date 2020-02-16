
#include "libft.h"

char			*ft_ulltostr(unsigned long long num, unsigned base)
{
	unsigned long long	rank;
	char				*base_str;
	int					len_num;
	int					i;
	char				*s;

	if (base < 2 || base > 16)
		return (NULL);
	base_str = "0123456789abcdef";
	len_num = ft_ull_len_base(num, base);
	if (!(s = (char *)malloc(sizeof(*s) * (len_num + 1))))
		return (NULL);
	rank = 1;
	while (num / rank >= base)
		rank *= base;
	i = 0;
	while (rank)
	{
		s[i++] = *(base_str + (num / rank) % base);
		rank /= base;
	}
	s[i] = '\0';
	return (s);
}
