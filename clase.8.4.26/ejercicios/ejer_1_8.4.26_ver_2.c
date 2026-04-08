#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Ingresar un numero y preguntar si es primo o no */
/* Esta version se detiene 
apenas encuentra que no es primo, apenas encuentra un divisor*/

void main(){
    int N, i;
    bool EsPrimo;

    EsPrimo=true;
    i=2;

    printf("Ingrese el numero para ver si es primo: ");
    scanf("%d", &N);

    while(i <= N/2 && EsPrimo){
        if(N%i==0){
            EsPrimo=false;
        }
        else{
            i++;
        }
    }

    if(EsPrimo){
        printf("El numero %d es primo", N);
    }
    else{
        printf("El numero %d no es primo", N);
    }
}