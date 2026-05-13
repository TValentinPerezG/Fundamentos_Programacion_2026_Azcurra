/* Escribir una función en C, que reciba:
a) como primer parámetro un vector de números enteros;
b) como segundó parámetro, la cantidad de elementos en el vector;
c) como tercer parámetro deberá devolver la cantidad de valores negativos que
hay en el vector recibido;
d) como cuarto parámetro, la cantidad de elementos positivos que hay en el
vector recibido.
Escribir el programa que incluya a la función y las invocaciones con los
siguientes ejemplos, y la respectiva impresión de los valores devueltos:
Probar el programa con los siguiente casos:
v1 = [2,8,1,-5,4] -> Negativos: 1 Positivos: 4
v2 = [-2,-15,-3] -> Negativos: 3 Positivos: 0
v3 = [0,0,10,12,23,55,1] -> Negativos: 0 Positivos: 5 */

#include <stdio.h>
#define MF 1000
typedef int Tvec[MF];

void ingresoVector(Tvec vec, int *ml){
    int ingreso;
    *ml=0;

    do{
        printf("Ingrese un valor, si quiere detenerse ingrese 0: ");
        scanf("%i", &ingreso);
        if(ingreso != 0){
            vec[*ml] = ingreso;
            *ml = *ml + 1;
        }
    }while(ingreso != 0 && *ml < MF);
}

void encontrarSigno(Tvec vec, int ml, int *neg, int *pos){
    int i;
    *neg = 0;
    *pos = 0;

    for(i=0; i<ml; i++){
        if(vec[i]>0){
            *pos = *pos + 1;
        }
        else if(vec[i]<0){
            *neg = *neg + 1;
        }
    }
}

void mostrarVec(Tvec vec, int ml, int neg, int pos){
    int i;

    printf("En el vector [ ");
    for(i=0; i<ml;i++){
        printf("%i ",vec[i]);
    }
    printf("]\n hay %i Negativos y\n %i Positivos.\n", neg, pos);
}

int main(){
    Tvec vec1={2,8,1,-5,4}, vec2={-2,-15,-3}, vec3={0,0,10,12,23,55,1};
    int ml1, ml2, ml3, neg, pos;

    ml1=5;
    ml2=3;
    ml3=7;

    encontrarSigno(vec1, ml1, &neg, &pos);

    mostrarVec(vec1, ml1, neg, pos);

    encontrarSigno(vec2, ml2, &neg, &pos);

    mostrarVec(vec2, ml2, neg, pos);

    encontrarSigno(vec3, ml3, &neg, &pos);

    mostrarVec(vec3, ml3, neg, pos);

    return 0;
}