/* Escribir un programa en C, que:
- declare una cadena para almacenar como máximo 40 caracteres y como valor inicial le asigne tu nombre y apellido
- recorra la cadena e imprima sólo las consonantes, una debajo de la otra
- indique cuantas consonantes hay en tu nombre y apellido
 */

#include <stdio.h>

#define MAX 41

void imprimir_cadena(char nom_ap[MAX], int *cont_conso){
    int i = 0;

    while(nom_ap[i] != '\0'){
        if (nom_ap[i] >= 'A' && nom_ap[i] <= 'Z'){
            if(nom_ap[i] != 'a' && nom_ap[i] != 'A' &&
            nom_ap[i] != 'e' && nom_ap[i] != 'I' &&
            nom_ap[i] != 'i' && nom_ap[i] != 'E' &&
            nom_ap[i] != 'o' && nom_ap[i] != 'O' &&
            nom_ap[i] != 'u' && nom_ap[i] != 'U' ){
                printf("%c\n", nom_ap[i]);
                *cont_conso = *cont_conso + 1;
            }
        }
        i++;
    }
}

int main(){
    char cadena[MAX] = "Tobias Valentin Perez Gomez";
    int cont_conso = 0;

    imprimir_cadena(cadena, &cont_conso);

    printf("El total de consonantes es: %i", cont_conso);

    return 0;
}