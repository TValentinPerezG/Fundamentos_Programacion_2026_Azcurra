#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Escribir una función que dados 2 números, calcule el porcentaje que el
primero representa respecto del segundo. */

float porcentaje_dif(int parte, int total){
    float dif_porcentaje;

    dif_porcentaje = ((float)parte / total) * 100;

    return dif_porcentaje;
}

int main(){
    int num1, num2;
    float porcentaje;

    printf("ingrese el primer numero: ");
    scanf("%i", &num1);
    printf("ingrese el segundo numero: ");
    scanf("%i", &num2);

    porcentaje = porcentaje_dif(num1, num2);
    printf("\nEl porcentaje de %i en %i es %.2f", num1, num2, porcentaje);


    return 0;
}
