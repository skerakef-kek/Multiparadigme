#include <stdio.h>
#include <stdlib.h>

typedef struct _intarray
{
	int*	data;
	int		len;
}				intarray;

/*			prototypes des fonctions 		*/
intarray	create_intarray (int len);
intarray	debug_intarray (intarray tab);
void		print_positive_values_intarray (intarray tab);
int			search_intarray (intarray tab, int n);
int			nb_occurences_intarray (intarray tab, int n);
int			get_intarray (intarray tab, int index);
void		destroy_intarray (intarray tab);
void		set_intarray (intarray tab, int index, int value);
int			length_intarray (intarray tab);
intarray	concat_intarray(intarray t1, intarray t2);
int			get_min_intarray(intarray tab);
int			get_index_min_intarray(intarray tab);
int			get_index_min_from_intarray(intarray tab, int n);
void		sort1_intarray(intarray tab);
void		swap_intarray(int* m, int* n);

/*	*/


void		destroy_intarray (intarray tab)
{
	free (tab.data);
}

intarray		create_intarray(int len)
{
	intarray tab;
	int		i;

	tab.len = len;
	tab.data = malloc (len * sizeof(int));
	for (i = 0; i < len ; i++)
		tab.data[i] = 0;
	return (tab);
}

intarray	debug_intarray(intarray tab) 
{
	int i;
	printf("[");
	for (i = 0; i < tab.len - 1; i++)
		printf("%d, ", tab.data[i]);
	printf("%d]\n", tab.data[tab.len - 1]);
}

void		print_positive_values_intarray (intarray tab)
{
	int i;

	for (i = 0; i < tab.len ; i++)
	{
		if (tab.data[i] >= 0)
			printf("%d ", tab.data[i]);
	}
}

int			search_intarray (intarray tab, int n)
{
	int i;

	for (i = 0; i < tab.len; i++)
	{
		if (tab.data[i] == n)
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
		if (tab.data[i] == n)
			count++;
	}
	return (count);
}

int			get_intarray (intarray tab, int index)
{
	if ((index < 0) || (index >= tab.len))
		{	
			printf ("get_intarray :\nIndex %d invalid\n", index);
			return (-1);
		}
	return (tab.data[index]);
}

void		set_intarray (intarray tab, int index, int value)
{
	if ((index < 0) || (index >= tab.len))
		{	
			printf ("set_intarray :\nIndex %d est invalide\n", index);
			return;
		}	
	tab.data[index] = value;
}

int			length_intarray (intarray tab)
{
	return (tab.len);
}

intarray	concat_intarray(intarray t1, intarray t2)
{
	intarray tab;
	int i, j;

	tab = create_intarray(t1.len + t2.len);
	for (i = 0; i < t1.len; i++)
		tab.data[i] = t1.data[i];
	for (j = 0; j < t2.len; j++)
		tab.data[i + j] = t2.data[j];
	return (tab);
}

int			get_min_intarray(intarray tab)
{
	int index_min = get_index_min_intarray(tab);

	return (tab.data[index_min]);
}

int			get_index_min_intarray(intarray tab)
{
	return (get_index_min_from_intarray(tab, 0));
}

int			get_index_min_from_intarray(intarray tab, int index)
{
	if ((index < 0) || (index >= tab.len))
	{
		printf ("get_index_min_from_intarray : index %d invalid value\n", index);
		return (-1);
	}
	int min = tab.data[index];
	int index_min = index;
	int i;

	for (i = index + 1; i < tab.len; i++)
	{
		if (tab.data[i] < min)
		{	
			min = tab.data[i];
			index_min = i;
		}
	}
	return (index_min);
}

void		swap_intarray(int* m, int* n)
{
	int tmp;

	tmp = *m;
	*m = *n;
	*n = tmp;
}

void		sort1_intarray(intarray tab)
{
	int i, index_min, tmp;

	for (i = 0; i <= tab.len - 2; i++)
	{
		index_min = get_index_min_from_intarray(tab, i);
		swap_intarray(tab.data + index_min, tab.data + i);
	}
}

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
