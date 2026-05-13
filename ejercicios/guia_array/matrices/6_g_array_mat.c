/*  Dadas dos matrices A y B, tales que A∈R^(m×n) y B∈R^(q×p), escribir un programa
que permita cargar sus dimensiones y sus datos. El programa debe
multiplicarlas (A.B) en caso de ser posible o devolver una señal si la operación
no puede realizarse. Para la estructura de datos considere un tamaño máximo
de 10 (m, n y p pueden tomar valores entre 1 y 10).
Aclaración: para multiplicar matrices, la primera matriz debe tener igual
columnas que filas tenga la segunda (n = q).
La matriz resultante será C∈R^(m×p) */

#include <stdio.h>
#define MAX 10
#define MIN 1
typedef int Tmat[MAX][MAX];

void elegirDimen(int *filas, int *columnas){
    int dimFila, dimColum;

    do{
        printf("Ingrese cuantas filas tendra su matriz: ");
        scanf("%i", &dimFila);
        if(dimFila >= MIN && dimFila <= MAX){
            *filas = dimFila;
        }
    }while(dimFila < MIN || dimFila > MAX);

    do{
        printf("Ingrese cuantas columnas tendra su matriz: ");
        scanf("%i", &dimColum);
        if(dimColum >= MIN && dimColum <= MAX){
            *columnas = dimColum;
        }
    }while(dimColum < MIN || dimColum > MAX);
}


void cargarMatriz(int fila, int colum, Tmat matr){
    int i, j;

    printf("Ingrese los valores de su Matriz:\n");
    for(i=0;i<fila;i++){
        for(j=0;j<colum;j++){
            printf("Ingrese el numero para la posicion %i,%i: ", i, j);
            scanf("%i", &matr[i][j]);
        }
    }
}

void multiplicarMatrices(Tmat matA, Tmat matB, int filas, int inter, int colum, Tmat matMult){
    int i, j, k;

    for(i=0; i<filas;i++){
        for(j=0; j<colum; j++){
            matMult[i][j] = 0;
            for(k=0; k<inter; k++){
                matMult[i][j] = matMult[i][j] + (matA[i][k] * matB[k][j]);
            }
        }
    }
}

void mostrarMatrices(Tmat matr, int filas, int colum){
    int i, j;

    printf("Su matriz es:\n");
    for(i=0; i<filas;i++){
        for(j=0; j<colum; j++){
            printf("%i ", matr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main(){
    Tmat mat1, mat2, mat_mult;
    int m, n, q, p;

    elegirDimen(&m, &n);
    elegirDimen(&q, &p);


    if(n == q){
        cargarMatriz(m, n, mat1);
        cargarMatriz(q, p, mat2);

        multiplicarMatrices(mat1, mat2, m, n, p, mat_mult);
        mostrarMatrices(mat1, m, n);
        mostrarMatrices(mat2, q, p);
        mostrarMatrices(mat_mult, m, p);
    }
    else{
        printf("No se pudo multiplicar las matrices por diferencia de tamaño");
    }
}