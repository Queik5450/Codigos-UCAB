//Programa que sume los 10 primeros numeros pares que se ingresen por teclado
#include <stdio.h>

int main()
{
    int contador=0;
    int sumatoria=0;
    while (contador<10)
    {
        int par, num;
        printf("Ingrese cualquier numero entero: ");
        scanf("%i",&num);
        
        par = (num % 2);
        switch(par)
        {
        case 1:
            printf("Es un numero impar, ingrese otro numero \n");
            break;
                    
        case 0:
            printf("Es un numero par \n");
            sumatoria += num;
            contador++;
            break;
        }
    }
    printf("La suma de los primeros 10 numeros pares es: %i\n", sumatoria);
    return 0;
}