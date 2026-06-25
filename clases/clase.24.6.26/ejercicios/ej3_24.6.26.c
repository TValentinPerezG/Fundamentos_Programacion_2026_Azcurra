/*  Implementar una función que retorna un puntero a un vector de n struct del
tipo t_alumno (ver anexo), el cual apunta a un bloque de memoria dinámica,
respetando la siguiente declaración. En caso de no poder reservar la memoria,
retornar NULL.
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

// t_alumno* crear_alumnos(int n){
//     t_alumno *alumnos = malloc(n*sizeof(t_alumno));
//     int i;

//     if(alumnos != NULL){
//         for(i=0;i<n;i++){
//             printf("Ingrese el padron del alumno: ");
//             scanf("%i", &alumnos->padron);
//             getchar();
//             printf("Ingrese el nombre del alumno: ");
//             fgets(alumnos->nombre, 30, stdin);
//             printf("Ingrese el apellido del alumno: ");
//             fgets(alumnos->apellido, 30, stdin);    
//             printf("\n");    
//         }
//     }
//     else{
//         printf("no");
//     }

//     return alumnos;
// }

t_alumno* crear_alumnos(int n){
    return malloc(n*sizeof(t_alumno));
}
// devuelve un puntero que tenga el espacio que se pidio.

int main(){
    t_alumno *alumnos;

    alumnos = crear_alumnos(2);

    //se puede hacer que el free sea funcional dependiendo de si 
    //fue NULL o no el puntero, pero no es necesario.
    free(alumnos);    
    

    return 0;
}
