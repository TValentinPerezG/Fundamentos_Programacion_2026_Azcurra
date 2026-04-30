//Ingresar una serie de números, entre 0 y 999,  finalizada con un numero 
//negativo y mostrar la cantidad de veces que aparece cada número en la serie

#include <stdio.h>

#define MAX 1000
typedef int t_vec_cont[MAX];

void inicializarVec(t_vec_cont vecCont){
    int i = 0;

    for(i;i<MAX;i++){
        vecCont[i] = 0;
    }
}

void cargar(t_vec_cont vecCont){
    int ing;

    printf("Ingrese un numero: ");
    scanf("%i", &ing);

    while(ing >= 0){
        vecCont[ing] = vecCont[ing] + 1;
        printf("Ingrese un numero: ");
        scanf("%i", &ing);
    }   
}

void mostrarVec(t_vec_cont vecCont){
    int i = 0;

    for(i;i<MAX;i++){
        if(vecCont[i] != 0){
            printf("El numero %i se ingreso %i veces\n", i, vecCont[i]);
        }
    }
}

void main(){
    t_vec_cont vecCont;
    
    inicializarVec(vecCont);

    cargar(vecCont);

    mostrarVec(vecCont);

    return;
}