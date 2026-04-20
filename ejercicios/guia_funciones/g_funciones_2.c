#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Escribir una función que dado un número entero, devuelva un valor booleano
que indique si dicho número es primo o no. Antes de plantear una solución ten
presente las siguientes preguntas.

a) Con sólo encontrar un divisor del número a evaluar distinto a uno y a sí
mismo, ya puedo afirmar que el número no es primo. ¿Tiene sentido seguir
evaluando más divisores?
b) Teniendo en cuenta que todo número par a excepción del 2, no es primo,
¿Tiene sentido seguir en un ciclo, si al calcular el resto de la división del número
a evaluar por 2, el resultado es cero?
c) Puedo encontrar un divisor del número a evaluar que sea mayor al número a
evaluar dividido 2?
*/

int ingreso_numero(){
    int ingreso;

    printf("Ingrese el numero y se le dara la suma de todos los valores entre 0 y el numero: ");
    scanf("%i", &ingreso);

    return ingreso;
}

bool num_primo(int num){
    bool primo = true;
    int cont=3;

    if(num == 2){
        primo = true;
    }
    else if(num%2==0){
        primo = false;
    }
    else{
        while(primo && cont<num){
            if(num % cont == 0){
                primo = false;
            } 
            cont += 2;
        }
    }

    return primo;
}

void resultado_primo(bool primo){
    if(primo){
        printf("El numero es primo\n");
    }
    else{
        printf("El numero no es primo\n");
    }
}


int main(){
    int num;
    bool es_primo;

    num = ingreso_numero();

    es_primo = num_primo(num);

    resultado_primo(es_primo);
    
    return 0;
}

