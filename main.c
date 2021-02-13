#include "intarray.h"

int			main()
{
	intarray tab = create_intarray(10);
	int i;

	set_intarray(tab, 0, 10);
	set_intarray(tab, 1, 14);
	set_intarray(tab, 2, 8);
	set_intarray(tab, 3, -52);
	set_intarray(tab, 4, -37);
	set_intarray(tab, 5, -214);
	set_intarray(tab, 6, -24);
	set_intarray(tab, 7, -224);
	set_intarray(tab, 8, -24);
	set_intarray(tab, 9, 5);
	
	debug_intarray(tab);

	sort1_intarray(tab);

	debug_intarray(tab);
	
	destroy_intarray(tab);

	return (0);
}