#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "../.vscode/test/TEST.h"

int resolverEcuacion( double a, double b, double c, double *sol1, double *sol2);

int main(){
    INICIO_TEST();
    double a,b,c,sol1,sol2;

    printf("Determine los valores de a, b, c, respectivamente:");
    scanf("%lf %lf %lf", &a, &b, &c);

    int soluciones = resolverEcuacion(a, b, c, &sol1, &sol2);

    if(estado == 2){
        printf("Las soluciones de x son %.2lf y %.2lf.", sol1, sol2);
        PRINT_TEST("%.2lf %.2lf", sol1, sol2);
    
    }else if(estado == 1){
        printf("La solución de x es %.2lf.", sol1);
        PRINT_TEST("%.2lf ", sol1);

    }else{
        printf("No existe solución real para dicha ecuación.");
        PRINT_TEST("error");

    }

    FIN_TEST();
    return 0;
}

int resolverEcuacion( double a, double b, double c, double *sol1, double *sol2){
    double discriminante

    discriminante = (b*b)-4*a*c

    if(discriminante > 0){
        *sol1 = (-b + sqrt(discriminante)) / (2 * a);
        *sol2 = (-b - sqrt(discriminante)) / (2 * a);

        return 2;

    }else if (discriminante == 0){
        *sol1 = -b/(2*a);
        *sol2 = -b/(2*a);

        return 1;

    }else{

        return 0;
    }


}