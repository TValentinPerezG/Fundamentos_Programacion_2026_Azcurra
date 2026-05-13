/* Dada una matriz de 3x4, escribir un programa que permita cargar sus datos y
luego mostrarlos */

#include <stdio.h>
#define FILAS 3
#define COLUMNAS 4
typedef int Vmatriz[FILAS][COLUMNAS];

void cargarMatriz(Vmatriz matr){
    int iFilas, iColum;

    for(iFilas=0;iFilas<FILAS;iFilas++){
        for(iColum=0;iColum<COLUMNAS;iColum++){
            printf("Ingrese el numero para la posicion %i,%i: ", iFilas, iColum);
            scanf("%i", &matr[iFilas][iColum]);
        }
    }
}

void mostrarMatriz(Vmatriz matr){
    int iFilas, iColum;

    for(iFilas=0;iFilas<FILAS;iFilas++){
        for(iColum=0;iColum<COLUMNAS;iColum++){
            printf(" %i ", matr[iFilas][iColum]);
        }
        printf("\n");
    }
}

int main(){
    Vmatriz matr;

    cargarMatriz(matr);

    mostrarMatriz(matr);

    return 0;
}