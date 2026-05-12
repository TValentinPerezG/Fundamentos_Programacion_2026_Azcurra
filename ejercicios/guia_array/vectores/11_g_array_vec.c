/* Idem problema anterior, pero el vector está ordenado ascendente */

#include <stdio.h>
#define MAX 100000
typedef int Tvec[MAX];

void busquedaVector(Tvec a, int p, int n, int *posicion){
    *posicion = 0;

    while(*posicion < n && a[*posicion] != p){
        *posicion = *posicion + 1;
    }

    if(*posicion == n){
        printf("No se encontro el valor p en el vector.");
    }
    
}