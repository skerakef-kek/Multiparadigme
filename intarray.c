#include <stdio.h>
#include <stdlib.h>

typedef struct _intarray
{
	int*	tab;
	int		len;
}				intarray;

intarray	fill_intarray (int *tab, int len);
intarray	display_intarray (intarray tab);
void		print_positive_values_intarray (intarray tab);
int			search_intarray (intarray tab, int n);
int			nb_occurences_intarray(intarray tab, int n);

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

void		print_positive_values_intarray (intarray tab)
{
	int i;

	for (i = 0; i < tab.len ; i++)
	{
		if (tab.tab[i] < 0)
			printf("%d ", tab.tab[i]);
	}
}

int			search_intarray (intarray tab, int n)
{
	int i;

	for (i = 0; i < tab.len; i++)
	{
		if (tab.tab[i] == n)
			return (1);
	}
	return (0);
}

int			nb_occurences_intarray(intarray tab, int n)
{
	int i;
	int	count;

	count = 0;
	for (i = 0; i < tab.len; i++)
	{
		if (tab.tab[i] == n)
			count++;
	}
	return (count);
}

int			main()
{
	intarray x;
	int		tab[] = {1, 2, 10, 2, 10, 10, 10, 2};
	int		n = 2;

	x = fill_intarray(tab, 8);
	display_intarray(x);
	printf("n value : %d\nnb occurences : %d\n", n,nb_occurences_intarray(x, n));
	return (0);
}
