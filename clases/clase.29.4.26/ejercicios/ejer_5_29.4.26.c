/* Mostrar el promedio de notas del curso
Mostrar todas las notas superiores al promedio calculado */

#include <stdio.h>
#define MAX 50
#define APROBO 4
typedef int Tvec[MAX];

void CargarNotas(Tvec vec, int *cont, int *acum){
    int Nota;
    *cont=0;

    printf("Ingresar nota -1 para finalizar: ");
    scanf("%d", &Nota);

    while ((Nota != -1) && (*cont < MAX)){
        vec[*cont]=Nota;
        *acum = *acum + Nota;
        *cont = *cont + 1;
        printf("Ingresar nota -1 para finalizar: ");
        scanf("%d", &Nota);
    }
}

double PromedioNotas(int cont, int acum){
    return (double)acum/cont;
}

void MostrarMayorProm(Tvec vec, int cont, int prom){
    int i;

    for(i=0;i<=cont;i++){
        if(vec[i] > prom){
            printf("El alumno num %i con la nota %i tiene una nota mayor al promedio.\n", i + 1, vec[i]);
        }
    }
}

void main(){
    Tvec vec;
    int ML, acum, Nota;
    double Promedio;

    CargarNotas(vec, &ML, &acum);
    if(ML == 0){
        printf("No se ingresaron notas.");

    }
    else{
        Promedio = PromedioNotas(ML, acum);
        printf("El promedio es %.2lf\n", Promedio);
        MostrarMayorProm(vec, ML, Promedio);        
    }

    return;
}