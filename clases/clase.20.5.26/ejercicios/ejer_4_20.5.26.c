#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Escribir un programa modular en C, que solicite el ingreso de no mas de 10 palabras
    cada palabra no tendra mas de 20 caracteres
    al finalizar la carga, mostrar las palabras ingresadas
    Luego mostrar las palabras de forma ordenada alfabeticamente*/
// hacer por burbujeo
#define MAXPALABRAS 10
#define MAXCARACTERES 21

typedef char tcadena[MAXCARACTERES];
typedef tcadena tpalabras[MAXPALABRAS]; 

void cargar_palabras(tpalabras palabras, int *ml){
    *ml = 0;

    do{
        printf("Ingrese la cadena de como mucho 20 caracteres. Si quiere detenerse ingrese un espacio: ");
        fgets(palabras[*ml], 21, stdin);
        fflush(stdin);
        if(strcmp(palabras[*ml], " \n") != 0){
            *ml = *ml + 1;
        }
    }while((*ml < MAXPALABRAS) && strcmp(palabras[*ml], " \n") != 0);
}

void mostrar_palabras(tpalabras listado, int ml){
    int i;

    for(i=0;i<ml;i++){
        printf("%s", listado[i]);
    }
    printf("\n\n");
}

void ordenar_listado_burbujeo(tpalabras palabras, int ml){
    int i=1, j;
    bool hubo_cambios = true;
    tcadena palabra_auxiliar;

    while((i<ml) && hubo_cambios){ 
        hubo_cambios=false;
        for(j=0;j<ml-i;j++){ 
            if(strcmp(palabras[j], palabras[j+1])>0){ 
                strcpy(palabra_auxiliar, palabras[j]);
                strcpy(palabras[j], palabras[j+1]);
                strcpy(palabras[j+1], palabra_auxiliar);
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
    tpalabras palabras;
    int ml;

    cargar_palabras(palabras, &ml);

    printf("\nPALABRAS INGRESADAS.\n");
    mostrar_palabras(palabras, ml);

    ordenar_listado_burbujeo(palabras, ml);

    printf("PALABRAS ORDENADAS.\n");
    mostrar_palabras(palabras, ml);

    return 0;
}