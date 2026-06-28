#include <stdio.h>
#include <stdbool.h>

#define MAX 30
typedef int tvector[MAX];

bool es_capicua(tvector vec, int ml, int posi){

    if(ml <= posi){ // caso base correcto
        return true;
    }
    else if(vec[ml - 1] != vec[posi]){ // caso base error
        return false;
    }

    return es_capicua(vec, ml-1, posi+1); // caso recursivo
}

int main(){
    int ml=6;
    tvector vec = {2, 4, 5, 5, 4, 2};
    int posi=0;
    bool capicua;

    //aqui iria el ingreso del vector

    capicua = es_capicua(vec, ml, posi);

    if(capicua){
        printf("\nEs capicua\n");
    }
    else{
        printf("\nNo es capicua\n");
    }

    return 0;
}