//Programa que determine si el numero es par o impar

#include <stdio.h>

int main()
{
	int par, num;
	{
	printf("Ingrese cualquier numero entero: ");
	scanf("%i",&num);
	par = (num % 2);
		
	switch(par)
	{
		case 1:
		printf("Es un numero impar \n");
		break;
		
		case 0:
		printf("Es un numero par \n");
		break;
	}
	}
}
