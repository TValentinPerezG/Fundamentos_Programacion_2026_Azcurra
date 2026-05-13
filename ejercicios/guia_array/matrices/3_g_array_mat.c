/* Escribir un programa que dada una matriz de números reales, de n x m,
devuelva un vector que en cada posición i almacene el elemento mínimo de
cada fila i de la matriz. */
#include <stdio.h>
#define FILAS 1000
#define COLUMNAS 1000
typedef float Tmat[FILAS][COLUMNAS];
typedef float Tvec[FILAS];

void vectorPorFila(Tmat matr, int n, int m, Tvec vec){
    int iFilas, iColum;


    for(iFilas=0;iFilas<n;iFilas++){
        vec[iFilas] = matr[iFilas][0];
        for(iColum=1;iColum<m;iColum++){
            if(vec[iFilas] > matr[iFilas][iColum]){
                vec[iFilas] = matr[iFilas][iColum];
            }
        }
    }
}