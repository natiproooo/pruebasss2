#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "../.vscode/test/TEST.h"

/* Prototipos de funciones */
void leer_opcion_menu(char *c);
void ejecutar_opcion(char c);
void hola_mundo(void);
void tirada_dados(void);
void fibonacci(void);
void saludo(const char mensaje[]);
void pausa();
void limpiar();

int main()   
{

    INICIO_TEST();

    char c;

    do
    {
        leer_opcion_menu(&c);
        ejecutar_opcion(c);
    } while (c != '4');

    FIN_TEST();
    return 0;
}

void ejecutar_opcion(char c)
{
    switch (c)
    {
    case '1':
        hola_mundo();
        pausa();
        break;
    case '2':
        tirada_dados();
        pausa();
        break;
    case '3':
        fibonacci();
        pausa();
        break;
    case '4':
        printf("\n\nFIN DE EJECUCIÓN");
        break;
    default:
        printf("\a");
        break;
    }
}

void leer_opcion_menu(char *c)
{
    printf("\n\n\n      MENU DE OPCIONES\n");
    printf("      ================\n\n");
    printf("\t1.- Mostrar mensaje hola mundo\n");
    printf("\t2.- Contar tiradas \n");
    printf("\t3.- Mostrar Fibonacci\n");
    printf("\t4.- Finalizar ejecucion\n\n");
    printf("\t\tIntroduzca opcion: ");
    scanf(" %c", c);
}

void saludo(const char mensaje[])
{
    printf("%s\n", mensaje);
    PRINT_TEST(" Hola Mundo ");
}
void hola_mundo(void)
{
    saludo("Hola Mundo");
}

void tirada_dados(void)
{
    int contador_ganadoras = 0;
    int dado1, dado2, suma

    for(int i = 0; i < 50; i++){
        dado1 = rand() % 6 + 1;
        dado2 = rand() % 6 + 1;
        suma = dado1 + dado2;

        if(suma == 7 || suma == 11){
            contador_ganadoras++;
        }
    }
 
    printf("Numero de tiradas ganadoras: %d\n", contador_ganadoras);
    PRINT_TEST("%d ", contador_ganadoras);
}

void fibonacci(void)
{
    int anterior = 0;
    int actual = 1;
    int termino = 1;

    //printf("%10d ", termino);
    //PRINT_TEST("%10d ", termino);

    while (INT_MAX - termino >= anterior)
    {
        termino = anterior + actual;

        printf("%10d ", termino);
        PRINT_TEST("%10d ", termino);

        anterior = actual;
        actual = termino;
    }
}


void limpiar(){ char c; // Vaciar buffer de entrada 
	while ((c = getchar()) != '\n' && c != EOF && c!=' '); 
}

void pausa(){
    limpiar();
    printf("\nPulse una tecla para continuar...");
    limpiar();
}

