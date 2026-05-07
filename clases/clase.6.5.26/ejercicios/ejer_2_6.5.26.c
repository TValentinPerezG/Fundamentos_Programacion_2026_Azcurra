/* Escribir un programa modular que solicite el ingreso de dos palabras y luego muestre las mismas según la longitud de cada una de ellas, mostrando primero la de menor longitud.
A igualdad de longitud, mostrar primero la menor de las dos, en términos de orden alfabético.
Las palabras tienen una longitud máxima de 15 caracteres. */

#include <stdio.h>
#include <string.h>

#define MAX 15

typedef char palab[MAX];

void ingreso_palabras(palab palabra1, palab palabra2){
    
    printf("ingrese la primer palabra (max 15 caracteres): ");
    fgets(palabra1, MAX, stdin);

    fflush(stdin);

    printf("ingrese la segunda palabra (max 15 caracteres): ");
    fgets(palabra2, MAX, stdin);

    fflush(stdin);

}

void primero_palabra2(palab palabra1, palab palabra2)
{
    printf("%s", palabra2);
    printf("%s", palabra1);
}

void primero_palabra1(palab palabra1, palab palabra2)
{
    printf("%s", palabra1);
    printf("%s", palabra2);
}

void mostrar_ordenado(palab palabra1, palab palabra2){
    int largo1 = strlen(palabra1);
    int largo2 = strlen(palabra2);

    if(largo1 > largo2){
        primero_palabra2(palabra1, palabra2);
    }
    else if(largo2 > largo1){
        primero_palabra1(palabra1, palabra2);
    }
    else{
        if(strcmp(palabra1, palabra2) > 0){
            primero_palabra2(palabra1, palabra2);
        }
        else if(strcmp(palabra1, palabra2) < 0){
            primero_palabra1(palabra1, palabra2);            
        }
        else{
            primero_palabra2(palabra1, palabra2);
            printf("son la misma palabra\n");
        }
    }
}

int main(){
    palab palabra1, palabra2;

    ingreso_palabras(palabra1, palabra2);

    mostrar_ordenado(palabra1, palabra2);

    return 0;
}