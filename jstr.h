#ifndef __JSTR_H__
#define __JSTR_H__
#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "intarray.h"

#define JSTR_ALLOC 8
/* "semantique par reference uniforme" */
typedef struct _jstr*	jstr;
typedef struct _jstr	s_jstr;

struct _jstr	{
	char	*data;
	int		len;
	int		alloc;
};

/*			prototypes des fonctions 		*/
jstr		create_jstr (int len);
jstr		empty_create_jstr(int alloc);
jstr		standard_empty_create_jstr(void);
jstr		regstr_to_jstr(char *str);
char		*jstr_to_regstr(jstr tab);
void		aux_create_jstr (jstr tab);
void		debug_jstr (jstr tab);
void		ext_debug_jstr (jstr tab);
void		print_positive_values_jstr (jstr tab);
int			search_jstr (jstr tab, char n);
int			nb_occurences_jstr (jstr tab, char n);
char		get_jstr (jstr tab, int index);
void		destroy_jstr (jstr tab);
void		set_jstr (jstr tab, int index, char value);
int			length_jstr (jstr tab);
jstr		concat_jstr(jstr t1, jstr t2);
void		d_concat_jstr(jstr t1, jstr t2);
char		get_min_jstr(jstr tab);
int			get_index_min_jstr(jstr tab);
int			get_index_min_from_jstr(jstr tab, int n);
void		sort1_jstr(jstr tab);
int			sum_jstr (jstr tab);
float		average_jstr (jstr tab);
jstr		clone_jstr(jstr tab);
float		median_jstr (jstr tab);
char		get_max_jstr (jstr tab);
int			get_index_max_from_jstr (jstr tab, int n);
int			get_index_max_jstr (jstr tab);
void		unsorted_delete_jstr(jstr tab, int index);
void		delete_jstr(jstr tab, int index);
void		add_jstr(jstr tab, char value);
void		ext_set_jstr (jstr tab, int index, char value);
void		resize_jstr (jstr tab, int newalloc);

int			equal_substr_jstr(jstr j1, int s1, int e1, jstr j2, int s2);
int			equal_jst(jstr j1, jstr j2);
intarray	find_substr_indices_jstr(jstr j, jstr sub);
intarray	find_proper_substr_indices_jstr(jstr j, jstr sub);
int			jstr_compare(jstr j1, jstr j2); 
/*	*/
#endif