//Ingresar una serie de de numeros positivos (validar que sean positivos) en un vector. 
//Invertir el vector y mostrar la serie invertida.
//No se pueden usar vectores auxiliares
//Mostrar vector invertido

#include <stdio.h>

#define MAX 200

typedef int tvec[MAX];

void ingreso_valores(tvec vec, int *cont){
    int ingreso;
    *cont = 0;

    do{
        printf("Ingrese valores. Si quiere dejar de ingresar ponga -1: ");
        scanf("%i", &ingreso);

        if(ingreso >= 0){
            vec[*cont] = ingreso;
            *cont = *cont + 1;
        }
        else if(ingreso != -1){
            printf("\nEl valor ingresado no es valido\n");
        }
    }while(ingreso != -1);
}

void invertir_vector(tvec vec, int cont){
    int aux;
    int i;

    for(i=0; i < cont/2 ;i++){
        aux = vec[i];
        vec[i] = vec[cont - 1 - i];
        vec[cont -1 - i] = aux;
    }
}

void mostrar_vector(tvec vec, int cont){
    int i;

    for(i=0; i < cont ; i++){
        printf("El numero %i esta en la posicion %i\n", vec[i], i);
    }
}

int main(){
    tvec vector;
    int contador = 0;

    ingreso_valores(vector, &contador);

    invertir_vector(vector, contador);

    mostrar_vector(vector, contador);

    return 0;
}