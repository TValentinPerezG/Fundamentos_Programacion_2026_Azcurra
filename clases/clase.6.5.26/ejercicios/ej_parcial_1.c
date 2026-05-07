/* ENUNCIADO EJERCICIO: Matriz Numeros Existentes

Implementar la función ejercicio_3 que reciba una matriz cargada con números enteros entre 0 y 100, y el máximo lógico de filas y el de columnas de ésta.
La función debe mostrar por pantalla los numeros que se encuentran presentes en la matriz y la cantidad de apariciones de cada uno de ellos.

Considerar que solo se puede recorrer una vez la matriz. Está permitida la utilización de un vector auxiliar.

Por ejemplo:
se tiene la siguiente matriz de 3x3
{
  {56, 89, 56},
  {78, 23, 11},
  {75, 56, 11}
}

El resultado debe ser:
11 -> 2
23 -> 1
56 -> 3
75 -> 1
78 -> 1
89 -> 1
*/
#include <stdio.h>

#define FILA 300
#define COLUMNA 300

void ejercicio_3(int matriz[FILA][COLUMNA], int mlfila, int mlcolumna){
    int vec_aux_cont[101];
    int i;
    int j;

    for(i = 0;i<101;i++){
        vec_aux_cont[i] = 0;
    }
    
    for(i = 0;i<mlfila;i++){
        for(j=0;j<mlcolumna;i++){
            vec_aux_cont[matriz[i][j]] = vec_aux_cont[matriz[i][j]] + 1;
        }
    }

    for(i = 0;i<101;i++){
        if(vec_aux_cont[i] != 0 || i == 0){
            printf("El numero %i aparece %i veces en la matriz", i, vec_aux_cont[i]);
        }
    }
}
