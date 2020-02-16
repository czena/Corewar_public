#include "asm.h"
#include "libft.h"

int				find_str(void *s1, void *s2)
{
	char		*str1;
	char		*str2;

	str2 = (char *)s2;
	str1 = ((t_token *)(s1))->name;
	return (ft_strcmp(str1, str2));
}
