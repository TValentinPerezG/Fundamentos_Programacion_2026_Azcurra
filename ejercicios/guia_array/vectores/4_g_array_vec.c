/* Cargar una serie de números reales positivos en un vector. No se conoce la
cantidad exacta de datos, pero se sabe que no superan los 100. La serie finaliza
cuando se ingresa cero. Utilizar una función que invierta el contenido del vector.
Informar el contenido del vector indicando la posición ocupada por cada
número a partir de la primera posición
 */

#include <stdio.h>
#define MAX 100
typedef float Tvec[MAX];

void ingresoVector(Tvec vec, int *cont){
    float ingreso;
    *cont = 0;
    
    do{
        printf("Ingrese un numero positivo. Si quiere detener el ingreso ponga 0: ");
        scanf("%f", &ingreso);
        if(ingreso < 0){
            printf("El numero ingresado es invalido. Intente nuevamente\n");
        }
        else if(ingreso > 0){
            vec[*cont] = ingreso;
            *cont = *cont + 1;
        }
    }while(ingreso != 0 && *cont < MAX);
}

void invertirVector(int cont, Tvec vec){
    float aux;
    int i;

    for(i=0;i<cont/2;i++){
        aux = vec[cont - 1 - i];
        vec[cont - 1 - i] = vec[i];
        vec[i] = aux;
    }
}

void mostrarVector(int cont, Tvec vec){
    int i;

    for(i=0;i<cont;i++){
        printf("El numero %.2f esta en la posicion %i\n", vec[i], i);
    }
}

int main(){
    Tvec vec;
    int cantidad;

    ingresoVector(vec, &cantidad);

    invertirVector(cantidad, vec);

    mostrarVector(cantidad, vec);

    return 0;
}