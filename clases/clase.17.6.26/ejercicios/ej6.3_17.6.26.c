/*5- Una función recursiva en C que suma los elementos en las posiciones pares de un arreglo
 
6- Una función recursiva que Sume la diagonal principal de una matriz cuadrada*/

#include <stdio.h>
#define MAX 10
typedef int tvector[MAX];
typedef int tmatriz[MAX][MAX];

int sumar_pos_pares_vec(tvector vec, int ml, int posi){

    if(posi>=ml){
        return 0; //base
    }
    return vec[posi] + sumar_pos_pares_vec(vec, ml, posi+2); //recursivo
}

int sumar_pos_pares_vecV2(tvector vec, int ml){

    if(ml > 0){
        if((ml-1)%2 == 0){
            return vec[ml - 1] + sumar_pos_pares_vecV2(vec, ml-2);
        }
        else{
            return sumar_pos_pares_vecV2(vec, ml-1);
        }
    }
    else{
        return 0; //base
    }
     //recursivo
}

int sumar_diagonal_principal_mat(tmatriz mat, int ml, int posi){
        
    if(posi>=ml){
        return 0; //base
    }
    return mat[posi][posi] + sumar_diagonal_principal_mat(mat, ml, posi+1); //recursivo

}

int sumar_diagonal_principal_matV2(tmatriz mat, int ml){
        
    if(ml > 0){
        return mat[ml - 1][ml - 1] + sumar_diagonal_principal_matV2(mat, ml-1);
    }
    else{
        return 0; //base
    }

}

int main(){
    tvector vec = {1,2,3,4,5,6};
    tmatriz mat =  {{1,2,3},
                    {4,5,6},
                    {7,8,9}};
    int ml_matriz=3;
    int ml = 6;
    int suma_vec, suma_mat;

    suma_vec = sumar_pos_pares_vecV2(vec, ml);
    suma_mat = sumar_diagonal_principal_matV2(mat, ml_matriz);

    printf("\nSuma vector: %i\n", suma_vec);
    printf("\nSuma Matriz: %i\n", suma_mat);

    return 0;
}