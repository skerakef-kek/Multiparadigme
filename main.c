#include "intarray.h"
#include "tools.h"

int			main(int argc, char** argv)
{
	intarray tab = create_intarray(10);
	int i;
	intarray tmp = empty_create_intarray(0);

	for (i = 0; i < tab->len; i++)
		tab->data[i] = 2 * i - 1;
	
	debug_intarray (tab);
	
	delete_intarray(tab, 0);	

	add_intarray(tab, 20);



	debug_intarray (tab);

	printf ("TMP = ");
	debug_intarray(tmp);

	destroy_intarray (tmp);
	destroy_intarray(tab);
	return (0);
}