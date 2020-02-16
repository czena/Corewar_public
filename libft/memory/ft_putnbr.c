
#include "libft.h"

static void		ft_rec(unsigned n)
{
	if (n < 10)
		ft_putchar('0' + n);
	else
	{
		ft_rec(n / 10);
		ft_rec(n % 10);
	}
}

void			ft_putnbr(int n)
{
	long lnum;

	lnum = n;
	if (n < 0)
	{
		ft_putchar('-');
		lnum = -lnum;
	}
	ft_rec(lnum);
}
