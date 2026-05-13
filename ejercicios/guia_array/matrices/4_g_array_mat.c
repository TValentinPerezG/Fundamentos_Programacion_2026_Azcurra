/* Escribir un programa modular que dada una matriz del tipo descrito a
continuación, muestre el menor número que aparece y cuantas veces aparece
dicho número en la matriz.
#define CANT_FILAS 3
#define CANT_COLS 3
typedef int matriz_t[CANT_FILAS][CANT_COLS]; */
#include <stdio.h>
#define CANT_FILAS 3
#define CANT_COLS 3
typedef int matriz_t[CANT_FILAS][CANT_COLS];

void cargarMatriz(matriz_t matr){
    int fila, colum;

    for(fila=0;fila<CANT_FILAS;fila++){
        for(colum=0;colum<CANT_COLS;colum++){
            printf("Ingrese el numero para la posicion %i,%i: ", fila, colum);
            scanf("%i", &matr[fila][colum]);
        }
    }
}

void buscarMenor(matriz_t matr, int *menor, int *cant_men){
    int fila, colum;

    *menor = matr[0][0];
    *cant_men = 0;

    for(fila=0;fila<CANT_FILAS;fila++){
        for(colum=0;colum<CANT_COLS;colum++){
            if(*menor == matr[fila][colum]){
                *cant_men = *cant_men + 1;
            }
            else if(*menor > matr[fila][colum]){
                *menor = matr[fila][colum];
                *cant_men = 1;
            }
        }
    }
}

void mostrarMatriz(matriz_t matr, int menor, int cant_men){
    int fila, colum;

    for(fila=0;fila<CANT_FILAS;fila++){
        for(colum=0;colum<CANT_COLS;colum++){
            printf(" %i ", matr[fila][colum]);
        }
        printf("\n");
    }
    printf("El numero mas bajo es %i y aparece %i vez/veces.", menor, cant_men);
}

int main(){
    matriz_t matr;
    int menor, cantidad_menor;

    cargarMatriz(matr);

    buscarMenor(matr, &menor, &cantidad_menor);

    mostrarMatriz(matr, menor, cantidad_menor);

    return 0;
}
