#include <stdio.h>

// Prototipos de funciones
void TablaPotencias(double n, int a, int b);
double potencia(double base, int exponente);

int main() {
    double base;
    int limA, limB;

    // Validación de la base n: entre -5 y 5 (nunca 0)
    do {
        printf("Introduce base n (entre -5 y 5, no 0): ");
        scanf("%lf", &base);
    } while (base < -5 || base > 5 || base == 0);

    // Validación de los límites a y b: entre -10 y 10
    do {
        printf("Introduce límite a (-10 a 10): ");
        scanf("%d", &limA);
    } while (limA < -10 || limA > 10);

    do {
        printf("Introduce límite b (-10 a 10): ");
        scanf("%d", &limB);
    } while (limB < -10 || limB > 10);

    // Llamada a la función principal
    TablaPotencias(base, limA, limB);

    return 0;
}

/**
 * Genera la tabla de potencias en el intervalo [a, b] o [b, a]
 */
void TablaPotencias(double n, int a, int b) {
    int inicio, fin;

    // Ordenar a y b para que el bucle funcione en cualquier orden
    if (a < b) {
        inicio = a; fin = b;
    } else {
        inicio = b; fin = a;
    }

    printf("\nTabla de potencias para base %.2f:\n", n);
    for (int i = inicio; i <= fin; i++) {
        double resultado = potencia(n, i);
        
        // El enunciado pide mostrar (1) si es válido o (0) si es indeterminación
        if (n == 0 && i <= 0) {
            printf("%.2f ^ %d = Indeterminación (0)\n", n, i);
        } else {
            printf("%.2f ^ %d = %.3f (1)\n", n, i, resultado);
        }
    }
}

/**
 * Calcula la potencia sin usar math.h
 * Soporta exponentes positivos, negativos y el caso 0
 */
double potencia(double base, int exponente) {
    // Casos de indeterminación según la tabla del enunciado
    if (base == 0 && exponente <= 0) {
        return 0.0; 
    }

    double resultado = 1.0;
    int expAbsoluto = (exponente < 0) ? -exponente : exponente;

    // Multiplicación sucesiva
    for (int i = 0; i < expAbsoluto; i++) {
        resultado *= base;
    }

    // Si el exponente era negativo, invertimos el resultado (1/base^exp)
    if (exponente < 0) {
        return 1.0 / resultado;
    }

    return resultado;
}