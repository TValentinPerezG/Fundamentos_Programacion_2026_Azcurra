/*
12) Desarrollar un programa que muestre los primeros N números naturales. El
número N lo debe ingresar el usuario.
*/
#include <stdio.h>
#include <stdbool.h>

int ingreso(){
    int num;
    printf("Ingrese un numero natural: ");
    scanf("%i", &num);

    return num;
}

void muestra_recur(int num){
    if(num==0){
        printf("%i ", num);
    }
    else if(num>0){
        muestra_recur(num-1);
        printf("%i ", num);
    }
}

int main(){
    int num;
    
    num = ingreso();

    muestra_recur(num);

    return 0;
}