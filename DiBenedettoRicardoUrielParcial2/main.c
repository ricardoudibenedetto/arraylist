#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "Parser.h"

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca ArrayList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.

    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

int main()
{
    int opcion;
    int respuesta='s';
    // Definir lista de empleados
    ArrayList* listaEmpleados=al_newArrayList();
    do
    {

        opcion=0;
        printf("1.- cargar archivos\n2.-calcular sueldo\n3.-generar archivo\n4.-salir\n\n");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            // Crear lista empledos
            //...

            // Leer empleados de archivo data.csv
            if(parser_parseEmpleados("data.csv",listaEmpleados)==1)
            {
                // Calcular sueldos
                printf("archivo cargado con exito\n\n");
            }
            else
                printf("Error leyando empleados\n");
            break;
        case 2:
            listaEmpleados->generarSueldo(listaEmpleados,em_calcularSueldo);
           //calcularSueldo(listaEmpleados);
            printf("sueldos calculados\n");

            break;

        case 3:
            // Generar archivo de salida
            if(generarArchivoSueldos("sueldos.csv",listaEmpleados)==1)
            {
                printf("Archivo generado correctamente\n");
            }
            else
                printf("Error generando archivo\n");
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
