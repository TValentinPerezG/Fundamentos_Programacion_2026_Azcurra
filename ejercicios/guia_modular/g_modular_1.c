
#include <stdbool.h>
#include <stdio.h>

/*bool es_multiplo(int num, int divisor){
    bool resultado;
    resultado = num % divisor == 0;
    return resultado;
}
int suma(int a, int b){
    int resultado;
    resultado = a + b;
    return resultado;
}

ESTAS 2 VERSIONES SON REDUNDANTES, NO UTILIZAR PORQUE NO ES EFICIENTE
*/


bool es_multiplo(int num, int divisor){
    return num % divisor == 0;
}

int suma(int a, int b){
    return a + b;
}

