#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



int Sumar(x,y)
{
 int suma;
 suma=x+y;
  return suma;
}

int Restar(x,y)
{
   int resta;
   resta=x-y;
   return resta;
}

int Multiplicacion(x,y)
{
   int multiplica;
   multiplica=x*y;
   return multiplica;
}
void Division(x,y)
{
    float A=x, B=y, dividir;
    if(B==0)
    {
        printf("ERROR. La division por cero no es posible. Modifique el valor B");
    }
    else
    {
    dividir=A/B;
    printf("La division de los dos operandos es: %.2f",dividir);
    }
}

double Factorial(x)
{
   int i=x;
   double res=1;
   if(x<0)
   {
   while(i!=0)
   {
       res=res*i;
       i++;
   }
   }
   else
   {
     while(i!=0)
     {
         res=res*i;
         i--;
     }
   }
   return res;
}





#endif // FUNCIONES_H_INCLUDED
