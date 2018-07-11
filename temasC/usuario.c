#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "temas.h"
#include "usuario.h"


int parser_Usuarios(char* fileName, ArrayList* listaUsuarios)
{

    FILE *fp;
    eUsuario* unUsuario;


    int id;
    char idAux[20];
    char nombre[50];
    char email[50];
    char sexo;
    char pais[50];
    char password[50];
    char ipAddress[50];

    int cant;
    int retorno=-1;
    fp = fopen(fileName,"r");
    if(fp!=NULL)
    {
        while(!feof(fp))
        {
            unUsuario=(eUsuario*)malloc(sizeof(eUsuario));
            if(unUsuario!=NULL)
            {
                if(feof(fp))
                {
                    break;
                }
                cant=fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux,nombre,email,sexo,pais,password,ipAddress);
                if(cant==3)
                {
                    unUsuario->id=atoi(idAux);
                    strcpy(unUsuario->nombre,nombre);
                    strcpy(unUsuario->email,email);
                    strcpy(unUsuario->sexo,sexo);
                    strcpy(unUsuario->pais,pais);
                    strcpy(unUsuario->password,password);
                    strcpy(unUsuario->ipAddress,ipAddress);

                    listaUsuarios->add(listaUsuarios,unUsuario);
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
