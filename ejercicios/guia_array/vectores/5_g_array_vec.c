/* Cargar una serie de números reales positivos en un vector. No se conoce la
cantidad exacta de datos, pero se sabe que no superan los 100. La serie finaliza
cuando se ingresa cero. Informar el valor máximo, la cantidad de veces que
aparece y la/s posición/es que ocupa.
*/
#include <stdio.h>
#define MAX 100
typedef float Tvec[MAX];
typedef int Ivec[MAX];

void ingresoVector(Tvec vec, int *ml){
    float ingreso;
    *ml = 0;
    
    do{
        printf("Ingrese un numero positivo. Si quiere detener el ingreso ponga 0: ");
        scanf("%f", &ingreso);
        if(ingreso < 0){
            printf("El numero ingresado es invalido. Intente nuevamente\n");
        }
        else if(ingreso > 0){
            vec[*ml] = ingreso;
            *ml = *ml + 1;
        }
    }while(ingreso != 0 && *ml < MAX);
}

void encontrarMaximo(Tvec vec, int ml, float *max, int *cantidad, Ivec posiciones){
    int i;
    *max=0;
    *cantidad=0;

    for(i=0;i<ml;i++){
        if(*max < vec[i]){
            posiciones[0]=i;
            *max = vec[i];
            *cantidad = 1;
        }
        else if(*max == vec[i]){
            posiciones[*cantidad]=i;
            *cantidad = *cantidad + 1;
        }
    }
}

void mostrarMax(Tvec vec, int ml, float max, int cantidad, Ivec posi){
    int i;

    printf("En el vector [ ");
    for(i=0;i<ml;i++){
        printf("%.2f ", vec[i]);
    }
    printf("] \nEl maximo valor es %.2f\n Que aperece %i vez/veces\n en las posiciones [ ", max, cantidad);
    for(i=0;i<cantidad;i++){
        printf("%i ", posi[i]);
    }
    printf("]\n");
}

int main(){
    Tvec vec;
    Ivec posi;
    int ml, cant_max;
    float max;

    ingresoVector(vec, &ml);

    encontrarMaximo(vec, ml, &max, &cant_max, posi);

    mostrarMax(vec, ml, max, cant_max, posi);

    return 0;
}