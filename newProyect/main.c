#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "libreria.h"

int main()
{
    int respuesta='s';
    // Definir lista de empleados
    ArrayList* listaEmpleados=al_newArrayList();
    do
    {
        switch(menu())
        {
        case 1:

            break;
        case 2:


            break;

        case 3:

            break;

        case 4:
            respuesta='n';
            break;
        default:
            printf("opcion incorrecta");
        }
        system("pause");
        system("cls");
    }
    while(respuesta!='n');
    return 0;
}
