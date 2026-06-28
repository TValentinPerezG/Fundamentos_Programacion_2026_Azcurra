#include <stdio.h>
#define MAX 100
typedef int tvec[MAX];

//Ordenamieto por seleccion

void ordenar_por_insercion(tvec vec, int ml){
    int i, j, aux;

    for(i = 1; i < ml ; i++){ //sub arreglos ordenados
        aux = vec[i]; //preservo nuevo elemento
        j = i - 1;
        while((j >= 0) && (vec[j] > aux)){ //encontrar posicion
            vec[j+1] = vec[j]; //desplazo elemento
            j = j - 1;
        }
        vec[j+1] = aux; 
    }
}

int main(){
    tvec vec = {23, 10, 31, 9, 4, 234, 45};
    int ml=7;
    int i;
    ordenar_por_insercion(vec,ml);
    for(i=0;i<ml;i++){
        printf("%i\n", vec[i]);
    }
}