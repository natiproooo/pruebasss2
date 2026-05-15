#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "../.vscode/test/TEST.h"

typedef struct {
    double x;
    double y;
} Punto;

Punto leerPunto(int n);
double distancia(Punto p1, Punto p2);
double productoVectorial(Punto p1, Punto p2, Punto p3);
Punto calcularCentro(Punto p1, Punto p2, Punto p3);

int main(){
    INICIO_TEST();
    Punto p1, p2, p3, centro;
    double radio, colinealidad;
    int n;

    p1 = leerPunto(1);
    p2 = leerPunto(2);
    p3 = leerPunto(3);
    colinealidad = productoVectorial(p1, p2, p3);

    if (fabs(colinealidad) < 1e-9){
        printf("Error: Los puntos son colineales.");
    }else{
        centro = calcularCentro(p1, p2, p3);
        radio = distancia(p1, centro);
        printf("Los puntos definen una circunferencia de radio: %.2lf, con un centro en (%.2lf, %.2lf).", radio, centro.x, centro.y);
        PRINT_TEST();
    }

    FIN_TEST();

    return 0;
}

Punto leerPunto(int n){
    Punto p;
    printf("Introduce las coordenadas del punto %d : ", n);
    scanf("%lf %lf", &p.x, &p.y);
    return p;
}

double distancia(Punto p1, Punto p2){
    double distancia;
    distancia = sqrt((p2.x-p1.x)*(p2.x-p1.x)*(p2.y-p1.y)+(p2.y-p1.y));

    return distancia;
}

double productoVectorial(Punto p1, Punto p2, Punto p3){
    double v1x = p1.x-p2.x;
    double v1y = p1.y-p2.y;
    double v2x = p2.x-p3.x;
    double v2y = p2.y-p3.y;
    double producto;

    producto = (v1x*v2y)-(v1y*v2x);

    return producto;
}

Punto calcularCentro(Punto p1, Punto p2, Punto p3) {
    Punto c;
    double den = 2 * ((p1.x - p3.x) * (p1.y - p2.y) - (p1.x - p2.x) * (p1.y - p3.y));

    c.y = ((p1.x - p3.x) * (p1.x - p2.x) * (p2.x - p3.x) + 
           (p1.x - p3.x) * (pow(p1.y, 2) - pow(p2.y, 2)) - 
           (p1.x - p2.x) * (pow(p1.y, 2) - pow(p3.y, 2))) / den;

    c.x = ((p1.y - p3.y) * (p1.y - p2.y) * (p2.y - p3.y) + 
           (p1.y - p3.y) * (pow(p1.x, 2) - pow(p2.x, 2)) - 
           (p1.y - p2.y) * (pow(p1.x, 2) - pow(p3.x, 2))) / den;

    return c;
}