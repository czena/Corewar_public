
#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

static void		with_width(t_print_info *info, char **s, int *len)
{
	if (info->flags & flag_minus)
	{
		ft_join_nsym(s, 1, info->width - *len, ' ');
	}
	else
	{
		if (info->flags & flag_zero)
			ft_join_nsym(s, 0, info->width - *len, '0');
		else
			ft_join_nsym(s, 0, info->width - *len, ' ');
	}
	*len = info->width;
}

static int		print_u_continue(t_print_info *info,
									unsigned long long num)
{
	char	*s;
	int		len;

	if (!(s = ull_base(num, info)))
		return (0);
	len = ft_strlen(s);
	if (info->precision > len)
	{
		ft_join_nsym(&s, 0, info->precision - len, '0');
		len = ft_strlen(s);
	}
	if (info->precision >= 0)
		info->flags = info->flags & (~flag_zero);
	if (info->width > len)
	{
		with_width(info, &s, &len);
	}
	write(1, s, len);
	free(s);
	return (len);
}

int				print_u(t_print_info *info, va_list params)
{
	unsigned long long	ull_num;

	if (info->size_type == size_ll)
		ull_num = va_arg(params, unsigned long long int);
	else if (info->size_type == size_l)
		ull_num = va_arg(params, unsigned long int);
	else
		ull_num = va_arg(params, unsigned int);
	if (info->size_type == size_hh)
		ull_num = (unsigned char)ull_num;
	else if (info->size_type == size_h)
		ull_num = (unsigned short int)ull_num;
	if (info->precision == 0 && ull_num == 0)
	{
		ft_put_nsym(info->width, ' ');
		return (info->width);
	}
	return (print_u_continue(info, ull_num));
}
