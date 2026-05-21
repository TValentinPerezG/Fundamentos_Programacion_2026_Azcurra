#include <stdio.h>
#define MAX 100
typedef int tvec[MAX];

//Ordenamieto por burbujeo sin optimizar

int busqueda_lineal(tvec vec, int ml, int valor_buscado){
    int devolver = -1;
    int posicion = 0;

    while((posicion <ml) && (vec[posicion] != valor_buscado)){
        posicion++;
    }
    if(posicion<ml){
        devolver = posicion;
    }

    return devolver;
}

int main(){
    tvec vec = {23, 10, 31, 9};
    int ml=4;
    int i;
    ordenar_por_burbujeo(vec,ml);


}