#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*  Escribir una función que dado un número entero positivo retorne un valor
booleano que indique si el mismo es capicúa (palindromo). */

bool calc_capicua(int valor){
    int invert, aux;
    bool resu_capi;

    aux = valor;

    invert = aux%10;

    while(aux>9){
        aux = aux/10;
        invert = (invert * 10) + aux%10;
    }
	
    // if(valor == invert){
    //    resu_capi = true;
    // }
    // else{
    //     resu_capi = false;
    // }

    // return resu_capi;
    return valor == invert;
}

int main(){
    int num;

    printf("Ingrese un numero para ver si es capicua: ");
    scanf("%d", &num);

    if (calc_capicua(num)){
        printf("El numero es capicua");
    }
    else
        printf("El numero no es capicua");
    
    return 0;
}
