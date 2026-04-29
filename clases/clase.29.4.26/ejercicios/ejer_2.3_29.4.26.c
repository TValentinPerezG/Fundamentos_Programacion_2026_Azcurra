#include <stdio.h>
//al llamar al vector en nuestra funcion, tenemos que avisarle a la funcion que es un vector
void imprimirVector(int vec[], int tamanio){
    int i;
    for (i = 0; i < tamanio; i++){
        printf("\n%i", vec[i]);
    }
    printf("\n");
}

void modificarVector(int vec[], int tamanio){
    for (int i = 0; i < tamanio; i++){
        vec[i] = vec[i] * 2;
    }
}

int main(){
    int vector[] = {11,22,33,44,55,87};

    //int tamanio = 5;
    //sirve pero si el vector se hace mas grande no mostraremos valores nuevos

    int tamanio = sizeof(vector) / sizeof(vector[0]); 
    //te da el tamaño actual del vector al dividir el tamaño total
    //con el tamaño de una de sus celdas

    //nuestro maximo fisico, todos los elementos totales en nuestro vector
    imprimirVector(vector, tamanio);
    //Cuando paso el vector no pongo el nombre

    modificarVector(vector, 3);
    //Lo que hice en la version local de la funcion con la variable se refleja en el main
    //porque los vectores siempre se llaman por referencia
    //esto ocurre porque llamar vector es como llamar &vector[0]
    
    //aca trabajo con mi maximo logico, aunque los otros valores existen, los relevantes son estos 5
    //por lo que 
    imprimirVector(vector, 3);
    
    return 0;
}