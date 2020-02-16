#include "asm.h"
#include "libft.h"

void	print_char(char c, const int fd, int *cur_byte)
{
	write(fd, &c, 1);
	if (cur_byte != NULL)
		*cur_byte += sizeof(c);
}

void	print_int(int int_arg, const int fd, int *cur_byte)
{
	write(fd, ((char *)(&int_arg)) + 3, 1);
	write(fd, ((char *)(&int_arg)) + 2, 1);
	write(fd, ((char *)(&int_arg)) + 1, 1);
	write(fd, ((char *)(&int_arg)), 1);
	if (cur_byte != NULL)
		*cur_byte += sizeof(int_arg);
}

void	print_short(short int sh_int_arg, const int fd, int *cur_byte)
{
	write(fd, ((char *)(&sh_int_arg)) + 1, 1);
	write(fd, ((char *)(&sh_int_arg)), 1);
	if (cur_byte != NULL)
		*cur_byte += sizeof(sh_int_arg);
}
