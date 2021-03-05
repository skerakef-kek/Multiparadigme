#include "intarray.h"

void		destroy_intarray (intarray tab)
{
	free (tab->data);
	free (tab);
}
intarray	standard_empty_create_intarray(void)
{
	return (empty_create_intarray(INTARRAY_ALLOC));
}

void	aux_create_intarray (intarray tab)
{
	int i;
	if (tab->alloc <= 0)
	{
		tab->alloc = 4;
		printf ("aux_create_intarray : taille allouee <= 0 \n");
		printf ("nous allouons %d a la place\n", tab->alloc);
	}
	
	tab->data = malloc (tab->alloc * sizeof(int));
	for (i = 0; i < tab->alloc ; i++)
		tab->data[i] = 0;
}

intarray		create_intarray(int len)
{
	intarray tab = malloc (sizeof(s_intarray));
	tab->len = len;
	tab->alloc = len;
	aux_create_intarray (tab); 
	return (tab);
}

intarray	empty_create_intarray(int alloc)
{
	intarray tab = malloc (sizeof(s_intarray));
	tab->len = 0;
	tab->alloc = alloc;
	aux_create_intarray(tab);
	return (tab);
}

void		debug_intarray(intarray tab) 
{
	int i;
	printf("[ ");
	for (i = 0; i < tab->len - 1; i++)
		printf("%d, ", tab->data[i]);
	if (tab->len > 0)
		printf("%d", tab->data[tab->len - 1]);
	printf(" ]\n");
}

void		ext_debug_intarray (intarray tab)
{
	printf ("tab. alloc = %d ; tab. len = %d\n\n", tab->alloc, tab->len);
	debug_intarray (tab);
}
void		print_positive_values_intarray (intarray tab)
{
	int i;

	for (i = 0; i < tab->len ; i++)
	{
		if (tab->data[i] >= 0)
			printf("%d ", tab->data[i]);
	}
}

int			search_intarray (intarray tab, int n)
{
	int i;

	for (i = 0; i < tab->len; i++)
	{
		if (tab->data[i] == n)
			return (1);
	}
	return (0);
}

int			nb_occurences_intarray(intarray tab, int n)
{
	int i;
	int	count;

	count = 0;
	for (i = 0; i < tab->len; i++)
	{
		if (tab->data[i] == n)
			count++;
	}
	return (count);
}

int			get_intarray (intarray tab, int index)
{
	if ((index < 0) || (index >= tab->len))
		{	
			printf ("get_intarray :\nIndex %d invalid\n", index);
			return (-1);
		}
	return (tab->data[index]);
}

void		set_intarray (intarray tab, int index, int value)
{
	if ((index < 0) || (index >= tab->len))
		{	
			printf ("set_intarray :\nIndex %d est invalide\n", index);
			return;
		}	
	tab->data[index] = value;
}

int			length_intarray (intarray tab)
{
	return (tab->len);
}

intarray	concat_intarray(intarray t1, intarray t2)
{
	intarray tab;
	int i, j;

	tab = create_intarray(t1->len + t2->len);
	for (i = 0; i < t1->len; i++)
		tab->data[i] = t1->data[i];
	for (j = 0; j < t2->len; j++)
		tab->data[i + j] = t2->data[j];
	return (tab);
}

int			get_min_intarray(intarray tab)
{
	int index_min = get_index_min_intarray(tab);

	return (tab->data[index_min]);
}

int			get_index_min_intarray(intarray tab)
{
	return (get_index_min_from_intarray(tab, 0));
}

int			get_index_min_from_intarray(intarray tab, int index)
{
	if ((index < 0) || (index >= tab->len))
	{
		printf ("get_index_min_from_intarray : index %d invalid value\n", index);
		return (-1);
	}
	int min = tab->data[index];
	int index_min = index;
	int i;

	for (i = index + 1; i < tab->len; i++)
	{
		if (tab->data[i] < min)
		{	
			min = tab->data[i];
			index_min = i;
		}
	}
	return (index_min);
}

intarray	clone_intarray(intarray tab)
{
	int i;
	intarray copy = create_intarray(tab->len);

	for (i = 0; i < copy->len; i++)
		copy->data[i] = tab->data[i];
	return (copy);
}

void		sort1_intarray(intarray tab)
{
	int i, index_min, tmp;

	for (i = 0; i <= tab->len - 2; i++)
	{
		index_min = get_index_min_from_intarray(tab, i);
		swap_int(tab->data + index_min, tab->data + i);
	}
}

int			sum_intarray (intarray tab)
{
	int sum = 0;
	int i;
	for (i = 0; i < tab->len; i++)	
		sum += tab->data[i];
	if (tab->len == 0)
		printf ("sum_intarray : len tab = 0\n");
	return (sum);
}

float		average_intarray (intarray tab)
{
	int sum = sum_intarray(tab);
	if (tab->len == 0)
	{
		printf ("sum_intarray : len tab = 0\n");
		return (-1.0);
	}
	return ((float)sum / tab->len);
}

float		median_intarray (intarray tab)
{
	intarray copy = clone_intarray(tab);
	sort1_intarray(copy);
	float	median;
	
	if (tab->len == 0)
	{	
		printf ("sum_intarray : len tab = 0");
		return (-1.0);
	}
	if (copy->len % 2 == 0)
	{
		int v1 = copy->data[(copy->len - 1) / 2];
		int v2 = copy->data[(copy->len) / 2];
		median = ((float)(v1 + v2) / 2);
	}	
	else
		median = (copy->data[(copy->len - 1) / 2]);
	destroy_intarray(copy);
	return (median);
}

int			get_max_intarray (intarray tab)
{
	int index_max = get_index_max_intarray(tab);
	return (tab->data[index_max]);
}

int			get_index_max_intarray (intarray tab)
{
	int index_max = get_index_max_from_intarray (tab, 0);
	return (index_max);
}

int			get_index_max_from_intarray (intarray tab, int index)
{
	int max = tab->data[index];
	int index_max = index;
	int i;

	if ((index < 0) || (index >= tab->len))
	{
		printf ("get_index_max_from_intarray : index %d invalid value\n", index);
		return (-1);
	}
	for (i = index + 1; i <= tab->len - 1; i++)
	{
		if (tab->data[i] > max)
		{
			max = tab->data[i];
			index_max = i;
		}
	}
	return (index_max);
}

void		unsorted_delete_intarray(intarray tab, int index)
{
	if ((index >= tab->len) || (index < 0))
	{
		printf ("unsorted_delete_intarray: index invalid\n");
		return;
	}
	tab->data[index] = tab->data[tab->len - 1];
	tab->len--;
}

void		delete_intarray(intarray tab, int index)
{
	int i;
	if ((index >= tab->len) || (index < 0))
	{
		printf ("unsorted_delete_intarray: index invalid\n");
		return;
	}

	for (i = index + 1; i < tab->len; i++)
		tab->data[i - 1] = tab->data[i];
	tab->len--;
}
void		resize_intarray (intarray tab, int newalloc)
{
	int* newdata = malloc (sizeof (int) * newalloc);
	int i;

	for (i = 0; i < tab->len; i++)
		newdata[i] = tab->data[i];
	free (tab->data);
	tab->data = newdata;
	tab->alloc = newalloc;
}

void		ext_set_intarray (intarray tab, int index, int value)
{
	int i;

	printf ("Added value %d to case number %d ;\n", value, index);
	if (index < 0)
	{
		printf ("ext_set_intarray : index negative");
		return;
	}
	if (index < tab->len)
	{
		tab->data[index] = value;
		return;
	}
	if (index >= tab->alloc)
		resize_intarray (tab, 1 + 2 * index);
	for (i = tab->len; i < index ; i++)
		tab->data[i] = 0;
	tab->data[index] = value;
	if (index >= tab->len)
		tab->len = index + 1;

}

void		add_intarray(intarray tab, int value)
{
	ext_set_intarray(tab, tab->len, value);
}



/*	
	0 1 2 3 4 5 6 7    				tab->len = 5
	4 5 2 2 5 . . .	. .				tab->alloc = 8

	ext_set_intarray(tab, 9, 10);
*/