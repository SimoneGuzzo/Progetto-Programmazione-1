#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef struct
{
    char titolo[20];
    char autore[20];
    float prezzo;
    int n_dischi;
}disco;

typedef struct
{
    int codice;
    char genere[20];
    int n_dischi;
    disco array_dischi[5];
}categoria;
