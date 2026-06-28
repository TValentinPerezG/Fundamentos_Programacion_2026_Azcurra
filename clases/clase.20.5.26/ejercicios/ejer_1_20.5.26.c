#include <stdio.h>
#define MAX 100
typedef int tvec[MAX];

//Ordenamieto por burbujeo sin optimizar

void ordenar_por_burbujeo(tvec vec, int ml){
    int i, j, aux;

    for(i = 1; i<ml;i++){ //pasos
        for(j=0;j<ml-i;j++){ //comparaciones
            if(vec[j] > vec[j+1]){ //intercambios
                aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }
}

int main(){
    tvec vec = {23, 10, 31, 9};
    int ml=4;
    int i;
    ordenar_por_burbujeo(vec,ml);


}