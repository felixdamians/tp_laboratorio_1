#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <windows.h>
#include <conio.h>
#define C 20

int main()
{
    char seguir='s';
    int opcion=0;
    EPersona x[C];
    int indice;

    for(indice=0;indice<C;indice++)
    {
        x[indice].estado=0;
    }

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                Altas(x);
                system("cls");
                break;
            case 2:
                Eliminar(x);
                system("pause");
                break;
            case 3:
                Mostrar(x);
                system("pause");
                break;
            case 4:
                Grafico(x);
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("ERROR. INGRESE UN NUMERO ENTRE 1 y 5 PARA UTILIZAR EL MENU\n");

        }
    }

    return 0;
}
