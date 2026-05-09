#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
//#include "../.vscode/test/TEST.h"


typedef struct
{
    int numerador;
    int denominador;
} tipo_racional;

tipo_racional leer_racional();
tipo_racional simplificar(tipo_racional r);
tipo_racional sumar(tipo_racional num1, tipo_racional num2);
tipo_racional dividir(tipo_racional num1, tipo_racional num2);
void escribir(tipo_racional r);

int main() {
    tipo_racional r1, r2, resultado;

    r1 = leer_racional();
    r2 = leer_racional();

    resultado = sumar(r1, r2);
    escribir(resultado);
    printf("\n");


    resultado = dividir(r1, r2);
    escribir(resultado);
    printf("\n");

    return 0;
}

tipo_racional leer_racional(){
    tipo_racional n;
    do
    {
        printf("Ingrese el numerador: ");
        scanf(" %i", &n.numerador);
        printf("Ingrese el denominador: ");
        scanf(" %i", &n.denominador);
        if(n.denominador <=0){
            numerador = numerador * (-1);
            denominador = denominador * (-1);
        }
    } while (n.denominador <= 0);

    return simplificar(n);
}
    
tipo_racional simplificar(tipo_racional r) {
    int a, b, temporal, mcd;

    a = abs(r.numerador);
    b = abs(r.denominador);

    while (b != 0) {
        temporal = b;
        b = a % b;
        a = temporal;
    }
    mcd = a;

    if (mcd > 0) {
        r.numerador /= mcd;
        r.denominador /= mcd;
    }

    if (r.denominador < 0) {
        r.numerador = -r.numerador;
        r.denominador = -r.denominador;
    }

    return r;
}

tipo_racional sumar(tipo_racional num1, tipo_racional num2){

    tipo_racional r;

    r.numerador = (num1.numerador * num2.denominador) + (num2.numerador * num1.denominador);
    r.denominador = (num1.denominador * num2.denominador);

    r = simplificar(r);

    return r;
} 

tipo_racional dividir(tipo_racional num1, tipo_racional num2){
    tipo_racional r;

    r.numerador = (num1.numerador * num2.denominador);
    r.denominador = (num1.denominador * num2.numerador);
    
    r = simplificar(r);

    return r;
} 

void escribir(tipo_racional r){
    printf("%d/%d", r.numerador, r.denominador);
}