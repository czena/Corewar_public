
#include "ft_printf.h"
#include <unistd.h>
#include "libft.h"

int			print_percent(t_print_info *info)
{
	if (info->width <= 1)
		write(1, "%", 1);
	else
	{
		if (info->flags & flag_minus)
		{
			write(1, "%", 1);
			ft_put_nsym(info->width - 1, ' ');
		}
		else
		{
			if (info->flags & flag_zero)
				ft_put_nsym(info->width - 1, '0');
			else
				ft_put_nsym(info->width - 1, ' ');
			write(1, "%", 1);
		}
	}
	return (info->width <= 1 ? 1 : info->width);
}
