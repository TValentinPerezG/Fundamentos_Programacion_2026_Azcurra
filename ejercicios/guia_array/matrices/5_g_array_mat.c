/* Dadas dos matrices A y B cuadradas de igual dimensión, tales que A∈R^(n×n) y B∈R^(n×n), 
escribir un programa que permita cargar su dimensión y sus datos. El
programa debe sumarlas y mostrar la matriz resultante. Para la estructura de
datos considere un tamaño máximo de 10 (1 <= n <= 10). */

#include <stdio.h>
#define MAX 10
#define MIN 1
typedef int Tmat[MAX][MAX];

int elegirDimen(){
    int dim;

    do{
        printf("Ingrese que dimension tendra su matriz: ");
        scanf("%i", &dim);
    }while(dim < MIN || dim > MAX);

    return dim;
}

void cargarMatriz(int dim, Tmat matr){
    int fila, colum;

    for(fila=0;fila<dim;fila++){
        for(colum=0;colum<dim;colum++){
            printf("Ingrese el numero para la posicion %i,%i: ", fila, colum);
            scanf("%i", &matr[fila][colum]);
        }
    }
}

void calcularMatrizSum(int dim, Tmat mat1, Tmat mat2, Tmat matsum){
    int fila, colum;

    for(fila=0;fila<dim;fila++){
        for(colum=0;colum<dim;colum++){
            matsum[fila][colum] = mat1[fila][colum] + mat2[fila][colum];
        }
    }
}

void mostrarMatriz(int dim, Tmat matr){
    int fila, colum;

    for(fila=0;fila<dim;fila++){
        for(colum=0;colum<dim;colum++){
            printf(" %i ", matr[fila][colum]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    Tmat a, b, suma;
    int dim;

    dim = elegirDimen();

    cargarMatriz(dim, a);

    cargarMatriz(dim, b);

    calcularMatrizSum(dim, a, b, suma);

    printf("Matriz A:\n");
    mostrarMatriz(dim, a);

    printf("Matriz B:\n");
    mostrarMatriz(dim, b);

    printf("Matriz Suma:\n");
    mostrarMatriz(dim, suma);

    return 0;
}