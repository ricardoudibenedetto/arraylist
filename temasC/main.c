#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "temas.h"
#include "usuario.h"

int main()
{
    int opcion;
    int respuesta='s';
    int respuesta2 ='s';
    int opcion2;
    int opcion3;
    int respuesta3='s';
    int i;
    eTemas* unTema;
    ArrayList* listaTemas=al_newArrayList();
    ArrayList* listaUsuarios=al_newArrayList();


   // parser_Usuarios("usuarios.dat",listaUsuarios);
    parser_temas("temas.dat",listaTemas);
    system("pause");
    do
    {
        system("cls");
        opcion=0;
        printf("1.- Ordenar\n2.-listar temas\n3.-escuchar temas\n4.-guardar estadistica\n5.-informar\n6.-salir\n\n");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            do
            {
                system("cls");
                opcion2=0;
                printf("1.- Ordenar por nombre\n2.-Ordenar por nacionalidad y nombre\n3.-atras\n");
                fflush(stdin);
                scanf("%d",&opcion2);
                switch(opcion2)
                {
                case 1:


                    for(i=0;i<listaTemas->len(listaTemas);i++)
                    {
                     unTema=(eTemas*)malloc(sizeof(eTemas));
                     unTema=listaTemas->get(listaTemas,i);
                     if(i==200)
                        system("pause");
                        printf("%d %s %s \n", unTema->id, unTema->nombre_tema, unTema->artista);
                    }
                    system("pause");
                    break;

                case 2:

                    break;
                case 3:
                    respuesta2='n';
                    break;
                }
            }
            while(respuesta2!='n');

            break;
        case 2:

            break;

        case 3:

            break;
        case 4:

            break;
        case 5:
            do
            {
                 system("cls");
                opcion3=0;
                printf("1.-El tema mas escuchado \n2.-El tema mas escuchado segun nacionalidad del usuario\n3.-El autor con mas reproducciones\n4.-El autor con mas temas en el catalogo\n5.-atras\n");
                fflush(stdin);
                scanf("%d",&opcion3);
                switch(opcion3)
                {
                case 1:

                    break;

                case 2:

                    break;
                case 3:

                    break;
                case 4:

                    break;
                case 5:
                    respuesta3='n';
                    break;
                }
            }
            while(respuesta3!='n');
            break;
        case 6:
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
