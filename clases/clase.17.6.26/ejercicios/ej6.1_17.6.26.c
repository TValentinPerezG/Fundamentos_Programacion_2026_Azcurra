/*Mostrar numeros pares entre 1 y X*/

#include <stdio.h>

void mostrar_pares_recursivo(int X){
    if(X>1){
        if(X%2==0){
        mostrar_pares_recursivo(X - 2);
        printf("\n%i", X);
        }
        else{
            mostrar_pares_recursivo(X - 1);
        }
    }
}

int main(){
    int num=9;

    mostrar_pares_recursivo(num);

    return 0;
}