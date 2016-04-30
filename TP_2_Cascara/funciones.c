#include <stdio.h>
#include "funciones.h"
#include <ctype.h>
#include <string.h>
#include <windows.h>
#define C 20
int obtenerEspacioLibre(EPersona x[])
{
int indice;

for(indice=0;indice<C;indice++)
{
 if(x[indice].estado==0)
 {
     break;
 }
 else
    {
      if(indice==C)
 {
     printf("YA SUPERO LA CANTIDAD INGRESOS!");
     break;
 }
}
}
return indice;
}

void Altas(EPersona x[])
{
    int indice;

    indice=obtenerEspacioLibre(x);
    system("cls");
    printf("Ingrese el nombre de la persona: \n");
    fflush(stdin);
    gets(x[indice].nombre);
    printf("Ingrese la edad de la persona: \n");
    scanf("%d",&x[indice].edad);
    x[indice].edad=val_int(x[indice].edad,1,110);
    printf("Ingrese el dni sin puntos de la persona: \n");
    scanf("%ld",&x[indice].dni);
    x[indice].dni=val_int(x[indice].dni,1,100000000);
    x[indice].estado=1;
    system("cls");
}



void Eliminar(EPersona x[])
{
    int indice;
    long int aux_dni;
    printf("Ingrese el DNI de la persona que desea eliminar 'sin comas ni puntos': ");
    scanf("%ld",&aux_dni);
    indice=buscarPorDni(x,aux_dni);
    if(indice==0)
    {

        printf("\n ERROR.No se puedo encontrar el DNI vuelva a ingresar\n");
    }
    else
    {
        x[indice].estado=0;
        printf("Se limpiaron los datos de %s\n",x[indice].nombre);
    }

}


 int val_int(int dato, int min, int max)
    {
        while(dato<min || dato>max)
        {
            printf("Error. Reingrese el dato entre %d y %d: \n", min, max);
            scanf("%d",&dato);
        }
        return dato;
    }

void Mostrar(EPersona x[])
{
 int i, j;
EPersona aux;

for(i=0;i<C-1;i++)
{
     for(j=i+1;j<C;j++)
     {
         if(strcmp(x[i].nombre, x[j].nombre)>0)
         {
             aux=x[i];
             x[i]=x[j];
             x[j]=aux;
         }
     }
}
  for(i=0;i<C;i++)
 {
     if(x[i].estado==1)
     {
    printf("\n 1#Nombre: %s \n 2#Edad: %d \n 3#Dni: %ld \n", x[i].nombre, x[i].edad, x[i].dni);
}
}
}
int buscarPorDni(EPersona x[], long int dni)
{

int indice;
    for(indice=0;indice<C;indice++)
    {

        if(dni==x[indice].dni)
        {
            return indice;
        }
    }

    indice=0;
    return indice;
}

void Grafico(EPersona x[])
{
  int indice, men18=0, e18y35=0, may35=0, mayor;
   for(indice=0;indice<C;indice++)//Acumulo por edad las personas a graficar
    {
        if(x[indice].estado!=0)
        {
            if(x[indice].edad<18)
            {
                men18++;
            }
            else
            {
                if(x[indice].edad>=18&&x[indice].edad<=35)
                e18y35++;
                if(x[indice].edad>35)
                may35++;
            }
        }
    }
    mayor=0;
     if(men18>mayor)
    {
        mayor=men18;
    }
    else
    {
        if(e18y35>mayor)
        {
            mayor=e18y35;
        }
        else
        {
            if(may35>mayor)
            {
                mayor=may35;
            }
        }
    }
    for(indice=mayor;indice>0;indice--)
    {
        if(men18==indice&&e18y35==indice&&may35==indice)
        {
            printf("*\t*\t*");
            men18--;
            e18y35--;
            may35--;
        }
        else
        {
            if(men18==mayor&&e18y35==mayor)
            {
                printf("*\t*");
                men18--;
                e18y35--;
            }
            else if(men18==indice&&may35==indice)
            {
                printf("*\t*");
                men18--;
                may35--;
            }
            else if(e18y35==mayor&&may35==mayor)
            {
                printf("\t*\t*");
                e18y35--;
                may35--;
            }
            else
            {
                if(may35==mayor)
                {
                    printf("\t\t*");
                    may35--;
                }
                else if(e18y35==mayor)
                {
                    printf("\t*");
                    e18y35--;
                }
                else
                {
                    if(men18==mayor)
                    {
                        printf("*");
                        men18--;
                    }
                }
            }
        }
    printf("\n");
    }

    printf("<18\t18-35\t>35\n");

}
