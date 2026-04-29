#include <stdio.h>

int main(){
    int vector[] = {1,2,3,4,5,8};

    //int tamanio = 5;
    //sirve pero si el vector se hace mas grande no mostraremos valores nuevos

    int tamanio = sizeof(vector) / sizeof(vector[0]); 
    //te da el tamaño actual del vector al dividir el tamaño total
    //con el tamaño de una de sus celdas

    for(int i = 0; i < tamanio; i++){
        printf("\n%i", vector[i]);
    }

    printf("\n");

    return 0;
}