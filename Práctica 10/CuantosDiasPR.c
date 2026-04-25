#include <stdio.h>
#include "../.vscode/test/TEST.h"

typedef struct {
    int dia;
    int mes;
} tipo_fecha;

extern void PROBAR(tipo_fecha primera, tipo_fecha segunda, int resultado);

int main(int argc, char *argv[])
{
    INICIO_TEST();

    tipo_fecha f1, f2;
    int dias_totales = 0;
    int dias_por_mes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Ingrese la primera fecha en formato dia/mes (por ejemplo, 25/12): ");
    scanf("%d/%d", &f1.dia, &f1.mes);

    printf("Ingrese la segunda fecha en formato dia/mes: ");
    scanf("%d/%d", &f2.dia, &f2.mes);

    
    int total_f1 = f1.dia;
    for(int i = 0; i < f1.mes - 1; i++) total_f1 += dias_por_mes[i];

    int total_f2 = f2.dia;
    for(int i = 0; i < f2.mes - 1; i++) total_f2 += dias_por_mes[i];

    
    if (total_f2 >= total_f1) {
        dias_totales = total_f2 - total_f1;
    } else {
        dias_totales = (365 - total_f1) + total_f2;
    }

    if (argc > 1) {
        PRINT_TEST("PROBAR");
        PROBAR(f1, f2, dias_totales);
    }

    FIN_TEST();
    return 0;
}