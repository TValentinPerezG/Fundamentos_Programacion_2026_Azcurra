/*
5) Desarrollar una función recursiva para obtener en mayor valor en un vector
de números enteros.
*/
#include <stdio.h>
#include <stdbool.h>

typedef int t_vec[100];

/* No termino de entender como hacer que mantenga un valor separado*/

int mayor_vector_recu(t_vec vec, int ml){
    if(ml<=0){
        return;
    }
    else{
        if(vec[ml-1] > 0){
            return vec[ml-1];
        }
    }
    return mayor_vector_recu(vec, ml-1);
}


int main(){
    t_vec vector = {1,5,3,10,4};
    int ml=5;
    int receptor = funcion();

    printf("%i", receptor);
    return 0;
}