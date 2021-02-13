#include "intarray.h"

int			main()
{
	intarray tab = create_intarray(6);
	int i;

	set_intarray(tab, 0, 1);
	set_intarray(tab, 1, 2);
	set_intarray(tab, 2, 3);
	set_intarray(tab, 3, 4);
	set_intarray(tab, 4, 6);
	set_intarray(tab, 5, -2);
	
	debug_intarray (tab);
	
	printf ("Sum of value %d\n", sum_intarray(tab));
	printf ("Average value %f\n", average_intarray(tab));
	printf ("Median value %f\n", median_intarray(tab));


	debug_intarray (tab);

	destroy_intarray(tab);

	return (0);
}