//Programa que pida al usuario su nombre, apellido y universidad
#include <stdio.h>
void main()
{
	char nombre[50];
	char uni[75];
	printf("Ingrese el nombre y apellido: ");
	if (fgets(nombre,50,stdin)!=NULL);
	
	printf("Ingrese universidad en la que estudia: ");
	if (fgets(uni,75,stdin)!=NULL);
	printf("Bienvenido %sUsted estudia en %s \n", nombre, uni);
}
