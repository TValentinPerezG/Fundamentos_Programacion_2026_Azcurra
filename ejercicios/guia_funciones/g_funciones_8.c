#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Escribir una función que dados a y b devuelva el resto de la división entera,
sin utilizar el operador correspondiente de lenguaje. Para esta resolución deben
considerar la utilización de restas sucesivas. */

int calc_resto(int numerador, int divisor){
    int total_resto = numerador;

    while (total_resto >= divisor){
        total_resto = total_resto - divisor;
    }

    return total_resto;
}

int main(){
    int a, b, resto;

    printf("Ingrese el numerador: ");
    scanf("%i", &a);
    printf("Ingrese el divisor: ");
    scanf("%i", &b);

    resto = calc_resto(a, b);

    printf("El resto de la division de %i dividido %i es %i", a, b, resto);

    return 0;
}

