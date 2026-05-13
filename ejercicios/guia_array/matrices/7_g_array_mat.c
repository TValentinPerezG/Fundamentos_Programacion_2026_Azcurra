/* Se tiene una colección de datos de la temperatura por hora (0 a 23) por día (1
a 31) del mes de marzo.
Se pide:
a) Cargar el listado en una matriz e informarla en forma bidimensional.
b) Informar además la máxima y la mínima temperatura por día, la máxima y la
mínima del mes. */

#include <stdio.h>
#define DIAS 31
#define HORAS 24
typedef float Tmat[HORAS][DIAS];
typedef float Tvec[DIAS];

void cargarDatos(Tmat matr) {
    int i, j;

    for (i = 0; i < DIAS; i++) {
        printf("Ingrese las temperaturas para el dia: %d\n", i);
        for (j = 0; j < HORAS; j++) {
            printf("Hora: %d", j);
            scanf("%f", &matr[j][i]);
        }
    } 
}


void tempMaxMinDia(Tmat matr, Tvec maxD, Tvec minD){
    int fila, colum;

    for (colum = 0; colum < DIAS; colum++) {
        maxD[colum] = matr[0][colum];
        minD[colum] = matr[0][colum];
        for (fila = 1; fila < HORAS; fila++) {
            if(maxD[colum] < matr[fila][colum]){
                maxD[colum] = matr[fila][colum];
            }
            else if(minD[colum] > matr[fila][colum]){
                minD[colum] = matr[fila][colum];
            }
        }
    }
}

void tempMaxMinMes(Tmat matr, float *maxM, float *minM) {
    int fila, colum;

    *maxM = matr[0][0];
    *minM = matr[0][0];

    for (fila = 0; fila < HORAS; fila++) {
        for (colum = 0; colum < DIAS; colum++) {
            if(*maxM < matr[fila][colum]){
                *maxM = matr[fila][colum];
            }
            else if(*minM > matr[fila][colum]){
                *minM = matr[fila][colum];
            }
        }
    }

}

void mostrarDatos(Tmat matr, Tvec maxD, Tvec minD, float maxM, float minM) {
    int i, j;

    for (i = 0; i < HORAS; i++) {
        for (j = 0; j < DIAS; j++) {
            printf("%.2f ", matr[i][j]);
        }
        printf("\n");
    }

    printf("La temperatura maxima en el mes fue: %.2f\n", maxM);
    printf("La temperatura minima en el mes fue: %.2f\n", minM);

    printf("Maximos: [ ");
    for(i = 0; i < DIAS; i++){
        printf("%.2f ", maxD[i]);
    }
    printf("]\nMinimos: [ ");
    for(i = 0; i < DIAS; i++){
        printf("%.2f ", minD[i]);
    }
    printf("]\n");
}

int main() {
    Tmat datos_hora;
    Tvec max_dia, min_dia;
    float max_mes, min_mes;

    cargarDatos(datos_hora);

    tempMaxMinDia(datos_hora, max_dia, min_dia);
    tempMaxMinMes(datos_hora, &max_mes, &min_mes);
    
    mostrarDatos(datos_hora, max_dia, min_dia, max_mes, min_mes);

    return 0;
}