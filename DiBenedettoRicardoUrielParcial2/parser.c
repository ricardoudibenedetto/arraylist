#include "ArrayList.h"
#include "empleado.h"
#include "stdio.h"
int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados)
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

                    listaEmpleados->add(listaEmpleados,unEmpleado);
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


