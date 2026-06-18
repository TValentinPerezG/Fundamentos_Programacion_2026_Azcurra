#include <stdio.h>
#include <stdbool.h>

#define MAX 30

typedef int tvector[MAX];

bool es_capicua(tvector vec, int ml){
    int i=0;
    bool capicua = true;

    while((capicua) && (i<ml/2)){
        if(vec[i] != vec[ml - 1 - i]){
            capicua = false;
        }
        i++;
    }

    return capicua;
}

int main(){
    int ml=5;
    tvector vec = {2, 3, 4, 3, 2};
    bool capicua;

    //aqui iria el ingreso del vector

    capicua = es_capicua(vec, ml);

    if(capicua){
        printf("\nEs capicua\n");
    }
    else{
        printf("\nNo es capicua\n");
    }

    return 0;
}