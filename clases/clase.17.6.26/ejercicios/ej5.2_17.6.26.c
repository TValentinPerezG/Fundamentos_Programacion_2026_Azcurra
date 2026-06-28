//sumar todos los digitos de un numero
#include <stdio.h>

int suma_digitos_recursivo(int num){
    if(num < 10){
        return num;
    }
    else{
        return num%10 + suma_digitos_recursivo(num/10);
    }
}

int main(){
    int num=1198;
    int suma_dig;
    
    suma_dig=suma_digitos_recursivo(num);

    printf("\n%i\n", suma_dig);

    return 0;
}