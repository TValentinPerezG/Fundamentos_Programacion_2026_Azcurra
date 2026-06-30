/*
Escribir una función en lenguaje C llamada crear_estructura_dinamica que reciba un arreglo unidimensional de enteros ya cargado y su máximo lógico. La función debe 
devolver un puntero a una estructura dinámica que contenga los elementos del arreglo recibido y utilice solo el espacio de memoria necesario.

Escribir un programa main que:

Invoque la función crear_estructura_dinamica con:
int vec[100] = {4, 8, 23, 25, 18};
Invocar la función mostrar_estructura_dinamica, pasándole la estructura y la cantidad de elementos. Esta función no debe desarrollarse, solo invocarse correctamente si el puntero no es NULL.
*/

#include <stdio.h>
#include <stdlib.h>

int *crear_estructura_dinamica(int vec[100], int ml){
    int *puntero = malloc(ml * sizeof(int));
    int i;

    if(puntero != NULL){
        for(i=0;i<ml;i++){
            puntero[i] = vec[i];
        }
    }

    return puntero;
}

int main(){
    int vec[100] = {4, 8, 23, 25, 18};
    int ml=5;
    int *puntero;

    puntero = crear_estructura_dinamica(vec, ml);

    if(puntero == NULL){
        printf("Hubo un error, no hay memoria disponible.");
    }
    else{
        mostrar_estructura_dinamica(puntero, ml);
    }

    free(puntero);

    return 0;
}