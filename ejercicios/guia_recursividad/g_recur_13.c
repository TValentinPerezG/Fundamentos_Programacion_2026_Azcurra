/*
13) Desarrollar una función recursiva que compruebe si un número es binario.
Un número binario está formado únicamente por ceros y unos.
*/
#include <stdio.h>
#include <stdbool.h>
bool es_binario(int num){
    if(num == 1 || num == 0){
        return true;
    }
    else if(num%10 == 0 || num%10 == 1){
        return es_binario(num/10);
    }
    else{
        return false;
    }
}

int main(){
    int num = 1010;
    bool receptor = es_binario(num);

    if(receptor){
        printf("\nes binario\n");
    }
    else{
        printf("aiaiai");
    }
    return 0;
}