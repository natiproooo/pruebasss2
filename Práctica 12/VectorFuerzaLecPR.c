#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

typedef float tipo_vector[MAX];

typedef struct {
    int tam;            
    tipo_vector vector; 
} tipo_fuerzas;


void leerFuerzas(tipo_fuerzas *f) {
    float aux = 0; 
    f->tam = 0;    

    printf("Introduce las fuerzas (un numero negativo para terminar):\n");

    
    printf("Fuerza %d: ", f->tam + 1);
    scanf("%f", &aux);

    
    while (aux >= 0 && f->tam < MAX) {
        
        f->vector[f->tam] = aux;
        f->tam++;

        
        if (f->tam < MAX) {
            printf("Fuerza %d: ", f->tam + 1);
            scanf("%f", &aux);
        }
    }
}


int main() {

    tipo_fuerzas mis_fuerzas;
    float fuerzaTotal = 0;
    float promedio = 0;

    leerFuerzas(&mis_fuerzas);

    if (mis_fuerzas.tam == 0)
    {
        printf("No hay valores, porfavor introduzca unos valores que sean correctos");

    }else{
        
        for (int i = 0; i < mis_fuerzas.tam; ++i) {
        fuerzaTotal += mis_fuerzas.vector[i];
        }
        promedio = fuerzaTotal / mis_fuerzas.tam;
    
        printf("\n La fuerza total en el puente es de %.2f, el promedio es de %.2f y el numero de secciones es %d", fuerzaTotal, promedio, mis_fuerzas.tam);
    }

    return 0;
}