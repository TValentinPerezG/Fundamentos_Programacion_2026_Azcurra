/*
7) Desarrollar un programa que muestre la suma de los primeros N números
naturales. El número N lo debe ingresar el usuario.
*/
#include <stdio.h>
#include <stdbool.h>

int suma_N_recu(int num){
    if(num==0){
        return 0;
    }
    return num + suma_N_recu(num-1);
}

int main(){
    int num = 7;
    int receptor = suma_N_recu(num);

    printf("%i\n", receptor);
    return 0;
}