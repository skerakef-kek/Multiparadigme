#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

/* "semantique par reference uniforme" */
typedef struct _intarray*	intarray;
typedef struct _intarray	s_intarray;

struct _intarray	{
	int*	data;
	int		len;
	int		alloc;
};

/*			prototypes des fonctions 		*/

intarray	create_intarray (int len);
intarray	empty_create_intarray(int alloc);
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
int			sum_intarray (intarray tab);
float		average_intarray (intarray tab);
intarray	clone_intarray(intarray tab);
float		median_intarray (intarray tab);
int			get_max_intarray (intarray tab);
int			get_index_max_from_intarray (intarray tab, int n);
int			get_index_max_intarray (intarray tab);
void		unsorted_delete_intarray(intarray tab, int index);
void		delete_intarray(intarray tab, int index);
void		add_intarray(intarray tab, int value);

/*	*/