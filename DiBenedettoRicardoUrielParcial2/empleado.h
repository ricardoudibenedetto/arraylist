#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "ArrayList.h"
struct S_Empleado
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
};
typedef struct S_Empleado Empleado;

int generarArchivoSueldos(char* fileName,ArrayList* listaEmpleados);
void calcularSueldo(ArrayList* listaEmpleados);
void em_calcularSueldo(void* p);

#endif // EMPLEADO_H_INCLUDED

