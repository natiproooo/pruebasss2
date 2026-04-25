#include <stdio.h>
#include <stdlib.h>
#include "../.vscode/test/TEST.h"

#define PI 3.1415
#define FE 0.00786   // Densidad hierro (Kg/cm³)
#define AG 0.01049   // Densidad plata (Kg/cm³)
#define AU 0.01932   // Densidad oro (Kg/cm³)
#define AL 0.0027    // Densidad aluminio (Kg/cm³)

typedef struct {
    float radio;
    float masa;
    float densidad;
} tipo_bola;

extern void PROBAR();

int main(int argc, char *argv[])
{
    INICIO_TEST();

    char opcion;
    float diametro;
    tipo_bola bola;
    int opcion_valida = 0; 

    
    do {
        printf("\n=== CALCULADORA DE MASA ESFERICA ===\n");
        printf("1. Hierro\n");
        printf("2. Plata\n");
        printf("3. Oro\n");
        printf("4. Aluminio\n");
        printf("Seleccione material (1-4): ");
        scanf(" %c", &opcion);

        switch(opcion) {
            case '1': 
                bola.densidad = FE;
                printf("\nMaterial seleccionado: HIERRO\n");
                opcion_valida = 1;
                break;
            case '2':
                bola.densidad = AG;
                printf("\nMaterial seleccionado: PLATA\n");
                opcion_valida = 1;
                break;
            case '3':
                bola.densidad = AU;
                printf("\nMaterial seleccionado: ORO\n");
                opcion_valida = 1;
                break;
            case '4':
                bola.densidad = AL;
                printf("\nMaterial seleccionado: ALUMINIO\n");
                opcion_valida = 1;
                break;
            default:
                printf("\nOpción no válida! Intente nuevamente.\n");
        }
    } while (!opcion_valida); 

    PRINT_TEST("PROBAR");  
    if (argc > 1)  PROBAR(); 

    
    printf("Introduzca el diámetro (cm): ");
    scanf("%f", &diametro);

    
    bola.radio = diametro / 2;
    float volumen = (4.0/3.0) * PI * bola.radio * bola.radio * bola.radio;
    bola.masa = bola.densidad * volumen;

    printf("\nResultados:\n");
    printf("Radio: %.2f cm\n", bola.radio);
    PRINT_TEST("%.2f", bola.radio);
    printf("Volumen: %.2f cm³\n", volumen);
    PRINT_TEST("%.2f", volumen);
    printf("Masa: %.2f Kg\n", bola.masa);
    PRINT_TEST("%.2f", bola.masa);

    FIN_TEST();
    return 0;
}