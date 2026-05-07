#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Escribir una función que reciba un valor entero y calcule el factorial del
mismo. Si no se puede calcular el factorial del valor recibido, la función deberá
devolver 0, de lo contrario deberá devolver el valor calculado.*/

int ingreso_numero(){
    int ingreso;

    printf("Ingrese el numero para recibir su factorial: ");
    scanf("%i", &ingreso);

    return ingreso;
}

long long calc_factorial(int numero){
    int i;
    long long factorial_calc=1;
    
    if(numero < 0){
        factorial_calc = 0;
    }
    else{
        for(i=2;numero>=i;i++){
            factorial_calc = factorial_calc * i;
        }
    }

    return factorial_calc;
}

int main(){
    int num;
    long long factorial;

    num = ingreso_numero();

    factorial = calc_factorial(num);

    printf("El factorial del numero %i es %lld\n", num, factorial);

    return 0;
}