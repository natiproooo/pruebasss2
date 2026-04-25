#include <stdio.h>
#include <stdlib.h>
//#include "../.vscode/test/TEST.h"

#define MAX 100 

typedef double tipo_polinomio[MAX]; 

extern void PROBAR (double polinomio[], double derivado[], int grado);

void leerPolinomio(double p[], int *n); 
void leerPolinomio(double p[], int *n){

}

void derivarPolinomio(double p[], int *n, double dp[]);
void escribirPolinomio(double p[], int n);

int main(int argc, char *argv[])
{
    //INICIO_TEST();

    
    tipo_polinomio variable_polinomio = {0};
    tipo_polinomio variable_vector_derivada = {0};
    int grado;
    int grado_derivado;

    leerPolinomio(polinomio, &grado);

    grado_derivado = grado;
    derivarPolinomio(polinomio, &grado_derivado, derivada);

    printf("\nEl polinomio derivado es: ");
    escribirPolinomio(derivada, grado_derivado);
    printf("\n");
    
    //PRINT_TEST("PROBAR");  
    //if (argc > 1)   
        //PROBAR(polinomio, derivada, grado_derivado);
    //FIN_TEST();
    return 0;
}

void leerPolinomio(double p[], int *n, double dp[]){
    printf("Introduce el grado del polinomio: ");
    scanf("%d", n);

    for(int i = 0; i <= *n; i++){
        printf("Coficiente de x^%d: ", i);
        scanf("%lf", &p[i])
    }
}

void derivarPolinomio(double p[], int *n, double dp[]){
    int grado_original = *n;
    
    if(grado_original == 0){
        dp[0] = 0;
        *n = 0;
    }else{
        for (int i = 1; i <= grado_original; i++){
            dp[i - 1] = p[i] * i;
        }
        *n = grado_original - 1;
    }
}

void escribirPolinomio(double p[], int n) {
    for (int i = 0; i <= n; i++) {
        printf("%.2lf", p[i]);
        if (i > 0) printf("x^%d", i);
        if (i < n) printf(" + ");
    }
}