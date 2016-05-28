#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    EMovie pelicula;

    while(seguir=='s')
    {
        printf("REGISTROS DE PELICULAS:\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPelicula(&pelicula);
                system("pause");
                break;
            case 2:
                system("cls");
                borrarPelicula(&pelicula);
                system("pause");
                break;
            case 3:
                system("cls");
                generarPagina(&pelicula);
                system("pause");
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
