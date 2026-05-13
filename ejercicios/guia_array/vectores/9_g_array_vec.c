/* Dados 2 vectores a y b de longitudes n y m, el primero ordenado ascendente
y el segundo ordenado descendente, crear un nuevo vector c de longitud n + m
elementos intercalando los elementos de a y b de modo que c quede ordenado
ascendente.
*/

#include <stdio.h>
#define MF 10000
typedef int Tvec[MF];
typedef int Cvec[MF*2];

void ingresoVeca(Tvec a, int *n){

}

void ingresoVecb(Tvec b, int *m){

}

void ingresoVecC(Tvec a, Tvec b, int n, int m, Cvec c){
    int i= 0, j=m-1, k, largo;

    largo = n + m;

    for(k=0;k<largo;k++){
        if(i==n){
            c[k] = b[j];
            j--;
        }
        else if(j<0){
            c[k] = a[i];
            i++;
        }
        else{
            if(a[i] > b[j]){
                c[k] = b[j];
                j--;
            }
            else{
                c[k] = a[i];
                i++;
            }
        }  
    }
}

int main(){
    Tvec a, b;
    Cvec c;
    int n, m;

    ingresoVeca(a, &n);
    ingresoVecb(b, &m);
    ingresoVecC(a, b, n, m, c);


    return 0;
}