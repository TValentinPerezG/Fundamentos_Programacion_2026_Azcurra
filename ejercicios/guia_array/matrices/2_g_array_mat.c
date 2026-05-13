/* Dada una matriz cuadrada de 5x5 cargada por el usuario con números
enteros, escribir un programa modular que muestre:
a) Todos los elementos de la matriz.
b) La suma de todos los elementos de la matriz.
c) La suma de la diagonal principal.
d) La suma de la diagonal secundaria.
e) La suma de los elementos del triángulo superior.
f) La suma de los elementos del triángulo inferior.
g) Si es una matriz diagonal (todos los elementos por fuera de la diagonal
principal son igual a cero)
Cada módulo debe optimizar la cantidad de iteraciones a realizar. */
#include <stdio.h>
#include <stdbool.h>
#define FILAS 5
#define COLUMNAS 5
typedef int Tmat[FILAS][COLUMNAS];

void ingresarMatriz(Tmat matr){
    int iFilas, iColum;

    for(iFilas=0;iFilas<FILAS;iFilas++){
        for(iColum=0;iColum<COLUMNAS;iColum++){
            printf("Ingrese el numero para la posicion %i,%i: ", iFilas, iColum);
            scanf("%i", &matr[iFilas][iColum]);
        }
    }
}

void mostrarMatrizCompleta(Tmat matr){
    int iFilas, iColum;

    for(iFilas=0;iFilas<FILAS;iFilas++){
        for(iColum=0;iColum<COLUMNAS;iColum++){
            printf(" %i ", matr[iFilas][iColum]);
        }
        printf("\n");
    }
}

int sumarMatriz(Tmat matr){
    int iFilas, iColum;
    int sumaMat=0;

    for(iFilas=0;iFilas<FILAS;iFilas++){
        for(iColum=0;iColum<COLUMNAS;iColum++){
            sumaMat = sumaMat + matr[iFilas][iColum];
        }
    }

    return sumaMat;
}

int sumaDiagonalPrin(Tmat matr){
    int i;
    int sumaDiaPrin = 0;

    for(i=0;i<FILAS;i++){
        sumaDiaPrin= sumaDiaPrin + matr[i][i];
    }

    return sumaDiaPrin;
}

int sumaDiagonalInver(Tmat matr){
    int i;
    int sumaDiaInve = 0;

    for(i=0;i<FILAS;i++){
        sumaDiaInve = sumaDiaInve + matr[i][COLUMNAS -1 - i];
    }

    return sumaDiaInve;
}

int sumaTrianguloSup(Tmat matr){
    int iFila, iColum;
    int sumaTriSup = 0;

    for(iFila=0;iFila<FILAS-1;iFila++){
        iColum=COLUMNAS - 1;
        while(iColum>iFila){
            sumaTriSup = sumaTriSup + matr[iFila][iColum];
            iColum--;
        }
    }

    return sumaTriSup;
}

int sumaTrianguloInf(Tmat matr){
    int iFila, iColum;
    int sumaTriInf = 0;

    for(iFila=1;iFila<FILAS;iFila++){
        iColum=0;
        while(iColum<iFila){
            sumaTriInf = sumaTriInf + matr[iFila][iColum];
            iColum++;
        }
    }

    return sumaTriInf;
}

bool esMatrizDiagonal(Tmat matr){
    bool matrDiag= true;
    int iFila = 0, iColum = 0;

    while(matrDiag && iFila < FILAS){
        iColum=0;
        while(matrDiag && iColum < COLUMNAS){
            if(iFila != iColum){
                if(matr[iFila][iColum] != 0){
                    matrDiag = false;
                }
            }
            iColum++;
        }
        iFila++;
    }

    return matrDiag;
}