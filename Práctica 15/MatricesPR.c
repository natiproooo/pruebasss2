#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "../.vscode/test/TEST.h"


#define FILAS 10
#define COLUMNAS 10



typedef struct {
    int f;               
    int c;               
    double datos[FILAS][COLUMNAS]; 
} tipo_matriz;

tipo_matriz leerMatriz();
void escribirMatriz();
tipo_matriz copiarMatriz(tipo_matriz original);
tipo_matriz sumarMatriz();
tipo_matriz restarMatrices();
tipo_matriz productoEscalar();
void multiplicar_matrices(tipo_matriz a, tipo_matriz b, tipo_matriz c, int f1, int c1, int f2, int c2, int *f3, int *c3);
tipo_matriz transpuesta();
tipo_matriz determinante();
tipo_matriz inversa();

int main(){

}

tipo_matriz copiarMatriz(tipo_matriz original) {
    tipo_matriz copia;
    copia.f = original.f;
    copia.c = original.c;

    for (int i = 0; i < original.f; i++) {
        for (int j = 0; j < original.c; j++) {
            copia.datos[i][j] = original.datos[i][j];
        }
    }
    return copia;
}

tipo_matriz sumarMatrices(tipo_matriz a, tipo_matriz b) {
    tipo_matriz resultado;
    if(a.f != b.f || a.c != b.c){
        printf("Error: Las matrices deben de ser de la misma dimensión: ");
        resultado.f = 0;
        resultado.c = 0;
        return resultado;
    
    }

    resultado.f= a.f;
    resultado.c = a.c;
    for(int i = 0; i < a.f; i++){
        for(int j = 0; j < a.c; j++){
            resultado.datos[i][j] = a.datos[i][j] +b.datos[i][j];

        }
    }

    return resultado;

}

tipo_matriz productoEscalar(tipo_matriz m, double escalar){
    for(int i = 0; i < a.f; i++){
        for(int j = 0; j < a.c; j++){
            m.datos[i][j] += escalar;
        }
    }
    return m;

}

tipo_matriz traspuesta(tipo_matriz m){
    
}
    