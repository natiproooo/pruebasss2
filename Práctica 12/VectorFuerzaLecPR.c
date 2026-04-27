#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

typedef float VectorFuerzas[MAX];


int main() {

    int numSecciones = 6;
    float fuerzaTotal;
    VectorFuerzas fuerzas = {1000, 1500, 800, 1200, 2000, 22};

    for (int i = 0; i < numSecciones; ++i) {
        fuerzaTotal += fuerzas[i];
    }


    printf("Fuerzas en las secciones del puente:\n");
    for (int i = 0; i < numSecciones; ++i) {
        printf("Sección %d: %f Newtons\n", i + 1, fuerzas[i]);
    }

    printf("\nFuerza total en el puente: %.2f Newtons\n", fuerzaTotal);

    return 0;
}