#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "../.vscode/test/TEST.h"


int ackermann(int m, int n, int a);

int main(){

    INICIO_TEST();
    int m, n, resultado;


    printf("Introduce el número m y el número n:");
    scanf("%d %d", &m, &n);

    resultado = ackermann(m, n);

    printf("El resultado de la función de Ackermann es: %d\n", resultado);
    PRINT_TEST("%d ", resultado);

    FIN_TEST();

    return 0; 
}

int ackermann(int m, int n, ){
    if(m==0){
       
        return (n + 1); 
    }
    else if(m > 0 && n==0){
        
        return ackermann(m -1 , 1);
        
    }
    else{
        
        return ackermann(m - 1,ackermann(m, n - 1));
    }
}