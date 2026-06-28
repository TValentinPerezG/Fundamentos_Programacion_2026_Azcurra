//Mostrar X primeros numeros naturales

#include <stdio.h>

void mostrar_x_num_recursiva(int num){
    if(num>0){
        printf("%i\n", num);
        mostrar_x_num_recursiva(num - 1);//recursividad
    }
    //caso base es implicito
}

int main(){
    int num=8;

    mostrar_x_num_recursiva(num);

    return 0;
}