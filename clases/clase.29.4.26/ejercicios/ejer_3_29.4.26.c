#include <stdio.h>

#define FILAS 30
#define COLUMNAS 30
/* a- permitir al usuario ingresar los valores de la matriz
   b- calcular suma de diagonal principal
   c- calcular suma de diagonal secundaria
   d- declarar vector aux y guardar en el la suma de los elementos de cada fila */

void ingreso_matriz(int matriz[FILAS][COLUMNAS], int *dimension){

    printf("Ingrese la dimension de su matriz: ");
    scanf("%i", &*dimension);
    printf("%i", *dimension);

    for (int i = 0; i < *dimension; i++) {
        for (int j = 0; j < *dimension; j++) {
            printf("Ingrese el valor para la posicion [%i,%i] de la matriz: ", i, j);
            scanf("%i", &matriz[i][j]);
        }
    }
}

int calc_diagonal_prin(int matriz[FILAS][COLUMNAS], int dimension){
    int sum_diagonal = 0;
    
    for (int i = 0; i < dimension; i++) {
        // for (int j = 0; j < COLUMNAS; j++) {
        //     if(i == j){
        //         sum_diagonal += matriz[i][j];
        //     }
        // }
        sum_diagonal += matriz[i][i];
    }

    return sum_diagonal;
    // printf("El resultado de la suma de la diagonal principal es: %i\n", sum_diagonal);
}

int calc_diagonal_inver(int matriz[FILAS][COLUMNAS], int dimension){
    int sum_diagonal = 0;
    
    for (int i = 0; i < dimension; i++) {
        // for (int j = 0; j < COLUMNAS; j++) {
        //     if(i == j){
        //         sum_diagonal += matriz[i][j];
        //     }
        // }
        //en este caso, nos va a encontrar las filas donde coincida con i, porque filas es 3
        //si i es 0, [i][FILAS - 1 - i] queda [0][2] que es lo que buscamos
        sum_diagonal += matriz[i][dimension - 1 - i];
    }

    return sum_diagonal;
}

void vec_sum_filas(int matriz[FILAS][COLUMNAS], int vec[FILAS], int dimension){
    int i;

    printf("Si sumamos todas las filas de cada columna obtenemos: ");
    for (i = 0; i < dimension; i++) {
        vec[i] = 0;
        for (int j = 0; j < dimension; j++) {
            vec[i] += matriz[i][j];
        }
        printf("%d ", vec[i]);
    }
}

int main() {
    // Declaramos una matriz de enteros
    int matriz[FILAS][COLUMNAS];
    int vec_suma[FILAS];
    int dimension;
    //al definir una dimension lo volvimos un sistema con maximo logico y fisico
    //en la funcion se le da una dimension y esta misma es la cantidad que se usa
    ingreso_matriz(matriz, &dimension);

    printf("El resultado de la suma de la diagonal principal es: %i\n", calc_diagonal_prin(matriz, dimension));

    printf("El resultado de la suma de la diagonal inversa es: %i\n", calc_diagonal_inver(matriz, dimension));

    vec_sum_filas(matriz, vec_suma, dimension);

    // Imprimimos la matriz
    printf("\nMatriz:\n");
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }


    return 0;
}