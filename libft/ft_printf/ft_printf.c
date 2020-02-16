
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list		params;
	int			ret_value;

	va_start(params, format);
	ret_value = parser(format, params);
	va_end(params);
	return (ret_value);
}
