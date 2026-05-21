#include <stdio.h>
#include <stdbool.h>
#define MAX 100
typedef int tvec[MAX];

//Ordenamieto por burbujeo optimizado

void ordenar_por_burbujeo(tvec vec, int ml){
    int i=1, j, aux;
    bool hubo_cambios = true;

    while((i<ml) && hubo_cambios){ //pasos, ahora se detiene si no hubieron intercambios
        hubo_cambios=false;
        for(j=0;j<ml-i;j++){ //comparaciones
            if(vec[j] > vec[j+1]){ //intercambios
                aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
                hubo_cambios=true;
            }
        }
        i++;
    }
}

int main(){
    tvec vec = {9, 10, 31, 23};
    int ml=4;
    int i;
    ordenar_por_burbujeo(vec,ml);
    for(i=0;i<ml;i++){
        printf("%i\n", vec[i]);
    }

}