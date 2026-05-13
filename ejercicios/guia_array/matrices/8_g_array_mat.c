/* Se tiene un listado con los siguientes datos:
número de alumno ( 1 a n )
número de materia ( 1 a m )
nota promedio ( 0 a 10 )
El mismo número de alumno y de materia puede aparecer más de una vez.
El listado no está ordenado, ni necesariamente completo. Esto último quiere
decir que puede ser que un alumno no haya cursado una o más materias, y por
lo tanto no existan los datos correspondientes en el listado.
Se pide :
a) Crear una estructura bidimensional que almacene el promedio por
materia de cada alumno e informarla asignándole en la impresión un guión al
caso de falta de datos mencionado.
b) Informar el porcentaje de alumnos que cursó cada materia y el promedio
general por materia considerando los alumnos que la cursaron.
c) Informar la cantidad de materias que cursó cada alumno y el promedio
que obtuvo considerando las materias que cursó. */

#include<stdio.h>
#define NOTA_MAX 10
#define MATERIA 6
#define ALUMNOS 14
typedef float matriz_t[MATERIA][ALUMNOS];
void vacio(matriz_t matriz){
    int i, j;
    for (i=0;i<MATERIA;i++){
        for (j=0;j<ALUMNOS;j++){
            matriz[i][j]=-1;           //-1 en cada valor de la matriz se refiere a que esta vacio
        }
    }
}
void cargar(matriz_t matriz){
    int materia;
    int alumno;
    float nota;
    printf("Ingrese numero del estudiante (0 para acabar): ");
    scanf("%i",&alumno);
    while (alumno!=0){
        while (alumno<1 || alumno>ALUMNOS){
            printf("Alumno ingresado invalido\n");
            printf("Ingrese numero del estudiante (0 para acabar): ");
            scanf("%i",&alumno);
        }
        printf("Ingrese numero de materia: ");
            scanf("%i",&materia);
            while (materia<1 || materia>MATERIA){
                printf("Numero de materia ingresada invalida\n");
                printf("Ingrese numero de materia: ");
                scanf("%i",&materia);
            }
            printf("Ingrese nota del estudiante: ");
            scanf("%f",&nota);
            while (nota<0 || nota>NOTA_MAX){
                printf("Nota ingresada invalida\n");
                printf("Ingrese nota del estudiante: ");
                scanf("%f",&nota);
            }
            matriz[materia-1][alumno-1]=nota;
        printf("Ingrese numero del estudiante (0 para acabar): ");
        scanf("%i",&alumno);
    }
}
void calculo_materias(matriz_t matriz){
    int i, j;
    int cant;
    float prom, suma, porcentaje;
    for(i=0;i<MATERIA;i++){
        cant=0;
        suma=0;
        for (j=0;j<ALUMNOS;j++){
            if (matriz[i][j]!=-1){
                cant++;
                suma+=matriz[i][j];
            }
        }
        if (cant>0){
            prom=suma/cant;
            porcentaje=(cant*100.0)/ALUMNOS;
            printf("Materia %i\n",i+1);
            printf("Porcentaje de alumnos %.1f\n",porcentaje);
            printf("promedio de notas %.1f\n",prom);
        }
        else{
            printf("No hay datos de la materia %i\n",i+1);
        }
    }
    
}
void mostrar(matriz_t matriz){
    int i, j;
    for (i=0;i<MATERIA;i++){
        for (j=0;j<ALUMNOS;j++){
            if (matriz[i][j]==-1){
                printf(" - ");
            }
            else{
                printf(" %.1f ",matriz[i][j]);
            }
        }
        printf("\n");
    }
}
int main(){
    matriz_t matriz;
    vacio(matriz);
    cargar(matriz);
    calculo_materias(matriz);
    mostrar(matriz);
    getchar();
    getchar();
    return 0;
}