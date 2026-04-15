#include <stdio.h>
#include <stdlib.h>

/* Ingresar un numero y preguntar si es primo o no */

void main(){
    int divisor = 0, N, i;

    printf("Ingrese el numero para ver si es primo: ");
    scanf("%d", &N);

    for(i = 2;i <= N/2;i++){
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
}