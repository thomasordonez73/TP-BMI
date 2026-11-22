// URL del repositorio: https://github.com/thomasordonez73/TP-BMI

#include <stdio.h>

int main(void) {
    float peso, altura, imc;

    do {
        printf("Ingrese el peso en kg: ");
        if (scanf("%f", &peso) != 1) {
            int caracter;
            while ((caracter = getchar()) != '\n' && caracter != EOF) {
            }
            peso = -1;
        }

        if (peso < 0) {
            printf("Error: no se permiten valores negativos. Intente nuevamente.\n");
        }
    } while (peso < 0);

    do {
        printf("Ingrese la altura en metros: ");
        if (scanf("%f", &altura) != 1) {
            int caracter;
            while ((caracter = getchar()) != '\n' && caracter != EOF) {
            }
            altura = -1;
        }

        if (altura < 0) {
            printf("Error: no se permiten valores negativos. Intente nuevamente.\n");
        } else if (altura == 0) {
            printf("Error: la altura debe ser mayor que cero. Intente nuevamente.\n");
        }
    } while (altura <= 0);

    imc = peso / (altura * altura);

    printf("\nSu indice de masa corporal es: %.2f\n\n", imc);

    printf("    Indice    |  Condicion\n");
    printf("-----------------------------\n");
    printf("    <18.5     |  Bajo peso\n");
    printf(" 18.5 a 24.9  |  Normal\n");
    printf(" 25.0 a 29.9  |  Sobrepeso\n");
    printf("    >=30      |  Obesidad\n");

    return 0;
}
