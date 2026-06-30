/*
8) Desarrollar una función recursiva que compruebe si un número pasado como
parámetro es capicúa.
*/
#include <stdio.h>
#include <stdbool.h>

//ver como hacer en el caso de que no es vector,
//si es vector ya tengo el codigo

int main(){
    int num = 121;
    bool capicua = es_capicua(num);

    printf("%i", capicua);
    return 0;
}