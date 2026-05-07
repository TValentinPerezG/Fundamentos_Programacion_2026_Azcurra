#include <stdio.h>
#include <stdlib.h>

/* Escribir una función que reciba un valor n, entero, y devuelva la suma de los
valores entre 0 y n.
Ejemplos:
suma_n(5) = 15
suma_n(120) = 7260
suma_n(120120) = 7214467260
*/

int ingreso_numero(){
    int ingreso;

    printf("Ingrese el numero y se le dara la suma de todos los valores entre 0 y el numero: ");
    scanf("%i", &ingreso);

    return ingreso;
}

long long calcular_suma_rango(int numero){
    long long sum_rango=0;
    int i;

    for(i=1;i<=numero;i++){
        sum_rango= sum_rango + i;
    }

    return sum_rango;
}

int main(){
    int num;
    long long suma;

    num = ingreso_numero();

    suma = calcular_suma_rango(num);

    printf("%lld\n", suma);

    return 0;
}