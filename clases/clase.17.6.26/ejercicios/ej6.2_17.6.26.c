/*Mostrar de a 1 los digitos impares de un numero*/

#include <stdio.h>

void mostrar_digitos_impares(int X){
    
    if(X>0){
        mostrar_digitos_impares(X/10);
        if((X%10)%2!=0){
            printf("\n%i\n", X%10);
        }
    }

}

int main(){
    int num=9721;

    mostrar_digitos_impares(num);

    return 0;
}