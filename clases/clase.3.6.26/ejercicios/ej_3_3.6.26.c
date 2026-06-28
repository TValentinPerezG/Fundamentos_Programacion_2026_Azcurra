/* Se tiene un listado de alumnos de Algoritmos 1.
Por cada alumnos se tiene Nombre, Apellido, Padron, nota final.
 
Se pide:
a- Cargar informacion preguntando al usuario si quiere seguir cargando alumnos
b- Mostrar Info cargada

c- Mostrar el Promedio de notas
d- Ordenar por padron y mostrar todos los datos

e-Generar un archivo ordenado por padron
f-Generar un archivo de alumnos aprobados y otro de no aprobados a partir del archivo del punto anterior
*/
//B

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXALUMNOS 200

typedef struct  
{
     char nombre[30];
     char apellido[25];
     int nota;
     int padron;
} talumno;

typedef talumno tvalumnos[MAXALUMNOS];

void cargar_datos(tvalumnos tabla_alumnos, int *ml){
    *ml = 0;
    char condicion;

    printf("Ingrese s para finalizar");
    scanf("%c", &condicion);

    while(condicion != 's' && *ml < MAXALUMNOS){
        //aca van todos los ingresos

        *ml = *ml + 1;

        printf("Ingrese s para finalizar");
        scanf("%c", &condicion);
    }
}

void mostrar_alumnos_tabla(tvalumnos tabla_alumnos, int ml){
    int i;

    printf("\t Posicion \t Nombre \t Apellido \t Padron \t Nota\n");
    for(i=0;i<ml;i++){
        printf("\t %i \t %s \t %s \t %i \t %i", i, tabla_alumnos[i].nombre, tabla_alumnos[i].apellido, tabla_alumnos[i].padron, tabla_alumnos[i].nota);
        printf("\n");
    }
}

float cargar_promedio_notas(tvalumnos tabla_alumnos, int ml){
    float suma_prom = 0;
    float promedio=0;
    int i;

    for(i=0;i<ml;i++){
        suma_prom = suma_prom + tabla_alumnos[i].nota;
    }
    if(ml != 0){
        promedio = suma_prom/ml;
    }

    return promedio;
}

void ordenar_padron_y_mostrar(tvalumnos tabla_alumnos, int ml){
    int i=0;
    int j;
    bool encontrado = true;
    talumno auxiliar_alum;

    while((i<ml) && encontrado){
        encontrado = false;
        for(j=0;j<ml-i;j++){
            if(tabla_alumnos[j].padron > tabla_alumnos[j+1].padron){
                auxiliar_alum = tabla_alumnos[j];
                tabla_alumnos[j] = tabla_alumnos[j+1];
                tabla_alumnos[j+1] = auxiliar_alum;
            }
        }
        i++;
    }

    mostrar_alumnos_tabla(tabla_alumnos, ml);

}


//e-Generar un archivo ordenado por padron
//f-Generar un archivo de alumnos aprobados y otro de no aprobados a partir del archivo del punto anterior
void crear_archivo_ordenado(tvalumnos tabla_alumnos, int ml, FILE *carga_archivo){
    int i=0;
    carga_archivo= fopen("estudiantesej3.dat", "wb");
    for(i;i<ml;i++){
        fwrite(&tabla_alumnos[i], sizeof(talumno), 1, carga_archivo);
    }
    fclose(carga_archivo);
}

void crear_tablas_aprob_desap(FILE *archivo_ordenado, FILE *carga_aprob, FILE *carga_desap){
    talumno alum_aux;

    archivo_ordenado = fopen("estudiantesej3.dat", "rb");
    carga_aprob= fopen("estudiantesAprob.dat", "wb");
    carga_desap= fopen("estudiantesDesaprob.dat", "wb");
    
    fread(&alum_aux, sizeof(talumno), 1, archivo_ordenado);

    while(!feof(archivo_ordenado)){
        if(alum_aux.nota < 4){
            fwrite(&alum_aux, sizeof(talumno), 1, carga_desap);
        }
        else{
            fwrite(&alum_aux, sizeof(talumno), 1, carga_aprob);
        }
        fread(&alum_aux, sizeof(talumno), 1, archivo_ordenado);
    }

    fclose(archivo_ordenado);
    fclose(carga_aprob);
    fclose(carga_desap);
}

int main(){
    FILE *archivo_ordenado, *archivo_aprobados, *archivo_desaprobados;
    tvalumnos tabla_alumnos;
    int max_logico;
    float prom_notas;

    cargar_datos(tabla_alumnos, &max_logico);
    mostrar_alumnos_tabla(tabla_alumnos, max_logico);
    prom_notas = cargar_promedio_notas(tabla_alumnos, max_logico);
    ordenar_padron_y_mostrar(tabla_alumnos, max_logico);
    crear_archivo_ordenado(tabla_alumnos, max_logico, archivo_ordenado);
    crear_tablas_aprob_desap(archivo_ordenado, archivo_aprobados, archivo_desaprobados);

    return 0;
}