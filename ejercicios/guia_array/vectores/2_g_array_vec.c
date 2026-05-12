/* Dado un listado de números reales del cual no se conoce la cantidad,
almacenar los números en un vector en el orden de entrada.
Informar la cantidad de números y el contenido del vector indicando la posición
ocupada por cada número a partir de la primera posición.
Considerar una estructura de datos de tamaño físico máximo de 1000
posiciones.*/

#include <stdio.h>

#define MAX 1000
typedef float VecEntrada[MAX];

void ingresoReales(VecEntrada vec, int *cont){
    float ingreso;
    *cont = 0;

    do{
        printf("Ingrese un numero, si quiere dejar de ingresar, ponga 0: ");
        scanf("%f", &ingreso);

        if(ingreso != 0){
            vec[*cont] = ingreso;
            *cont = *cont + 1;
        }

    }while(ingreso != 0 && *cont < MAX);
}

void mostrarVectorCant(VecEntrada vec, int cont){
    int i;

    printf("Se ingresaron %i numeros\n", cont);
    for(i=0;i<cont;i++){
        printf("El valor en la celda %i es %.2f\n", i, vec[i]);
    }
}

int main(){
    VecEntrada vec;
    int cantidad;

    ingresoReales(vec, &cantidad);
    mostrarVectorCant(vec, cantidad);

    return 0;
}