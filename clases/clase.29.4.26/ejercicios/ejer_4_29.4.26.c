#include <stdio.h>
#define MAX 50
#define APROBO 4
typedef int Tvec[MAX];

void CargarNotas(Tvec vec, int *cont){
    int Nota;
    *cont=0;

    printf("Ingresar nota -1 para finalizar: ");
    scanf("%d", &Nota);

    while ((Nota != -1) && (*cont < MAX)){
        vec[*cont]=Nota;
        printf("Ingresar nota -1 para finalizar: ");
        scanf("%d", &Nota);
        *cont = *cont + 1;
    }
}

void MostrarArpobados(Tvec vec, int cont){
    int i;

    for(i=0;i<=cont;i++){
        if(vec[i] >= APROBO){
            printf("El alumno num %i con la nota %i aprobo.\n", i + 1, vec[i]);
        }
        printf("%i\n", i);
        printf("%i\n", cont);
    }
}

void main(){
    Tvec vec;
    int ML;
    int Nota;

    CargarNotas(vec, &ML);

    MostrarArpobados(vec, ML);

    return;
}