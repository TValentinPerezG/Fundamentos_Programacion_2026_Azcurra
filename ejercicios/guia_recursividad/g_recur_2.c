/* 
Desarrollar un programa que calcule y muestre por pantalla los primeros N
términos de la sucesión de Fibonacci en forma recursiva. 
*/
#include <stdio.h>
#include <stdbool.h>


int fibonnaci_recursiva(int num){
    if(num<=1){
        return num;
    }
    return fibonnaci_recursiva(num-1) + fibonnaci_recursiva(num-2);
}


int main(){
    int num = 5;
    int i;

    for(i=0;i<num;i++){
        printf("%i\n", fibonnaci_recursiva(i));
    }
    return 0;
}