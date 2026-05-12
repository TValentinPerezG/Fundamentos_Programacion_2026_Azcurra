/*  Dado un número n entero positivo y un listado de n números reales,
almacenar los números en un vector según el orden de entrada.
Informar el contenido del vector indicando la posición ocupada por cada
número a partir de la primera posición. (1 <= n <= 100)
*/
#include <stdio.h>

#define MAX 100
typedef float VecCont[MAX];

int ingresoEntero(){
    int ingresos;

    do{
        printf("Ingrese cuantos numeros ingresara, entre el 1 y el 100 inclusive: ");
        scanf("%i", &ingresos);
        if(ingresos < 1 || ingresos >100){
            printf("El numero no es valido. Intente denuevo\n");
        }
    }while(ingresos < 1 || ingresos > 100);

    return ingresos;
}

void ingresoVector(int ent, VecCont vec){
    int i;

    for(i=0;i<ent;i++){
        printf("Ingrese el valor para la celda %i: ", i);
        scanf("%f", &vec[i]);
    }
} 


void mostrarVector(int ent, VecCont vec){
    int i;

    for(i=0;i<ent;i++){
        printf("En la posicion %i esta el valor %f\n", i, vec[i]);
    }
}

int main(){
    VecCont vec;
    int entero;

    entero = ingresoEntero();
    ingresoVector(entero, vec);
    mostrarVector(entero, vec);

    return 0;
}