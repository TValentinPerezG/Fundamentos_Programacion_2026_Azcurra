#include <stdio.h>

/* Escribir una función que dados a y b devuelva el cociente de la división
entera, sin utilizar el operador correspondiente del lenguaje. Para esta
resolución deben considerar la utilización de restas sucesivas.
*/

int calc_cociente_entero (int dividendo, int divisor){
    int total_coci=0;

    while( dividendo >= divisor ){
        dividendo = dividendo - divisor;
        total_coci++;
    }

    return total_coci;
}


int main(){
    int cociente_ent, a, b;

    printf("Ingrese numero que quiere dividir: ");
    scanf("%d", &a);
    printf("Ingrese numero divisor: ");
    scanf("%d", &b);

    if(b =! 0){
        cociente_ent = calc_cociente_entero(a, b);

        printf("El cociente entero de la %d con %d es %d\n", a, b, cociente_ent);
    }
    else{
        printf("No es posible hacer el calculo ya que el divisor no puede ser 0");
    }

    return 0;
}

