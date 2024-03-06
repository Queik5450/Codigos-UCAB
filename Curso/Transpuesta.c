//Programa que cargue e imprima una matriz con su transpuesta en pantalla
#include <stdio.h>

void leer(int matrizA[4][5])
{
	int i,j;
	for (i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
		printf("Ingrese numero del espacio %d %d:", i, j);
		scanf("%i",&matrizA[i][j]);
		}
	}
}

void imprimir_normal(int matrizA[4][5])
{
	int i,j;
	for (i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
		printf("%i:", matrizA[i][j]);
		}
	printf("\n");
	}
}

void imprimir_trans(int matrizA[4][5])
{
	int i,j;
	for(j=0;j<5;j++)
	{
		for (i=0;i<4;i++)
		{
		printf("%i:", matrizA[i][j]);
		}
	printf("\n");
	}
}

int main()
{
	int matrizA[4][5];
	leer(matrizA);
	imprimir_normal(matrizA);
	imprimir_trans(matrizA);
}
