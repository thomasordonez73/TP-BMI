// URL del repositorio: https://github.com/thomasordonez73/TP-BMI

#include <stdio.h>
#include <stdlib.h>

#define TAM 20

int cuantas_piezas(int);
int rectificable(float, float);
int rechazada(float, float);

void cargar_piezas(float *, int);
int contar(int (*)(float, float), float, float *, int);
float* reserva_memoria(int);
void segregar(int (*)(float, float), float, float *, int, float *);
void mostrar_piezas(char *, float *, int);

int main (void) {
    float diametros[TAM] = {0};
    int n;
    float max = 12;
    float min = 10;

    n = cuantas_piezas(TAM);

    cargar_piezas(diametros, n);

    int n_rectificar = contar(rectificable, max, diametros, n);
    float *p_rectificables = reserva_memoria(n_rectificar);
    segregar(rectificable, max, diametros, n, p_rectificables);

    int n_rechazar = contar(rechazada, min, diametros, n);
    float *p_rechazadas = reserva_memoria(n_rechazar);
    segregar(rechazada, min, diametros, n, p_rechazadas);

    mostrar_piezas("rectificables", p_rectificables, n_rectificar);
    mostrar_piezas("rechazadas", p_rechazadas, n_rechazar);

    return 0;
}

int cuantas_piezas(int max) {
    int n;

    do {
        printf("Cuántas piezas ingresará? ");
        scanf("%d", &n);
    } while (n < 0 || n > max);

    return n;
}

int rectificable(float diametro, float valor) {
    if (diametro > valor)
        return 1;
    else
        return 0;
}

int rechazada(float diametro, float valor) {
    if (diametro < valor)
        return 1;
    else
        return 0;
}

/* a) Carga los diámetros. Solo acepta valores positivos. */
void cargar_piezas(float *p, int n) {
    for (int i = 0; i < n; i++) {
        do {
            printf("Ingrese diámetro de pieza %d: ", i);
            if (scanf("%f", p + i) != 1) {
                int caracter;
                while ((caracter = getchar()) != '\n' && caracter != EOF) {
                    /* Descarta la entrada inválida. */
                }
                *(p + i) = 0;
            }

            if (*(p + i) <= 0) {
                printf("Error: el diámetro debe ser un valor positivo.\n");
            }
        } while (*(p + i) <= 0);
    }
}

/* b) Cuenta los elementos que cumplen el criterio recibido. */
int contar(int (*criterio)(float, float), float valor, float *p, int n) {
    int cantidad = 0;

    for (int i = 0; i < n; i++) {
        if (criterio(*(p + i), valor) == 1) {
            cantidad++;
        }
    }

    return cantidad;
}

/* c) Reserva memoria para n diámetros. */
float* reserva_memoria(int n) {
    float *q;

    if (n == 0) {
        return NULL;
    }

    q = malloc(n * sizeof(float));

    if (q == NULL) {
        printf("No se pudo reservar memoria. Fin del programa.\n");
        exit(1);
    }

    return q;
}

/* d) Copia en q los diámetros que cumplen el criterio. */
void segregar(int (*criterio)(float, float), float valor,
              float *p, int n, float *q) {
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (criterio(*(p + i), valor) == 1) {
            *(q + j) = *(p + i);
            j++;
        }
    }
}

/* e) Muestra el mensaje y los diámetros del arreglo. */
void mostrar_piezas(char *mensaje, float *p, int n) {
    printf("Piezas %s:\n\n", mensaje);

    for (int i = 0; i < n; i++) {
        printf("Diámetro: %.2f\n\n", *(p + i));
    }
}
