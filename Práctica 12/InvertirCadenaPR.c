#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int longitud_cadena(char cad[]);

void invertir_cadena(char cad[]){
    int i = 0;
    int j = 0;
    char aux;

    j = longitud_cadena(cad) - 1;

    while(i < j){
        aux = cad[i];
        cad[i] = cad[j];
        cad[j] = aux;
        i++;
        j--;
    }
}