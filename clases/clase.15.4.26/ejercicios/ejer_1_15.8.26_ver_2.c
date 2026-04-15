# include <stdio.h>

/* Escribir una función que reciba un valor y calcule el factorial del mismo.
No debe imprimir el valor, debe solamente devolverlo.
Si no se puede calcular el factorial del valor recibido, la función deberá devolver 0, de lo contrario deberá devolver el valor calculado. 

Invocarla para los valores -8, 0, 1, 5; mostrando en cada caso lo que devuelve.

Definición: El factorial de un entero positivo n,  se define como el producto de todos los números enteros positivos desde 1 hasta n.  El factorial de 0 es 1.

Para la construcción del programa, podés utilizar el editor del intérprete o el ide que prefieras.
Luego copia y pega lo que hayas hecho en la caja de texto de esta actividad y efectuá la entrega de la misma. */

int factorial (int val1){
    int factorizacion=1, i;

    
    if(val1 >= 0){
        for(i=2;i<=val1;i++)
        {
            factorizacion = i * factorizacion;
        }
    }
    else{
        factorizacion = 0;
    }
    
    return factorizacion;
}

int main(){
    int num1, factorizado;
    
    printf("%d\n", factorizado = factorial(num1=-8));
    printf("%d\n", factorizado = factorial(num1=1));
    printf("%d\n", factorizado = factorial(num1=0));
    printf("%d\n", factorizado = factorial(num1=5));

    return 0;
}