#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "libreria.h"

ePersona* newPersona()
{
    ePersona* returnAux=NULL;
    ePersona* unaPersona=(ePersona*)malloc(sizeof(ePersona));
    if(unaPersona!=NULL)
    {
        strcpy(unaPersona->nombre,"");
        unaPersona->edad=0;
        unaPersona->id=0;
        returnAux=unaPersona;
    }
    return returnAux;
}


int menu()
{
    int opcion;

    system("cls");
    printf("Menu de opciones principales\n\n");
    printf("1-++++\n");
    printf("2-++++\n");
    printf("3-+++++\n");
    printf("4-+++++\n");
    printf("5-+++++\n");
    printf("6-++++++\n");
    printf("7-+++++\n");

    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


int parser(char* fileName, ArrayList* lista)
{

    FILE *fp;
    Empleado* unEmpleado;


    int id;
    char idAux[20];
    char horasAux[20];
    char nombre[128];
    int horasTrabajadas;

    int cant;

    int retorno=-1;
    fp = fopen(fileName,"r");
    if(fp!=NULL)
    {
        while(!feof(fp))
        {
            unEmpleado=(Empleado*)malloc(sizeof(Empleado));
            if(unEmpleado!=NULL)
            {
                if(feof(fp))
                {
                    break;
                }
                cant=fscanf(fp,"%[^,],%[^,],%[^\n]\n", idAux,nombre,horasAux);
                if(cant==3)
                {
                    unEmpleado->id=atoi(idAux);
                    unEmpleado->horasTrabajadas=atoi(horasAux);
                    strcpy(unEmpleado->nombre,nombre);

                    lista->add(lista,unEmpleado);
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




int generarArchivo(char* fileName,ArrayList* lista)
{
    int i;
    Empleado *Emp;
    FILE *b;
    b=fopen(fileName, "w");

    for(i=1; i<lista->len(lista); i++)
    {
        Emp=lista->get(lista,i);

        fprintf(b,"%d,%s,%d,%d\n",Emp->id,Emp->nombre,Emp->horasTrabajadas,Emp->sueldo);
    }
    fclose(b);

    return 1;
}

void ordenarTareas(ArrayList* totalTareas,ArrayList* tareasAlta, ArrayList* tareasBaja)
{
    eTarea* unaTarea=newTarea();
    int i;
    for(i=0;i<totalTareas->len(totalTareas);i++)
    {
        unaTarea=totalTareas->get(totalTareas,i);
        if(unaTarea->prioridad==1)
        {
            tareasAlta->add(tareasAlta,unaTarea);
        }
        if(unaTarea->prioridad==0)
        {
            tareasBaja->add(tareasBaja,unaTarea);
        }
    }
    totalTareas->clear(totalTareas);
}



int ordenarPorNombre(void* usuarioA,void* usuarioB)
{
    int returnAux=0;
    if(strcmp(((eUsuario*)usuarioA)->email , ((eUsuario*)usuarioB)->email)<0)
    {
        returnAux=1;
    }
    if(strcmp(((eUsuario*)usuarioA)->email , ((eUsuario*)usuarioB)->email)>0)
    {
        returnAux=-1;
    }
    return returnAux;
}

/*
FILE *b;
b=fopen("peliculasDB.dat", "wb");

for(int i=0; i<contadorPeliculas; i++)
{
    fwrite(pPelicula+i, sizeof(EMovie), 1, b);
}
fclose(b);
seguir = 'n';
break;

*/
