#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "../.vscode/test/TEST.h"


#define MAX 100


typedef double tipo_vector[MAX]; 


typedef struct {
    double x;
    double y;
} Punto;

void leer_opcion(char *c);
int calcular_regresion(tipo_vector x, tipo_vector y, int n, double *a, double *b, double *r);

int main(){

    Punto datos[MAX];
    tipo_vector vx; 
    tipo_vector vy; 
    int n = 0;
    int borrar, estado;
    char opcion;
    double a, b, r;

    do
    {
        leer_opcion(&opcion);

        switch (opcion)
        {
            case '1':
                printf("Ingrese los valor x del nuevo punto: ");
                scanf(" %lf", &puntos[n].x);
        
                printf("Ingrese los valor y del nuevo punto: ");
                scanf(" %lf", &puntos[n].y);
        
                n++;

                break;
    
            case '2':
                if (n == 0) printf("No hay puntos registrados.\n");
                for(int i = 0; i < n; i++){
                printf("Punto %d: x = %lf, y = %lf", i + 1, puntos[i].x, puntos[i].y);
                }
        
            break;

            case '3':
                do
                {
                    printf("¿Qué punto desea eliminar?:");
                    scanf("%d", &borrar);
                } while (borrar < 1 || borrar > n);

                for(int i = borrar - 1; i < n - 1; i++){
                    puntos[i] = puntos[i + 1];
                }        
                n--;
        
                break;

            case '4':
                if(n < 2){
                    printf("Error: Necesitas al menos 2 puntos para calcular la regresión.\n");
                } else{
                    
                    for (int i = 0; i < n; i++) {
                        vx[i] = datos[i].x;
                        vy[i] = datos[i].y;
                    }
                    
                    estado = calcular_regresion(vx, vy, n, &a, &b, &r);

                    if(estado == 0){
                        printf("La ecuación de la recta es: %lf = %lf%lf + %lf, con un coeficiente de %lf", vy, b, vx, a, r)
                    }else{
                        if (estado == 1) {
                            printf("Aviso: La recta es horizontal (pendiente cero).\n");
                        } 
                        else if (estado == 2) {
                            printf("Aviso: La recta es vertical (pendiente infinita).\n");
                        } 
                        else if (estado == 3) {
                            printf("Aviso: Todos los puntos son iguales, no hay recta definida.\n");
                        }
                    }

                }

                break;

            case '0':
                printf("Finalizando programa\n");
    
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    } while (opcion != '0');
}


void leer_opcion(char *c){
    printf("MENU OPCIONES PARA RECTA REGRESION\n");
    printf("==================================\n\n");
    printf("\t1.- Insertar un nuevo punto experimental\n");
    printf("\t2.- Imprimir en pantalla listado numerado de puntos\n");
    printf("\t3.- Eliminar un punto\n");
    printf("\t4.- Recta de regresión\n");
    printf("\t0.- Finalizar programa\n\n");
    printf("\t\tIntroduzca opción: ");
    scanf(" %c", c);   // con espacio para ignorar saltos de línea
}

int calcular_regresion(tipo_vector x,tipo_vector y,int n,double *a, double *b, double *r){
    double Sx = 0, Sy = 0, Sxx = 0, Syy = 0, Sxy = 0;
    
   for (int i = 0; i < n; i++) {
        Sx += x[i];
        Sy += y[i];
        Sxx += x[i] * x[i];
        Syy += y[i] * y[i];
        Sxy += x[i] * y[i];
    }

    
    double den_b = (n * Sxx) - (Sx * Sx);
    if (den_b == 0) return 2; 

    *b = (n * Sxy - Sx * Sy) / den_b;
    *a = (Sy - (*b) * Sx) / n;

    if (den_r != 0) {
        *r = (n * Sxy - Sx * Sy) / den_r;
    } else {
        return 3; 
    }
    
    if (*b == 0) return 1; 
    return 0; 
}


