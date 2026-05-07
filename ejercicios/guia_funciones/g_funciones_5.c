#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Escribir una función que dados a y b ambos de tipo entero devuelva a ^ b de
tipo double para los siguientes casos (no se puede utilizar ninguna biblioteca
de funciones matemáticas). Implementar una solución iterativa.
En las pruebas debe invocar a la función para los siguientes 5 casos:
i) a > 0 y b > 0
ii) a > 0 y b < 0
iii) a < 0 y b > 0
iv) a < 0 y b < 0
v) a > 0 y b = 0
Ejemplos:
i) a = 2 ; b = 3 ; resultado = 8
ii) a = -2 ; b = 3 ; resultado = 8
iii) a = -2 ; b = 0 ; resultado = 1
iv) a = -2 ; b = 0 ; resultado = 1 */

double resultado_pot(int base, int pot){
    int i = 1;
    double resu_pote;

    if(base > 0){
        if(pot > 0){
            resu_pote = base;
            for(i;i<pot;i++){
                resu_pote = resu_pote * base;
            }
        }
        else if(pot == 0){
            resu_pote = 1;
        }
        else{
            resu_pote = ((double)1/base);

            for(i;i<abs(pot);i++){
                resu_pote = resu_pote * ((double)1 / base);
            }
        }
    }
    else if(base < 0){
        if(pot > 0){
            resu_pote = base;
            for(i;i<pot;i++){
                resu_pote = resu_pote * base;
            }
        }
        else if(pot < 0){
            resu_pote = ((double)1/base);

            for(i;i<abs(pot);i++){
                resu_pote = resu_pote * ((double)1 / base);
            }
        }
    }

    return resu_pote;
}

int main(){
    int a, b;
    double pot_a_b;

    printf("Ingrese el valor del numero base: ");
    scanf("%i", &a);

    printf("Ingrese el valor al que se elevaba: ");
    scanf("%i", &b);

    pot_a_b = resultado_pot(a, b);

    printf("\n%.2lf", pot_a_b);

    return 0;
}