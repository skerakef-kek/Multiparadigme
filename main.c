#include "intarray.h"
#include "tools.h"

int			main(int argc, char** argv)
{
	intarray tab = create_intarray(0);
	int i;

	ext_debug_intarray (tab);
	
	for (i = 0; i < 10; i++)
		add_intarray(tab, 1 + i);

	destroy_intarray(tab);
	return (0);
}