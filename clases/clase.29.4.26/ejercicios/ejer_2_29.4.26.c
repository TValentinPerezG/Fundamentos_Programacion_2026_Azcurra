#include <stdio.h>
//al llamar al vector en nuestra funcion, tenemos que avisarle a la funcion que es un vector
void imprimirVector(int vec[], int tamanio){
    int i;
    for (i = 0; i < tamanio; i++){
        printf("\n%i", vec[i]);
    }
    printf("\n");
}

int main(){
    int vector[] = {1,2,3,4,5,8};

    //int tamanio = 5;
    //sirve pero si el vector se hace mas grande no mostraremos valores nuevos

    int tamanio = sizeof(vector) / sizeof(vector[0]); 
    //te da el tamaño actual del vector al dividir el tamaño total
    //con el tamaño de una de sus celdas

    imprimirVector(vector, tamanio);
    //Cuando paso el vector no pongo el nombre
    
    return 0;
}