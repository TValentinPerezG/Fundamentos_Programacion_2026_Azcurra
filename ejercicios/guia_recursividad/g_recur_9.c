/*
9) Desarrollar un programa que solicite al usuario el ingreso de un número
entero y muestre el resultado de sumar sus dígitos.
*/
#include <stdio.h>
#include <stdbool.h>

int suma_digitos_recu(int num){
    if(num%10 == num){
        return num;
    }
    return num%10 + suma_digitos_recu(num/10); 
}

int main(){
    int num=1233;
    int receptor = suma_digitos_recu(num);

    printf("%i", receptor);
    return 0;
}