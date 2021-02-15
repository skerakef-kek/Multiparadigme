#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _pendu* pendu;
typedef struct _pendu  s_pendu;

struct         _pendu {
    char tried[26];
    char *word;
    int remaining_letters;
    int remaining_tries;
};

void    s_pendu_init (pendu p, char* word, int nb_tries)
{
    int i;
    int len = strlen (word);
    char first = word[0], last = word[len - 1];

    p->word = word;
    p->remaining_tries = nb_tries;
    p->remaining_letters = len;

    for (i = 0; i < 26; i++)
        p->tried[i] = 0;
    if (len <= 1)
    {
        p->remaining_letters = 0;
        return;
    }
    p->remaining_letters -= 2;
    
    if ((first >= 'A') && (first <= 'Z'))
        p->tried[first - 'A'] = 1;

    if ((last >= 'A') && (last <= 'Z'))
        p->tried[last - 'A'] = 1;

    for (i = 1; i <= len - 2; i++)
    {
        char c = word[i];
        if ((c == last) || (c == first) || (c < 'A') || (c > 'Z'))
            p->remaining_letters--;
    }
    printf ("\nword = %s. rem. letters = %d\n", p->word, p->remaining_letters);
}

void    upper(char* str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'a') && (str[i] <= 'z'))
            str[i] += ('A' - 'a');
    }
}

void    pendu_display (p)
{
    int i;

    for (i = 0; p->word[i] != '\0'; i++)
    {
        char c = p->word[i];
        if ((p->tried[c - 'A'] == 1) || (c < 'A') || (c > 'Z'))
            printf ("%c", c);
        else
            printf("-");
    }

}

/*struct         _pendu {
    char tried[26];
    char *word;
    int remaining_letters;
    int remaining_tries;
};*/

void       pendu_play (pendu p)
{
    char letter;

    while ((p->remaining_tries > 0) && (p->remaining_letters > 0))
    {
        pendu_display (p);
        printf ("Choose a lettre : ");
        letter = pendu_choix_lettre (p);
    }
    if (p->remaining_letters == 0)
    {
        pendu_display (p);
        printf ("You win!\n");
    }
    else
    {
        printf ("You lost!\n");
        printf ("The word is %s", p->word);
    }
}

int     main(int argc, char** argv)
{
    s_pendu p;
    char* word;
    int nb_tries;

    if (argc >= 2)
        word = argv[1];
    else
        word = "Exceptionnelement";

    if (argc >= 3)
        nb_tries = atoi (argv[2]);
    else
        nb_tries = 7;
    printf ("Jeux du pendu\n");

    upper (word);

    s_pendu_init (&p, word, nb_tries);

    pendu_play (&p);    
    return (0);
}