
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

int		print_c(t_print_info *info, va_list params)
{
	char c;

	c = va_arg(params, int);
	if (info->width <= 1)
		write(1, &c, 1);
	else
	{
		if (info->flags & flag_minus)
		{
			write(1, &c, 1);
			ft_put_nsym(info->width - 1, ' ');
		}
		else
		{
			ft_put_nsym(info->width - 1, ' ');
			write(1, &c, 1);
		}
	}
	return (info->width <= 1 ? 1 : info->width);
}
