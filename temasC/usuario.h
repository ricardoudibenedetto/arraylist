#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int id;
    char nombre[50];
    char email[50];
    char sexo;
    char pais[50];
    char password[50];
    char ipAddress[50];
}eUsuario;
int parser_Usuarios(char* fileName, ArrayList* listaUsuarios);
