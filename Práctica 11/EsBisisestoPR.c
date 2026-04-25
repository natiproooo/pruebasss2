#include <stdio.h>
#include <stdlib.h>
//#include "../.vscode/test/TEST.h"

int esBisiesto(int anio);

int main(int argc, char *argv[]) {
    INICIO_TEST();

    int anio;
    int resultado;

  
    printf("Introduce un año: ");
    scanf("%d", &anio);

    
    resultado = esBisiesto(anio);

    if (resultado == 1) {
        printf("El año %d es bisiesto (tiene 366 días).\n", anio);
    } else {
        printf("El año %d no es un año bisiesto (tiene 365 días).\n", anio);
    }

    PRINT_TEST("PRUEBA_BISIESTO");

    FIN_TEST();
    return 0;
}


int esBisiesto(int anio) {
    
    if (anio % 4 == 0) {
        
        if (anio % 100 == 0) {
            
            if (anio % 400 == 0) {
                return 1; 
            } else {
                return 0; 
            }
        } else {
            return 1; 
        }
    } else {
        return 0; 
    }
}