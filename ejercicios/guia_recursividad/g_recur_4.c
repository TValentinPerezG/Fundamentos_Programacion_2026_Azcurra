/*
4) Desarrollar un programa que calcule y muestre por pantalla la división de 2
números mediante restas sucesivas en forma recursiva. Ambos números deben
ser ingresados por el usuario.
*/
#include <stdio.h>
#include <stdbool.h>

int resta_sucesiva_recu(int num, int divisor){
    if(num<divisor){
        return 0;
    }
    return 1 + resta_sucesiva_recu(num-divisor, divisor);
}

int main(){
    int num = 119;
    int div = 20;
    int receptor = resta_sucesiva_recu(num, div);

    printf("\n%i\n", receptor);
    return 0;
}