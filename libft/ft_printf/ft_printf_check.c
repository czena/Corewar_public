
#include "ft_printf.h"

void		check_flag(t_print_info *info, const char **ptr)
{
	while (**ptr)
	{
		if (**ptr == '+')
			info->flags |= flag_plus;
		else if (**ptr == '-')
			info->flags |= flag_minus;
		else if (**ptr == ' ')
			info->flags |= flag_space;
		else if (**ptr == '#')
			info->flags |= flag_hash;
		else if (**ptr == '0')
			info->flags |= flag_zero;
		else
			return ;
		++(*ptr);
	}
	return ;
}

static int	check_lsize(t_print_info *info, const char **ptr)
{
	if (**ptr == 'l')
	{
		++(*ptr);
		if (**ptr == 'l')
		{
			++(*ptr);
			info->size_type = size_ll;
		}
		else
		{
			info->size_type = size_l;
		}
		return (1);
	}
	return (0);
}

static int	check_hsize(t_print_info *info, const char **ptr)
{
	if (**ptr == 'h')
	{
		++(*ptr);
		if (**ptr == 'h')
		{
			++(*ptr);
			info->size_type = size_hh;
		}
		else
		{
			info->size_type = size_h;
		}
		return (1);
	}
	return (0);
}

void		check_size(t_print_info *info, const char **ptr)
{
	if (!check_lsize(info, ptr))
	{
		if (!check_hsize(info, ptr))
		{
			if (**ptr == 'L')
			{
				++(*ptr);
				info->size_type = size_L;
			}
			else
			{
				info->size_type = size_default;
			}
		}
	}
}

int			check_type(t_print_info *info, const char **ptr)
{
	if (**ptr == 'x')
		info->type = type_x;
	else if (**ptr == 'X')
		info->type = type_X;
	else if (**ptr == 'd')
		info->type = type_d;
	else if (**ptr == 'i')
		info->type = type_i;
	else if (**ptr == 'o')
		info->type = type_o;
	else if (**ptr == 'u')
		info->type = type_u;
	else if (**ptr == 'f')
		info->type = type_f;
	else if (**ptr == 'c')
		info->type = type_c;
	else if (**ptr == 's')
		info->type = type_s;
	else if (**ptr == 'p')
		info->type = type_p;
	else if (**ptr == '%')
		info->type = type_percent;
	else
		return (-1);
	return (*(++(*ptr)) & 0);
}
