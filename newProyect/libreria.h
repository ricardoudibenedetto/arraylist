#include <stdio.h>
#include <stdlib.h>

/** \brief muestra un menu por consola y solicita al usuario una opcion
 *
 * \return retorna la opcion elegida por el usuario
 *
 */
int menu();


/** \brief carga a memoria un archivo
 *
 * \param el nombre del archivo a cargar
 * \param arrayList donde se desea guardar
 * \return retorna -1 si hay un problema y 1 si es OK
 *
 */
int parser(char* fileName, ArrayList* lista);
void ordenarTareas(ArrayList* totalTareas,ArrayList* tareasAlta, ArrayList* tareasBaja);

/** \brief genera un archivo de texto
 *
 * \param nombre del archivo a generar
 * \param arraylist a guardar en el archivo
 * \return 1 OK
 *
 */
int generarArchivo(char* fileName,ArrayList* lista);

/** \brief funcion construsctora, reserva espacio en memoria e inicializa los campos del elemento
 *
 * \return puntero al elemento reservado
 *
 */
ePersona* newPersona():

/** \brief evalua si un usuario es mayor menor o igual al otro
 *
 * \param usuario uno
 * \param usuario dos
 * \return retorna 0 si son iguales 1 sies mas grande y -1 si es mas chico
 *
 */
int ordenarPorNombre(void* usuarioA,void* usuarioB)


