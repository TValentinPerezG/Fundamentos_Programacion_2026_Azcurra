#include <stdio.h>
#include <stdbool.h>
#define MAX 100
typedef int tvec[MAX];

//Ordenamieto por burbujeo sin optimizar

int busqueda_binaria(tvec vec, int ml, int valor_buscado){
    int devolver = -1;
    int inicio = 0;
    int fin = ml;
    int centro;
    bool encontrado = false;

    while((inicio <fin) && !encontrado){
        centro = (inicio + fin)/2; //bucamos la posicion intermedia
        if(vec[centro] == valor_buscado){ //si esta en esta posicion se encontro
            encontrado=true;
        }
        else{
            if(vec[centro] <valor_buscado){ //si es menor al buscado, seguimos desde el centro para arriba
                inicio = centro + 1;
            }
            else{ //si es mayor al buscado, seguimos cortando toda la parte superior del vector
                fin = centro - 1;
            }
        }
    }
    if(encontrado){ //si se encontro el valor, se guarda la posicion en la que se encontro
        devolver = centro;
    }

    return devolver;
}

int main(){
    tvec vec = {9, 10, 35, 60, 70, 80, 100};
    int ml=7;
    int valor;
    int posicion;
    printf("Ingrese valor: ");
    scanf("%i", &valor);

    posicion = busqueda_binaria(vec,ml,valor);

    if(posicion == -1){
        printf("no ta\n");
    }
    else{
        printf("se encontro en %i\n", posicion);
    }

}