/* Escribir un programa el cual reserve memoria dinámica para almacenar un
struct del tipo t_alumno (ver anexo). Luego solicitar al usuario que ingrese los
datos del alumno y almacenarlos en la memoria previamente reservada.
Mostrar luego todos los datos del alumno. Liberar la memoria reservada al
finalizar el programa.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int padron;
    char nombre[30];
    char apellido[30];
} t_alumno;

// void ingresar_alumno(t_alumno *alum){
//     t_alumno aux;
//     printf("Ingrese el padron del alumno: ");
//     scanf("%i", &aux.padron);
//     getchar();
//     printf("Ingrese el nombre del alumno: ");
//     fgets(aux.nombre, 30, stdin);
//     printf("Ingrese el apellido del alumno: ");
//     fgets(aux.apellido, 30, stdin);

//     *alum = aux;
// }

void ingresar_alumno(t_alumno *alum){

    if(alum != NULL){
        printf("Ingrese el padron del alumno: ");
        scanf("%i", &alum->padron);
        getchar();
        printf("Ingrese el nombre del alumno: ");
        fgets(alum->nombre, 30, stdin);
        printf("Ingrese el apellido del alumno: ");
        fgets(alum->apellido, 30, stdin);
    }
    else{
        printf("No hay memoria suficiente.\n");
    }
}

void mostrar_alumno(t_alumno *alumno){

    if(alumno != NULL){
        printf("\nPadron: %i \nNombre: %sApellido: %s", alumno->padron, alumno->nombre, alumno->apellido);
    }
    else{
        printf("No hay datos disponibles para mostrar");
    }
}

int main(){
    t_alumno *alumno = malloc(sizeof(t_alumno));

    ingresar_alumno(alumno);

    mostrar_alumno(alumno);

    free(alumno);
    //se puede hacer que el free sea funcional dependiendo de si 
    //fue NULL o no el puntero, pero no es necesario.
    
    return 0;
}
