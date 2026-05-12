/* Dado un listado de valores numéricos i y x, donde i es un entero mayor que
0 y menor o igual 999, y x un número real, almacenar x en la posición i de un
vector. El listado no se ingresa ordenado por posición. Informar la cantidad de
números y el contenido del vector indicando la posición ocupada por cada
número a partir de la primera posición. Omitir las posiciones que no contengan
valor.
Considerar una estructura de datos de tamaño físico máximo de 1000
posiciones.*/

#include <stdio.h>

#define MAX 1000
typedef float Tvec[MAX];

void rellenarVector(Tvec vec){
    int i;

    for(i=0;i<MAX;i++){
        vec[i] = 0;
    }
}

void ingresoVector(Tvec vec, int *cont, int *mayor){
    int posicion;
    float ingreso;
    *mayor = -1;
    *cont = 0;

    do{
        printf("Ingrese el valor que quiere guardar: ");
        scanf("%f", &ingreso);
        if(ingreso != 0){
            do{
                printf("Ingrese en que posicion quiere ingresarlo: ");
                scanf("%i", &posicion);
                if(posicion < 0 || posicion >= 1000){
                    printf("No es una posicion valida. Ingresar denuevo\n");
                }
                else if(vec[posicion] != 0){
                    printf("esta posicion ya esta en uso.\n");
                }
                else{
                    vec[posicion] = ingreso;
                    *cont = *cont + 1;
                    if(posicion > *mayor){
                        *mayor = posicion;
                    }
                }
            }while(posicion < 0 || posicion >= 1000 || vec[posicion] != ingreso);
        }
    }while(ingreso != 0 && *cont < MAX);
}

void mostrarVector(Tvec vec, int cont, int mayor){
    int i;

    printf("Se ingresaron %i numeros.\n", cont);
    for(i=0;i<=mayor;i++){
        if(vec[i] != 0){
            printf("En la posicion %i esta el numero %.2f.\n", i, vec[i]);
        }
    }
}

int main(){
    Tvec vec;
    int cantidad, mayor;

    rellenarVector(vec);
    ingresoVector(vec, &cantidad, &mayor);
    mostrarVector(vec, cantidad, mayor);

    return 0;
}