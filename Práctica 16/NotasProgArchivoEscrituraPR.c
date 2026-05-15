#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "../.vscode/test/TEST.h"

#include <stdio.h>
#include <string.h>

#define MAX_ALUMNOS 100

int main()
{
    INICIO_TEST();

    float hito1, hito2, examen, autoeval, nota;
    char nombre[50];
    char c; // Para limpiar el buffer
    int num_al = 0;
    int lectura_ok;
    FILE *entrada;
    FILE *salida;


    entrada = fopen("alumnos.txt", "r");
    salida = fopen("notas.txt", "w");

    if (entrada == NULL || salida == NULL) return 1;


    printf("Calculadora de Nota Final\n");
    printf("--------------------------\n");
    printf("Instrucciones: Introduzca el nombre y 4 notas. Escriba 0 como nombre para finalizar.\n");
    
    printf("\n[%d/%d] Introduzca el nombre y 4 notas: ", num_al + 1, MAX_ALUMNOS);
    lectura_ok = fscanf(entrada, " %s %f %f %f %f", nombre, &hito1, &hito2, &examen, &autoeval);
    while ((c = getchar()) != '\n' && c != EOF);

    while (lectura_ok == 5 && strcmp(nombre, "0") != 0 && num_al < MAX_ALUMNOS)
    {
        nota = (examen * 0.85f) + (hito1 * 0.05f) + (hito2 * 0.05f) + (autoeval * 0.05f);
        printf(" -> La nota final de %s es: %.2f\n", nombre, nota);
        fprintf(salida, "%s %.2f\n", nombre, nota);
        num_al++;
        
        if (num_al < MAX_ALUMNOS) {
            printf("\n[%d/%d] Introduzca el nombre y 4 notas (0 0 0 0 0 para salir): ", num_al + 1, MAX_ALUMNOS);
            lectura_ok = fscanf(entrada, " %s %f %f %f %f", nombre, &hito1, &hito2, &examen, &autoeval);
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            lectura_ok = 0; 
        }
    }

    fclose(entrada);
    fclose(salida);

    
    printf("\nProceso terminado. Se calcularon %d notas.\n", num_al);
    
    if (argc > 1){
        PROBAR();
        PRINT_TEST("PROBAR");
    }  
    FIN_TEST();
    return 0;
}