#include <stdlib.h>
#include <stdio.h>

#include "tools.h"
#include "intarray.h"

int main (int ac, char** av)
{
    intarray tab = create_empty_intarray(ac - 1);
    int i;

    for (i = 1; i < ac; i++)
    {
        int ok;
        int n = safe_string_to_int(av[i], &ok);
        if (ok)
        {
            add_intarray(tab, n);
        }
    }    

    debug_intarray(tab);

    printf ("Quelque statistic sur notre tableau:\nSomme = %d\n", sum_intarray(tab));
    printf("Minimum : %d\n", get_min_intarray(tab));
    printf ("Maximum : %d\n", get_max_intarray(tab));
    printf ("Moyenne = %f\n", average_intarray(tab));
    printf ("Mediane = %f\n", median_intarray(tab));
    sort1_intarray(tab);
    printf("Sorted array == > ");
    debug_intarray(tab);


    destroy_intarray(tab);
    return (0);
}