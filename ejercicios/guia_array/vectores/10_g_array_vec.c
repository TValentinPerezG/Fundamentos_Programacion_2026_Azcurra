/* Dado un vector a de longitud n y un elemento p del mismo tipo que los
elementos del vector, buscar p en el vector a y devolver la posición que ocupa
en caso de encontrarlo o una señal en caso contrario. Suponer que no hay
repeticiones.
 */
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