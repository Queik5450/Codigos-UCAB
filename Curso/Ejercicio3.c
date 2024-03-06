//Calculadora simple
#include <stdio.h>

int main() {
    int num1, num2;
    char op;

    printf("Ingresa el primer numero: ");
    scanf("%d", &num1);

    printf("Ingresa el simbolo de la operacion (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Ingresa el segundo numero: ");
    scanf("%d", &num2);

    switch (op) {
        case '+':
            printf("Resultado: %d\n", num1 + num2);
            break;
        case '-':
            printf("Resultado: %d\n", num1 - num2);
            break;
        case '*':
            printf("Resultado: %d\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0) {
                printf("Resultado: %.2f\n", (float)num1 / num2);
            } else {
                printf("Buen intento, pero no puedes dividir entre 0.\n");
            }
            break;
        default:
            printf("Operacion invalida.\n");
            break;
    }
    return 0;
}
