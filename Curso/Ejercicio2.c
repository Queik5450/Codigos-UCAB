//Programa que compare 2 numeros y muestre cual es menor o mayor

#include <stdio.h>

int main()
{
	float x,y;
	printf("Ingrese primer numero");
	scanf("%f", &x);
	printf("Ingrese segundo numero");
	scanf("%f", &y);
	
	 if (x>y) 
	 {
       printf("\nEl No.1 es mayor que el No. 2");
      } 
      else if (y>x) 
      {
       printf("\nEl No.2 es mayor que el No. 1");
      } 
      else 
      {
       printf("Son iguales");
      }
}
