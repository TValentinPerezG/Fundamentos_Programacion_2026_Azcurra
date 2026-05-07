/* Escribir una función en C que reciba como parámetro un numero entero y devuelva al modulo invocante los siguientes valores:
- el resultado de multiplicar sus digitos pares y
- la cantidad de digitos que cumplieron la condicion y fueron procesados. 

Por ejemplo: 

-> el número con el que se invoca la funcion es 25831 
-> los digitos pares son 2 y 8 
-> La funcion debe devolver los valores: 16 y 2. El 16 por el producto, y el 2 por la cantidad de dígitos.

Nota: para la resolucion de este ejercicio no se pueden utilizar arreglos. */

#include <stdio.h>

void producto_cantidad_pares(int num, int *produ_pares, int *cont_pares){
    int digito;

    *produ_pares = 1;
    *cont_pares = 0;

    while(num > 0){
        digito = num%10;

        if(digito%2 == 0){
            *produ_pares = *produ_pares * digito;
            *cont_pares = *cont_pares + 1;
        }

        num = num/10;
    }
}

/* esto seria todo lo necesario de la respuesta 
ya que pide la funcion que lo hace, no todo el programa */