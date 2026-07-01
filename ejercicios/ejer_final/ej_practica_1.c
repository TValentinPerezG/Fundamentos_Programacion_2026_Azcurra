/*
* Escribir un programa que solicite al usuario N números enteros y los almacene en un arreglo.
* Implementa el método de burbuja para ordenar el arreglo de menor a mayor y muestra el arreglo antes y después de ordenar.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 100
typedef int t_vec[MAX];

void pedir_array(t_vec vector, int *ml){
    int i=0;
    int ingreso;
    printf("Ingrese enteros, si quiere detenerse ingrese -1: ");
    scanf("%i", &ingreso);

    while(i<MAX && ingreso != -1){
        vector[i] = ingreso;

        i++;

        printf("Ingrese enteros, si quiere detenerse ingrese -1: ");
        scanf("%i", &ingreso);
    }
    *ml = i;
}

void mostrar_array(t_vec vector, int ml){
    int i;

    for(i=0;i<ml;i++){
        printf("%i\t", vector[i]);
    }
}

void ordenar_burbujeo(t_vec vec, int ml){
    int i, j, aux;
    bool encontrado=true;
    i=1;

    while(i<ml && encontrado){
        encontrado=false;
        for(j=0;j<ml-i;j++){
            if(vec[j] > vec[j+1]){
                aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
                encontrado=true;
            }
        }
        i++;
    }
}

int main(){
    t_vec vector;
    int ml;

    pedir_array(vector, &ml);

    mostrar_array(vector, ml);

    ordenar_burbujeo(vector, ml);

    mostrar_array(vector, ml);

    return 0;
}