#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void no_alfabeticos(char cad[]);

void no_alfabeticos(char cad[]){

    int vocales, consonantes, puntuacion, otros = 0;
    int i = 0;
    char c;

    while(cad[i] != '\0'){
        c = tolower(cad[i]);
        
        if(c != " "){
            
            if(c == "a" || c == "e" || c == "i" || c == "o"|| c == "u"){
                vocales++;
            }
            }else if (c >= "a" && c <= "z"){
                consonantes++;
            }else if (c == "." || c == ";" || c == "."){
                puntuacion++;
            }else{
                otros++;
            }
        
        i++;

        }
    printf("El Conteo final es de:\n Vocales: %d \n Consonantes: %d \n Puntuación: %d \n Otros: %d \n", vocales, consonantes, puntuacion, otros); 
    
}
        
        
    
