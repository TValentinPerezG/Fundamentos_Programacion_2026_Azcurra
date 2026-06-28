/* 
Desarrollar una funcion recursiva en C que reciba un array de numeros enteros, su tamaño y un valor, la cual debe retornar la cantidad de elementos 
dentro del array cuyo valor es mayor al pasado por parametro. Ejemplo:
Invocacion con: vector[5] = {3, 1, 4, 5, 2}, valor = 2 y tamaño = 5. Debe devolver 3. 
*/

#include <stdio.h>
#include <stdbool.h>

typedef int t_vec[100];

int mayores_vector_recursivo(int valor, int ml, t_vec vector){

    if(ml<=0){
        return 0;
    }
    else if(valor < vector[ml-1]){
        return 1 + mayores_vector_recursivo(valor, ml-1, vector);
    }

    return mayores_vector_recursivo(valor, ml-1, vector);
}

int main(){
    t_vec vector = {3, 1, 4, 5, 2};
    int valor = 2;
    int tamaño = 5;
    int muestra = mayores_vector_recursivo(valor, tamaño, vector);

    printf("\n%i\n", muestra);

    return 0;
}