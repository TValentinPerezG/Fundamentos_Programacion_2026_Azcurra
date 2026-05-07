#include <stdio.h>
#include <stdlib.h>

/*  Escribir una función que dado un tiempo expresado en segundos, devuelva
por parámetros el equivalente en días, horas, minutos y segundos.
Utilizar esta función dentro de un programa que solicite el valor al usuario.
Se debe validar que el valor ingresado sea entero positivo, de lo contrario,
deberá mostrarse el mensaje: “Valor ingresado inválido”.
*/

#define SEGUNDOS_POR_DIA 86400
#define SEGUNDOS_POR_HORA 3600
#define SEGUNDOS_POR_MINUTO 60

void dias_hrs_mins_seg (int total_seg, int *dia, int *hrs, int *mins, int *seg){
    

    *dia = total_seg / SEGUNDOS_POR_DIA;
    total_seg = total_seg % SEGUNDOS_POR_DIA;
    *hrs = total_seg / SEGUNDOS_POR_HORA;
    total_seg = total_seg % SEGUNDOS_POR_HORA;
    *mins = total_seg / SEGUNDOS_POR_MINUTO;
    *seg = total_seg % SEGUNDOS_POR_MINUTO;

}

void resultado_final(int dias, int hrs, int mins, int segs){
    printf("Dias: %i\n", dias);
    printf("Horas: %i\n", hrs);
    printf("Minutos: %i\n", mins);
    printf("Segundos: %i\n", segs);
}

int main(){
    int  segundos, dias, horas, minutos;
    long long total_segundos;

    printf("Ingrese la cantidad de segundos: ");
    scanf("%i", &total_segundos);

    if(total_segundos <= 0){
        printf("Valor ingresado invalido\n");
    }
    else{
    dias_hrs_mins_seg(total_segundos, &dias, &horas, &minutos, &segundos);

    resultado_final(dias, horas, minutos, segundos);
    }

    return 0;
}
