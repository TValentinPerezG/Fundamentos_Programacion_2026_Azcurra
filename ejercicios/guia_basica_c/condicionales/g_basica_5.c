#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Ingresar un número entero y decir si:
a) es par o impar.
b) es mayor, menor o igual a cero. */

int main(){
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    if(num%2 == 0){
        printf("El numero %d es par\n", num);
    }
    else{
        printf("El numero %d es impar\n", num);
    }

    if(num == 0){
        printf("El numero ingresado es 0\n", num);
    }
    else if(num > 0){
        printf("El numero %d es mayor a 0\n", num);
    }
    else{
        printf("El numero %d es menor a 0\n", num);
    }

    return 0;
}