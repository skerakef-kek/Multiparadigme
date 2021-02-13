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
void		swap_int(int* m, int* n);
int			sum_intarray (intarray tab);
float		average_intarray (intarray tab);
intarray	clone_intarray(intarray tab);
float		median_intarray (intarray tab);

int			get_max_intarray (intarray tab);
int			get_index_max_from_intarray (intarray tab);
int			get_index_max_intarray (intarray tab);

/*	*/