#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Escribir un programa modular en C, que solicite el ingreso de no mas de 10 palabras
    cada palabra no tendra mas de 20 caracteres
    al finalizar la carga, mostrar las palabras ingresadas
    Luego mostrar las palabras de forma ordenada alfabeticamente*/
// hacer por burbujeo
//ahora tenemos datos de un alumno y ingresamos su numero de legajo, y estos deben quedar relacionados
#define MAXALUMNOS 10
#define MAXLARGONOMBRE 50

typedef char tnombre[MAXLARGONOMBRE];
typedef tnombre talumno[MAXALUMNOS];
typedef int tlegado[MAXALUMNOS]; 

void cargar_palabras(talumno palabras, tlegado legajo, int *ml){
    *ml = 0;

    do{
        printf("Ingrese la cadena de como mucho 20 caracteres. Si quiere detenerse ingrese un espacio: ");
        fgets(palabras[*ml], 21, stdin);
        fflush(stdin);
        if(strcmp(palabras[*ml], " \n") != 0){
            printf("Ingrese el legajo del alumno: ");
            scanf("%i", &legajo[*ml]);  
            getchar();

            *ml = *ml + 1;
        }
    }while((*ml < MAXALUMNOS) && strcmp(palabras[*ml], " \n") != 0);
}

void mostrar_palabras(talumno listado, tlegado legajo, int ml){
    int i;

    for(i=0;i<ml;i++){
        printf("%i - %s", legajo[i], listado[i]);

    }
    printf("\n\n");
}

void ordenar_listado_burbujeo_por_nombre(talumno palabras, tlegado legajo, int ml){
    int i=1, j, aux;
    bool hubo_cambios = true;
    tnombre nombre_auxiliar;

    while((i<ml) && hubo_cambios){ 
        hubo_cambios=false;
        for(j=0;j<ml-i;j++){ 
            if(strcmp(palabras[j], palabras[j+1])>0){ //quiero cambiar solo esto, tengo que ver de cambiar solo esto
                strcpy(nombre_auxiliar, palabras[j]);
                strcpy(palabras[j], palabras[j+1]);
                strcpy(palabras[j+1], nombre_auxiliar);
                aux = legajo[j];
                legajo[j] = legajo[j+1];
                legajo[j+1] = aux;
                hubo_cambios=true;
            }
        }
        i++;
    }
}

void ordenar_listado_burbujeo_por_legajo(talumno palabras, tlegado legajo, int ml){
    int i=1, j, aux;
    bool hubo_cambios = true;
    tnombre nombre_auxiliar;

    while((i<ml) && hubo_cambios){ 
        hubo_cambios=false;
        for(j=0;j<ml-i;j++){ 
            if(legajo[j] < legajo[j+1]){ //quiero cambiar solo esto, tengo que ver de cambiar solo esto
                strcpy(nombre_auxiliar, palabras[j]);
                strcpy(palabras[j], palabras[j+1]);
                strcpy(palabras[j+1], nombre_auxiliar);
                aux = legajo[j];
                legajo[j] = legajo[j+1];
                legajo[j+1] = aux;
                hubo_cambios=true;
            }
        }
        i++;
    }
}


// int busqueda_lineal(tpalabras palabra, int ml, tcadena palabra_buscada){
//     int devolucion_pos = -1;
//     int posicion = 0;

//     while((posicion <ml) && strcmp(palabra[posicion], palabra_buscada) != 0){
//         posicion++;
//     }
//     if(posicion<ml){
//         devolucion_pos = posicion;
//     }

//     return devolucion_pos;
// }


int main(){
    talumno nombres_alum;
    tlegado legajo_alum;
    int ml, eleccion;

    cargar_palabras(nombres_alum, legajo_alum, &ml);

    printf("\nPALABRAS INGRESADAS.\n");
    mostrar_palabras(nombres_alum, legajo_alum, ml);

    printf("Elija si quiere ordenar por nombre (0) o legajo (1): ");
    scanf("%i", &eleccion);
    if(eleccion == 1){
        ordenar_listado_burbujeo_por_legajo(nombres_alum, legajo_alum, ml);
    }
    else if(eleccion == 0){
        ordenar_listado_burbujeo_por_nombre(nombres_alum, legajo_alum, ml);
    }
    printf("PALABRAS ORDENADAS.\n");
    mostrar_palabras(nombres_alum, legajo_alum, ml);

    return 0;
}