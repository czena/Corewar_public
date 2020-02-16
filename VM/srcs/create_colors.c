
#include "corewar.h"
#include "op.h"

void		create_colors(void)
{
	start_color();
	init_pair(1, 25, COLOR_BLACK);
	init_pair(2, 22, COLOR_BLACK);
	init_pair(3, 142, COLOR_BLACK);
	init_pair(4, 88, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, 8);
	init_pair(6, COLOR_BLACK, 25);
	init_pair(7, COLOR_BLACK, 22);
	init_pair(8, COLOR_BLACK, 142);
	init_pair(9, COLOR_BLACK, 88);
	init_pair(10, 8, 8);
	init_pair(11, 12, 0);
	init_pair(12, 10, 0);
	init_pair(13, 11, 0);
	init_pair(14, 9, 0);
	init_pair(16, 0, 8);
	init_pair(17, 15, 12);
	init_pair(18, 15, 10);
	init_pair(19, 15, 11);
	init_pair(20, 15, 9);
	init_pair(21, 8, 0);
}
