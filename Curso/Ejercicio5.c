//Arreglo que muestre las notas de 10 estudiantes y muestre la nota maxima, la nota minima y el promedio

#include <stdio.h>

#define NUM 10

int main(){
	int notas[NUM] = {10,1,2,3,4,5,6,7,14,18};
	int mayor, menor, promedio;
	int sumatoria=0;
	mayor = menor = notas[0];

	for (int i = 1; i < NUM; ++i)
	{
		sumatoria= sumatoria + i;
		if (notas[i] > mayor) mayor = notas[i];
		if (notas[i] < menor) menor = notas[i];
	}
	promedio=sumatoria/10;

	printf("La mejor nota es de %d y la peor es de %d, el promedio de las notas es de %d \n", mayor, menor, promedio);
}
