#ifndef __TOOLS_H__
#define __TOOLS_H__
#include <stdio.h>
#include <stdlib.h>

/*  Functions Prototypes    */

int     string_to_int (char* str);
int		safe_string_to_int (char* str, int* ok);
void		swap_int(int* m, int* n);
void		swap_char(char* m, char* n);
int     ft_strlen(char *str);

/*                          */
#endif