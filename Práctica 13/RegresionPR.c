void leer_opcion(char *c){
    printf("MENU OPCIONES PARA RECTA REGRESION\n");
    printf("==================================\n\n");
    printf("\t1.- Insertar un nuevo punto experimental\n");
    printf("\t2.- Imprimir en pantalla listado numerado de puntos\n");
    printf("\t3.- Eliminar un punto\n");
    printf("\t4.- Recta de regresión\n");
    printf("\t0.- Finalizar programa\n\n");
    printf("\t\tIntroduzca opción: ");
    scanf(" %c", c);   // con espacio para ignorar saltos de línea
}

int calcular_regresion(tipo_vector x,tipo_vector y,int n,double *a, double *b, double *r)

//   a     ordenada en el origen
//   b     pendiente
//   r     coeficiente de correlación
// valor devuelto    0=normal, 1=horizontal, 2=vertical, 3=todos iguales