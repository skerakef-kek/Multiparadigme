#include <stdio.h>
#include <stdlib.h>

typedef struct _intarray
{
	int*	tab;
	int	len;
}intarray;


intarray	fill_intarray(int *tab, int len)
{
	intarray	x;

	x.tab = tab;
	x.len = len;
	return (x);
}
intarray	display_intarray(intarray tab)
{
	int i;
	printf("[");
	for (i = 0; i < tab.len - 1; i++)
		printf("%d, ", tab.tab[i]);
	printf("%d]\n", tab.tab[tab.len - 1]);
}

int			main()
{
	intarray x;
	int		tab[] = {1, 2, 3, 4};

	x = fill_intarray(tab, 4);
	display_intarray(x);
	return (0);
}
