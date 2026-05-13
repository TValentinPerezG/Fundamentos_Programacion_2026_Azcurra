/* Dado un vector a ordenado ascendente de longitud ml y un elemento p del
mismo tipo que los elementos del vector, insertar p en el vector a de modo
que siga ordenado. Validar previamente que en el vector haya espacio libre para
guardar el nuevo dato.
Se solicita resolver lo solicitado recorriendo una sola vez el vector y sin utilizar
un arreglo auxiliar. */

#include <stdio.h>
#include <stdbool.h>

#define MAX 100
typedef int t_vector[MAX];

bool insertar_ent(int num, t_vector vec, int *ml){
    bool posible=true;
    int i=0;

    if(*ml == MAX){
        posible = false;
    }
    else if(vec[*ml - 1] <= num){
        vec[*ml] = num;
        *ml = *ml + 1;
    }
    else{
        while((*ml - 1 - i) >= 0 && num < vec[*ml - 1 -i] ){
            vec[*ml - i] = vec[*ml -1 - i];
            i++;
        }
        vec[*ml - i] = num;
        *ml = *ml + 1;
    }

    return posible;
}