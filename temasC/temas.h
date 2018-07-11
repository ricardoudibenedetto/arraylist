#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre_tema[30];
    char artista[30];
}eTemas;
int parser_temas(char* fileName, ArrayList* listaTemas);
