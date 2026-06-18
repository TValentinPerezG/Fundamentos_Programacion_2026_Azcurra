#include <stdio.h>
#include <stdbool.h>
// Implemente una funcion que resuelva la division como restas sucesivas
int division_recursiva(int num, int div){
    if(num < div){
        return 0;
    }
    return 1 + division_recursiva(num - div, div);
}

int main(){
    int num = 15;
    int divisor = 2;
    int division_resu;

    division_resu= division_recursiva(num, divisor);

    printf("\nEl numero %i es divisible sin resto %i veces por %i\n", num, division_resu, divisor);

    return 0;
}