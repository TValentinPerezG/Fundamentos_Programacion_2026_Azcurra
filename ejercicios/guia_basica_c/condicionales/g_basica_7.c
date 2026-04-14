#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Ingresar un número (del 1 al 7) que representa un día de la semana, escribir el
    nombre del día correspondiente. En el caso de haber ingresado un número fuera de
    rango indicarle del error al usuario. */

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