#include <stdio.h>
#define MAX 100
typedef int tvec[MAX];

//Ordenamieto por seleccion

void ordenar_por_seleccion(tvec vec, int ml){
    int i, j, aux, posMinimo;

    for(i = 0; i < ml - 1; i++){ //minimo
        posMinimo = i;
        for(j = i+1; j < ml; j++){ //comparaciones
            if(vec[j] > vec[posMinimo]){ //cambiamos minimo
                posMinimo = j;
            }
        }
        aux = vec[i]; //hacemos intercambio con el minimo
        vec[i] = vec[posMinimo];
        vec[posMinimo] = aux;
    }
}

int main(){
    tvec vec = {23, 10, 31, 9};
    int ml=4;
    int i;
    ordenar_por_seleccion(vec,ml);
    for(i=0;i<ml;i++){
        printf("%i\n", vec[i]);
    }

}