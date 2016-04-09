#include <stdio.h>
#include "funciones.h"
#include <stdlib.h>
#include <windows.h>

int main()
{
    char seguir=1;
    int opcion=0;
    int A=0, B=0, sumar, restas, multiplicaciones;
    double factorial;
    while(seguir==1)
    {
        printf("1- Ingresar 1er operando (A=%d)\n",A);
        printf("2- Ingresar 2do operando (B=%d)\n",B);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones \n");
        printf("9- Salir\n");

        scanf("%d",&opcion);


switch(opcion)
        {
            case 1:
                printf("Ingrese el primer operando: \n");
                scanf("%d",&A);
                system("pause");
                system("cls");
                break;
            case 2:
                printf("Ingrese el segundo operando: \n");
                scanf("%d",&B);
                system("pause");
                system("cls");
                break;
            case 3:
                sumar=Sumar(A,B);
                printf("La suma de los dos operandos es: %d \n",sumar);
                system("pause");
                system("cls");
                break;
            case 4:
                restas=Restar(A,B);
                printf("La resta de los dos operandos es: %d \n",restas);
                system("pause");
                system("cls");
                break;
            case 5:
                Division(A,B);
                system("pause");
                system("cls");
                break;
            case 6:
                multiplicaciones=Multiplicacion(A,B);
                printf("La multiplicacion de los dos operandos es: %d \n",multiplicaciones);
                system("pause");
                system("cls");
                break;
            case 7:
                factorial=Factorial(A);
                printf("El factorial del operando %d es: %lg \n",A,factorial);
                system("pause");
                system("cls");
                break;
            case 8:
                sumar=Sumar(A,B);
                restas=Restar(A,B);
                multiplicaciones=Multiplicacion(A,B);
                factorial=Factorial(A);
                printf("La suma de los dos operandos es: %d \n",sumar);
                printf("La resta de los dos operandos es: %d \n",restas);
                Division(A,B);
                printf("\nLa multiplicacion de los dos operandos es: %d \n",multiplicaciones);
                printf("El factorial del operando es: %lg \n",factorial);
                system("pause");
                system("cls");
                break;
            case 9:
                seguir = 0;
                break;
            default:
                 printf("ERROR.Debe presionar un numero entre el 1 y el 9 para utilizar la calculadora!");

        }
    }
return 0;

}
