/*
Desarrollar una función recursiva para realizar una 
búsqueda binaria en un vector.
*/
#include <stdio.h>
#include <stdbool.h>

typedef int t_vec[100];

int busqueda_binaria_recu(t_vec vec, int inf, int ml, int valor_busc){
    int centro= inf + ((ml-inf)/2);
    if(vec[centro]==valor_busc){
        return centro;
    }
    else{
        if(vec[centro]<valor_busc){
            return busqueda_binaria_recu(vec, 0, centro, valor_busc);
        }
    }
}

int main(){
    t_vec vec = {9, 10, 35, 60, 70, 80, 100};
    int ml=7;
    int valor = 35;
    int posicion = busqueda_binaria_recu(vec, 0, ml, valor);

    printf("\n%i\n", posicion);
    return 0;
}