#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../.vscode/test/TEST.h"

#define FILAS 10
#define COLUMNAS 10
#define PUNTOS_ALEATORIOS 20

typedef int MAtriz [FILAS][COLUMNAS];


void inicializarMatriz(Matriz matriz);
void mostrarMatriz(Matriz matriz);
void colorearPuntosAleatorios(Matriz matriz);
int contarVecinosColoreados(Matriz matriz, int fila, int columna, int distancia);
int contarPuntosConVecinosColoreados(Matriz matriz);

extern void PROBAR();

int main(int argc, char *argv[])
{
    INICIO_TEST();
    if (argc > 1)  {
        PROBAR();
        PRINT_TEST("PROBAR");
    }  

    Matriz matriz;

    inicializarMatriz(matriz);
    colorearPuntosAleatorios(matriz);
    printf("Matriz original:\n");
    mostrarMatriz(matriz);

    int puntosConVecinosColoreados = contarPuntosConVecinosColoreados(matriz);

    printf("\nTotal de puntos coloreados con vecinos coloreados: %d\n", puntosConVecinosColoreados);

    FIN_TEST();
    return 0;
}

void inicializarMatriz(Matriz matriz) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = 0;  
        }
    }
}

void mostrarMatriz(Matriz matriz) {
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            printf("%d ", matriz[i][j]);
        }
    
    pintf("\n");
    }
}

void colorearPuntosAleatorios(Matriz matriz) {
    srand(time(NULL));

    int puntosColoreados = 0;
    while (puntosColoreados < PUNTOS_ALEATORIOS) {
        int fila = rand() % FILAS;
        int columna = rand() % COLUMNAS;
    
        if (matriz[fila][columna] == 0) {
            matriz[fila][columna] = 1;
            puntosColoreados++;
        }
    
    }
}

int contarVecinosColoreados(int matriz[FILAS][COLUMNAS], int fila, int columna, int distancia) {
    int contador = 0;

    for (int i = -distancia; i <= distancia; i++) {
        for (int j = -distancia; j <= distancia; j++) {
            int nuevaFila = fila + i;
            int nuevaColumna = columna + j;

            
            if (nuevaFila >= 0 && nuevaFila < FILAS && nuevaColumna >= 0 && nuevaColumna < COLUMNAS) {
                
                if (!(i == 0 && j == 0) && matriz[nuevaFila][nuevaColumna] == 1) {
                    contador++;
                }
            }
        }
    }

    return contador;
}

int contarPuntosConVecinosColoreados(Matriz matriz) {
    int puntosConVecinosColoreados = 0;

    for (int i = 0; i < FILAS; i++) {
    for (int j = 0; j < COLUMNAS; j++) {
        if (matriz[i][j] == 1) { // Solo nos interesan puntos coloreados
            if (contarVecinosColoreados(matriz, i, j, 1) > 0) {
                puntosConVecinosColoreados++;
            }
        }
    }
}

    return puntosConVecinosColoreados;
}