#include "jstr.h"

void		destroy_jstr (jstr tab)
{
	free (tab->data);
	free (tab);
}
jstr	standard_empty_create_jstr(void)
{
	return (empty_create_jstr(JSTR_ALLOC));
}

void	aux_create_jstr (jstr tab)
{
	int i;
	if (tab->alloc <= 0)
	{
		tab->alloc = 4;
		printf ("aux_create_jstr : taille allouee <= 0 \n");
		printf ("nous allouons %d a la place\n", tab->alloc);
	}
	
	tab->data = malloc (tab->alloc * sizeof(char));
	for (i = 0; i < tab->alloc ; i++)
		tab->data[i] = 0;
}

jstr		create_jstr(int len)
{
	jstr tab = malloc (sizeof(s_jstr));
	tab->len = len;
	tab->alloc = len;
	aux_create_jstr (tab); 
	return (tab);
}

jstr	empty_create_jstr(int alloc)
{
	jstr tab = malloc (sizeof(s_jstr));
	tab->len = 0;
	tab->alloc = alloc;
	aux_create_jstr(tab);
	return (tab);
}

jstr		regstr_to_jstr(char *str)
{
	jstr	tab = standard_empty_create_jstr();

	for (int i = 0; str[i]; i++)
		add_jstr(tab, str[i]);
	return (tab);
}

char		*jstr_to_regstr(jstr tab)
{	
	char *str = (char *)malloc(sizeof(char) * (tab->len + 1));
	int i;

	for (i = 0; i <= tab->len; i++)
		str[i] = tab->data[i];
	str[i] = '\0';
	return (str);
}

void		debug_jstr(jstr tab) 
{
	int i;
	for (i = 0; i < tab->len; i++)
		printf("%c", tab->data[i]);
}

void		ext_debug_jstr (jstr tab)
{
	printf ("tab. alloc = %d ; tab. len = %d\n", tab->alloc, tab->len);
	debug_jstr (tab);
}
void		print_positive_values_jstr (jstr tab)
{
	int i;

	for (i = 0; i < tab->len ; i++)
	{
		if (tab->data[i] >= 0)
			printf("%d ", tab->data[i]);
	}
}

int			search_jstr (jstr tab, char n)
{
	int i;

	for (i = 0; i < tab->len; i++)
	{
		if (tab->data[i] == n)
			return (1);
	}
	return (0);
}

int			nb_occurences_jstr(jstr tab, char n)
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

char		get_jstr (jstr tab, int index)
{
	if ((index < 0) || (index >= tab->len))
		{	
			printf ("get_jstr :\nIndex %d invalid\n", index);
			return (-1);
		}
	return (tab->data[index]);
}

void		set_jstr (jstr tab, int index, char value)
{
	if ((index < 0) || (index >= tab->len))
		{	
			printf ("set_jstr :\nIndex %d est invalide\n", index);
			return;
		}	
	tab->data[index] = value;
}

int			length_jstr (jstr tab)
{
	return (tab->len);
}

jstr	concat_jstr(jstr t1, jstr t2)
{
	jstr tab;
	int i, j;

	tab = create_jstr(t1->len + t2->len);
	for (i = 0; i < t1->len; i++)
		tab->data[i] = t1->data[i];
	for (j = 0; j < t2->len; j++)
		tab->data[i + j] = t2->data[j];
	return (tab);
}

char		get_min_jstr(jstr tab)
{
	int index_min = get_index_min_jstr(tab);

	return (tab->data[index_min]);
}

int			get_index_min_jstr(jstr tab)
{
	return (get_index_min_from_jstr(tab, 0));
}

int			get_index_min_from_jstr(jstr tab, int index)
{
	if ((index < 0) || (index >= tab->len))
	{
		printf ("get_index_min_from_jstr : index %d invalid value\n", index);
		return (-1);
	}
	char min = tab->data[index];
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

jstr	clone_jstr(jstr tab)
{
	int i;
	jstr copy = create_jstr(tab->len);

	for (i = 0; i < copy->len; i++)
		copy->data[i] = tab->data[i];
	return (copy);
}

void		sort1_jstr(jstr tab)
{
	int i, index_min, tmp;

	for (i = 0; i <= tab->len - 2; i++)
	{
		index_min = get_index_min_from_jstr(tab, i);
		swap_char(tab->data + index_min, tab->data + i);
	}
}

int			sum_jstr (jstr tab)
{
	int sum = 0;
	int i;
	for (i = 0; i < tab->len; i++)	
		sum += ((int) tab->data[i]);
	if (tab->len == 0)
		printf ("sum_jstr : len tab = 0\n");
	return (sum);
}

float		average_jstr (jstr tab)
{
	int sum = sum_jstr(tab);
	if (tab->len == 0)
	{
		printf ("sum_jstr : len tab = 0\n");
		return (-1.0);
	}
	return ((float)sum / tab->len);
}

float		median_jstr (jstr tab)
{
	jstr copy = clone_jstr(tab);
	sort1_jstr(copy);
	float	median;
	
	if (tab->len == 0)
	{	
		printf ("sum_jstr : len tab = 0");
		return (-1.0);
	}
	if (copy->len % 2 == 0)
	{
		int v1 = ((int) copy->data[(copy->len - 1) / 2]);
		int v2 = ((int)copy->data[(copy->len) / 2]);
		median = ((float)(v1 + v2) / 2);
	}	
	else
		median = ((float)(copy->data[(copy->len - 1) / 2]));
	destroy_jstr(copy);
	return (median);
}

char		get_max_jstr (jstr tab)
{
	int index_max = get_index_max_jstr(tab);
	return (tab->data[index_max]);
}

int			get_index_max_jstr (jstr tab)
{
	int index_max = get_index_max_from_jstr (tab, 0);
	return (index_max);
}

int			get_index_max_from_jstr (jstr tab, int index)
{
	char max = tab->data[index];
	int index_max = index;
	int i;

	if ((index < 0) || (index >= tab->len))
	{
		printf ("get_index_max_from_jstr : index %d invalid value\n", index);
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

void		unsorted_delete_jstr(jstr tab, int index)
{
	if ((index >= tab->len) || (index < 0))
	{
		printf ("unsorted_delete_jstr: index invalid\n");
		return;
	}
	tab->data[index] = tab->data[tab->len - 1];
	tab->len--;
}

void		delete_jstr(jstr tab, int index)
{
	int i;
	if ((index >= tab->len) || (index < 0))
	{
		printf ("unsorted_delete_jstr: index invalid\n");
		return;
	}

	for (i = index + 1; i < tab->len; i++)
		tab->data[i - 1] = tab->data[i];
	tab->len--;
}
void		resize_jstr (jstr tab, int newalloc)
{
	char *newdata = malloc (sizeof (char) * newalloc);
	int i;

	for (i = 0; i < tab->len; i++)
		newdata[i] = tab->data[i];
	free (tab->data);
	tab->data = newdata;
	tab->alloc = newalloc;
}

void		ext_set_jstr (jstr tab, int index, char value)
{
	int i;

	if (index < 0)
	{
		printf ("ext_set_jstr : index negative");
		return;
	}
	if (index < tab->len)
	{
		tab->data[index] = value;
		return;
	}
	if (index >= tab->alloc)
		resize_jstr (tab, 1 + 2 * index);
	for (i = tab->len; i < index ; i++)
		tab->data[i] = 0;
	tab->data[index] = value;
	if (index >= tab->len)
		tab->len = index + 1;

}

void		 add_jstr(jstr tab, char value)
{
	ext_set_jstr(tab, tab->len, value);
}

int			equal_jst(jstr j1, jstr j2)
{
	int i;
	if (j1->len != j2->len)
		return (0);
	else
		for (i = 0; i <= j1->len; i++)
			if (j1->data[i] != j2->data[i])
				return (0);
	return (1);
}

void		d_concat_jstr(jstr t1, jstr t2)
{
	int i;
	for (i = 0; i < t2->len; i++)
		add_jstr(t1, t2->data[i]);
}

/*	
	0 1 2 3 4 5 6 7    				tab->len = 5
	4 5 2 2 5 . . .	. .				tab->alloc = 8

	ext_set_jstr(tab, 9, 10);
*/