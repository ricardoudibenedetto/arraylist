#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "temas.h"
#include "usuario.h"


int parser_temas(char* fileName, ArrayList* listaTemas)
{

    FILE *fp;
    eTemas* unTema;
    int id;
    char idAux[20];
    char nombre_tema[30];
    char artista[30];
    int cant;
    int retorno=-1;
    fp = fopen(fileName,"r");
    if(fp!=NULL)
    {
        while(!feof(fp))
        {
            unTema=(eTemas*)malloc(sizeof(eTemas));
            if(unTema!=NULL)
            {
                if(feof(fp))
                {
                    break;
                }
                cant=fscanf(fp,"%[^,],%[^,],%[^\n]\n", idAux,nombre_tema,artista);
                if(cant==3)
                {
                    unTema->id=atoi(idAux);
                    strcpy(unTema->artista,artista);
                    strcpy(unTema->nombre_tema,nombre_tema);

                    listaTemas->add(listaTemas,unTema);
                    retorno=1;
                }
                else
                    printf("error al leer con fscanf\n");
            }
        }

    }
    else
        printf("no se pudo leer");

    fclose(fp);
    return retorno;
}
/*
int parserTemasBin(char* fileName, ArrayList* listaTemas)
{
    FILE* b;
    eTemas *pTemas;
    pTemas=(eTemas*)malloc(sizeof(eTemas)*20);
    b=fopen(fileName, "rb");
    fread(pTemas, sizeof(eTemas),1,b);

    listaTemas->add(listaTemas,pTemas);
    fclose(b);
}

*/
