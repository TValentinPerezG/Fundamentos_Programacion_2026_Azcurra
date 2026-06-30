/*
Desarrollar un programa que calcule la factorial de un número en forma
recursiva.
*/
#include <stdio.h>
#include <stdbool.h>

int factorial_recursivo(int num){
    if(num == 0){
        return 1;
    }
    return num * factorial_recursivo(num-1);
}

int main(){
    int num;
    int receptor = factorial_recursivo(5);

    printf("\n%i\n", receptor);
    return 0;
}