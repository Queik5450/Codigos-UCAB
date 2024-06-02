/*
Defina un registro que permita guardar la siguiente información: Cédula, Nombre,
Apellido, FechaNacimiento, Sexo, Semestre que cursa, Mensaje, Materia más difícil.
Considere los tipos de datos convenientes para cada uno de los miembros de la
estructura. Seguidamente haga un programa que permita al usuario llenar la
información correspondiente en un registro y posterior a ello visualizarla en pantalla
*/
#include <stdio.h>

struct Regpersonas
{
    char Cedula[12];
    char Nombre[30];
    char FechaNacimiento[12];
    char Sexo[2];
    char Semestre[4];
    char Mensaje[100];
    char Materia[30];
};  

struct Regpersonas Regpersonas;


int main()
{
    printf("Ingrese la cedula: "); 
    scanf("%s", Regpersonas.Cedula);
    while(getchar() != '\n');

    printf("Ingrese el nombre y apellido: ");
    fgets(Regpersonas.Nombre, 30, stdin);

    printf("Ingrese la fecha de nacimiento(Seguir el formato DD/MM/AA): ");
    scanf("%s", Regpersonas.FechaNacimiento);

    printf("Ingrese el sexo(M/F): ");
    scanf("%s", Regpersonas.Sexo);

    printf("Ingrese el semestre: ");    
    scanf("%s", Regpersonas.Semestre);
    while (getchar() != '\n');

    printf("Ingrese el mensaje: ");
    fgets(Regpersonas.Mensaje, 100, stdin);

    printf("Ingrese la materia mas dificil: ");
    fgets(Regpersonas.Materia, 30, stdin);
    
    printf("Sus datos son: \n Cedula: %s \n Nombre: %s Fecha de nacimiento: %s \n Sexo: %s \n Semestre: %s \n Mensaje: %s Materia mas dificil: %s", Regpersonas.Cedula, Regpersonas.Nombre, Regpersonas.FechaNacimiento, Regpersonas.Sexo, Regpersonas.Semestre, Regpersonas.Mensaje, Regpersonas.Materia);
    return 0;
}