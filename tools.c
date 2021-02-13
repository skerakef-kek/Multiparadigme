#include "tools.h"

int     string_to_int (char* str)
{
    int ok;
    int n = safe_string_to_int(str, &ok);
    if (ok == 0)
        printf ("string_to_int : chaine de character %s invalide \n", str);
    return (n);
}

int		safe_string_to_int (char* str, int* ok)
{
    int i;
    int n = 0;
    *ok = 1;

    if (!(*str))
    {   
        *ok = 0;
        return (0);
    }
    for (i = 0; (str[i] != '\0'); i++)
    {
        if ((str[i] < '0') || (str[i] > '9'))
            *ok = 0;
        n *= 10;
        n += (str[i] - 48);
    }
    return (n);
}

int     main()
{
    char* str = "125b242";
    int n = string_to_int(str);
    printf ("%d\n", n);
    return (0);
}