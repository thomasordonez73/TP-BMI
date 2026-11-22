// URL del repositorio: https://github.com/thomasordonez73/TP-BMI

#include <stdio.h>

#define TAM 5

int main(void) {
    int codigos[TAM];
    float precios[TAM];
    int posicion_mayor = 0;
    int posicion_menor = 0;

    printf("Ingrese %d productos, se solicitara el codigo y precio:\n\n", TAM);

    for (int i = 0; i < TAM; i++) {
        do {
            printf("Ingrese el codigo de barras (1-999999999): ");

            if (scanf("%d", &codigos[i]) != 1) {
                int caracter;
                while ((caracter = getchar()) != '\n' && caracter != EOF) {
                }
                codigos[i] = 0;
            }

            if (codigos[i] < 1 || codigos[i] > 999999999) {
                printf("Error. El codigo de barras debe estar entre 1 y 999999999\n");
            }
        } while (codigos[i] < 1 || codigos[i] > 999999999);

        do {
            printf("Ingrese el precio: ");

            if (scanf("%f", &precios[i]) != 1) {
                int caracter;
                while ((caracter = getchar()) != '\n' && caracter != EOF) {
                }
                precios[i] = -1.0f;
            }

            if (precios[i] < 0) {
                printf("Error. El precio no puede ser negativo.\n");
            }
        } while (precios[i] < 0);

        if (i > 0) {
            if (precios[i] > precios[posicion_mayor]) {
                posicion_mayor = i;
            }

            if (precios[i] < precios[posicion_menor]) {
                posicion_menor = i;
            }
        }

        printf("\n");
    }

    printf("Codigo     Precio\n");

    for (int i = 0; i < TAM; i++) {
        printf("%9d %10.2f\n", codigos[i], precios[i]);
    }

    printf("\nMas caro: [%d] %.2f\n",
           codigos[posicion_mayor], precios[posicion_mayor]);

    printf("Mas barato: [%d] %.2f\n",
           codigos[posicion_menor], precios[posicion_menor]);

    return 0;
}
