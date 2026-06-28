/* 
Desarrollar una funcion recursiva en lenguaje C que reciba un arreglo y su maximo logico, y devuelva la suma de los elementos que estan en las posiciones pares del arreglo.
*/

#include <stdio.h>
#include <stdbool.h>

typedef int t_vec[100];

int suma_arreglo_recursiva(t_vec arreglo, int ml){

    if(ml <= 0){
        return 0;
    }
    else if((ml-1)%2 == 1){
        return suma_arreglo_recursiva(arreglo, ml-1);
    }

    return arreglo[ml-1] + suma_arreglo_recursiva(arreglo, ml-2);
}

int main(){
    t_vec array={10,2,3,4,5};
    int ml=5;
    int sumatoria=suma_arreglo_recursiva(array,ml);

    printf("\nsumatoria: %i\n", sumatoria);

    return 0;
}