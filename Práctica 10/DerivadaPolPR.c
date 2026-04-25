#include <stdio.h>
#include <stdlib.h>
#include "../.vscode/test/TEST.h"

#define MAX 100 // Grado máximo del polinomio 

typedef double tipo_polinomio[MAX]; 

extern void PROBAR (double poinomio[], double derivado[], int grado);

int main(int argc, char *argv[])
{
    INICIO_TEST();

    
    tipo_polinomio variable_polinomio = {0};
    tipo_polinomio variable_vector_derivada = {0};
    int grado_original;
    int grado_derivado;

    printf("Introduce el grado del polinomio : ");
    scanf("%d", &grado_original);

    
    for (int i = 0; i <= grado_original; i++) 
    {
        printf("Coeficiente de x^%d: ", i);
        scanf("%lf", &variable_polinomio[i]); 
    }

    
    for (int i = 1; i <= grado_original; i++) 
    {
        variable_vector_derivada[i - 1] = variable_polinomio[i] * i;
    }

    
    if (grado_original > 0) {
        grado_derivado = grado_original - 1;
    } else {
        grado_derivado = 0; 
    }

    
    printf("\nDerivada calculada con exito.\n");

    
    PRINT_TEST("PROBAR");  
    if (argc > 1)   
        PROBAR(variable_polinomio, variable_vector_derivada, grado_derivado); 

    FIN_TEST();
    return (0);
}
