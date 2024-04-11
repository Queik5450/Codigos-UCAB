/*  
Dado un arreglo de 20 números enteros, se desea que usted:
-Haga una función que calcule la ocurrencia de un número
dado y la muestre por pantalla.
-Siguiendo el prototipo: float relacionPI(int array[], int size), calcule
la división entre las suma de los valores pares y la suma de los valores
impares.
*/

#include <stdio.h>

float relacionPI(int array[], int size){
    int i;
    int sumaPares = 0, sumaImpares = 0;
    for(i = 0; i < size; i++){
        if(array[i] % 2 == 0){
            sumaPares += array[i];
        }else{
            sumaImpares += array[i];
        }
    }
    if (sumaImpares == 0){
        printf("No se puede dividir por 0\n");
        return 1;
    }
    return (float)sumaPares / sumaImpares;
}

int ocurrencia(int array[], int size, int num){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(array[i] == num){
            count++;
        }
    }
    return count;
}

int main(){
    int array[20], i, num;
    for(i = 0; i < 20; i++){
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("Ingrese el numero a buscar: ");
    scanf("%d", &num);
    printf("El numero %d se repite %d veces\n", num, ocurrencia(array, 20, num));
    printf("La relacion entre la suma de los pares y la suma de los impares es: %f \n", relacionPI(array, 20));
    return 0;
}