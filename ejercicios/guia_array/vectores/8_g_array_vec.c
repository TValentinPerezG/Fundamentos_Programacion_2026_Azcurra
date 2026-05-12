/* Dadas las siguientes declaraciones de constantes y tipos:
#define MAX 1000
typedef int vector_t[MAX]
Desarrollar una función en lenguaje C que reciba como parámetros un vector
de tipo vector_t ya cargado y su máximo lógico, que devuelva:
- un valor de verdad que informe si el vector está ordenado
ascendentemente
- la menor diferencia entre elementos contiguos.
Se solicita resolver lo pedido recorriendo una sola vez al vector.
Ejemplo:
Dado el siguiente vector cuyo máximo lógico es 7, la función debe devolver true
y 1 (la menor diferencia entre 27 y 28).
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 1000
typedef int vector_t[MAX];

bool revisarVector(vector_t vec, int ml, int *dif_menor){
    bool ascendente = true;
    int i;
    
    if(ml > 1){
        if(vec[0] >= vec[1]){
        *dif_menor = vec[0] - vec[1];
        }
        else{
            *dif_menor = vec[1] - vec[0];
        }
    }
    else{
        *dif_menor = 0;
    }

    for(i=0;i<ml - 1;i++){
        if(vec[i] > vec[i+1]){
            ascendente = false;
            if(vec[i] - vec[i+1] < *dif_menor){
                *dif_menor = vec[i] - vec[i+1];
            }
        }
        else{
            if(vec[i+1] - vec[i] < *dif_menor){
                *dif_menor = vec[i+1] - vec[i];
            }
        }
    }

    return ascendente;
}

//version while

#include <stdio.h>
#include <stdbool.h>
#define MAX 1000
typedef int vector_t[MAX];

bool revisarVector(vector_t vec, int ml, int *dif_menor){
    bool ascendente = true;
    int i = 0;
    
    if(ml > 1){
        if(vec[0] >= vec[1]){
        *dif_menor = vec[0] - vec[1];
        }
        else{
            *dif_menor = vec[1] - vec[0];
        }
    }
    else{
        *dif_menor = 0;
    }

    while(ascendente || *dif_menor != 0 && ml > 1 && i < ml - 1){
        if(vec[i] > vec[i+1]){
            ascendente = false;
            if(vec[i] - vec[i+1] < *dif_menor){
                *dif_menor = vec[i] - vec[i+1];
            }
        }
        else{
            if(vec[i+1] - vec[i] < *dif_menor){
                *dif_menor = vec[i+1] - vec[i];
            }
        }
        i++;
    }

    return ascendente;
}