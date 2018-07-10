#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "Parser.h"
void em_calcularSueldo(void* p)
{
    Empleado* unEmpleado;
    unEmpleado=(Empleado*)p;
    if(p!=NULL)
    {

         if(unEmpleado->horasTrabajadas < 177)
        {
            unEmpleado->sueldo=(180*unEmpleado->horasTrabajadas);
        }
        else
        {
            if(unEmpleado->horasTrabajadas > 176 && unEmpleado->horasTrabajadas < 208)
            {
                unEmpleado->sueldo=(270*unEmpleado->horasTrabajadas);
            }
            else
            {
                if(unEmpleado->horasTrabajadas > 207)
                {
                    unEmpleado->sueldo=(360*unEmpleado->horasTrabajadas);
                }

            }
        }
    }
}

/** \brief genera un archivo de texto con los datos generados
 *
 * \param nombre de archivo a generar
 * \param arraylist de empleados
 * \return 1 si esta todo bien
 *
 */
int generarArchivoSueldos(char* fileName,ArrayList* listaEmpleados)
{
    int i;
    Empleado *Emp;
    FILE *b;
    b=fopen("fileName2", "w");

    for(i=1; i<listaEmpleados->len(listaEmpleados); i++)
    {
        Emp=listaEmpleados->get(listaEmpleados,i);

        fprintf(b,"%d,%s,%d,%d\n",Emp->id,Emp->nombre,Emp->horasTrabajadas,Emp->sueldo);
    }
    fclose(b);

    return 1;
}


/** \brief carga el campo sueldo de los los empleados
 *
 * \param arraylist de emmpleados
 */
void calcularSueldo(ArrayList* listaEmpleados)
{
    int i;
    Empleado *unEmpleado;
    for(i=0; i<listaEmpleados->len(listaEmpleados); i++)
    {
        unEmpleado=listaEmpleados->get(listaEmpleados,i);

        if(unEmpleado->horasTrabajadas < 177)
        {
            unEmpleado->sueldo=(180*unEmpleado->horasTrabajadas);
        }
        else
        {
            if(unEmpleado->horasTrabajadas > 176 && unEmpleado->horasTrabajadas < 208)
            {
                unEmpleado->sueldo=(270*unEmpleado->horasTrabajadas);
            }
            else
            {
                if(unEmpleado->horasTrabajadas > 207)
                {
                    unEmpleado->sueldo=(360*unEmpleado->horasTrabajadas);
                }

            }
        }
    }

}


