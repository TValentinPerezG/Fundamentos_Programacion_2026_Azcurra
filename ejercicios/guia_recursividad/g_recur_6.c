/*
6) Desarrollar un programa que solicite al usuario el ingreso de un número
entero y lo muestre invertido. No se puede utilizar vectores.
*/
#include <stdio.h>
#include <stdbool.h>

void muestra_invertido_recu(int num){
    if(num%10!=num){
        printf("%i", num%10);
        muestra_invertido_recu(num/10);
    }
    else{
        printf("%i",num);
    }
}

int main(){
    int num= 123;

    muestra_invertido_recu(num);
    return 0;
}