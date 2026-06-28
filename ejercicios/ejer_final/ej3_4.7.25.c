/* 
Desarrollar una función recursiva en lenguaje C que reciba un número entero como parámetro y devuelva la sumatoria de los números naturales desde 1 hasta ese número.

Si el número recibido es menor o igual a 0, la función debe devolver 0. Ejemplo
sumatoria(6) → 1 + 2 + 3 + 4 + 5 + 6 = 21 
*/

#include <stdio.h>
#include <stdbool.h>

int sumataria_recursiva(int num){

    if(num == 0){
        return 0;
    }
    else if(num == 1){
        return 1;
    }

    return num + sumataria_recursiva(num - 1);
}

//solo lo de arriba era necesario para la respuesta, esto es para revisar el funcionamiento
int main(){
    int num = 10;
    int suma = sumataria_recursiva(num);

    printf("\n%i\n", suma);

    return 0;
}
