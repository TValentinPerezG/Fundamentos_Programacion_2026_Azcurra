#include <stdio.h>
#include <stdlib.h>

/* Ingresar un numero y preguntar si es primo o no */

void main(){
    int divisor, N, i;

    divisor = 0;

    printf("Ingrese el numero para ver si es primo: ");
    scanf("%d", &N);

    for(i = 2;i < N;i++){
        if(N%i == 0){
            divisor++;
        }
    }

    if(divisor > 0){
        printf("El numero %d no es primo", N);
    }
    else{
        printf("El numero %d es primo", N);
    }
    return;
}