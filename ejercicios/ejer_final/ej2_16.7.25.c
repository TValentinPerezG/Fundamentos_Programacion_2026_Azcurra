/*
Escribir una funcion llamada crear_estructura_dinamica que reciba una cadena de caracteres nombre y un entero correspondiente a un legajo, la misma debe reservar memoria, 
para almacenar los dos valores en un registro t_alumno. La funcion debe devolver un puntero a una estructura dinamica t_alumno que contenga los elementos 
pasados por parametros y utilice solo el espacio de memoria necesario. Escribir un main que:
Invoque a la funcion utilizando como arreglo la siguiente declaracion: nombre = Pepe legajo = 111111
Haga una llamada a la funcion mostrar_estructura_dinamica a la que se le debe pasar la estructura y la correspondiente cantidad de elementos a mostrar. No tenes que desarrollar 
esta funcion, solo utilizarla adecuadamente. Solo se puede invocar esta funcion si el puntero no es nulo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int legajo;
    char nombre[50];
}t_alumno;

t_alumno *crear_estructura_dinamica(char nom[], int legaj){
    t_alumno *datos = malloc(sizeof(t_alumno));

    if(datos != NULL){
        strcpy(datos->nombre,nom);
        datos->legajo = legaj;
    }

    return datos;
}

int main(){
    int legajo=111111;
    char nombre[50] = 'Pepe';
    t_alumno *datos;

    datos = crear_estructura_dinamica(nombre, legajo);

    if(datos != NULL){
        mostrar_estructura_dinamica(datos, 1);
    }

    free(datos);

    return 0;
}