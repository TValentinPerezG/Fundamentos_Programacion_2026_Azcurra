/* 
Una farmacia dispone de un archivo binario llamado medicamentos.dat, cuyos registros tienen la siguiente estructura:

código (entero)
categoría (cadena de hasta 25 caracteres, ej. "analgésicos", "antibióticos", etc.)
nombre_comercial (cadena de hasta 30 caracteres)
stock_actual (entero) El archivo no está ordenado y no entra completamente en memoria.
Desarrollar un programa modular que permita:

Solicitar al usuario una categoría.
Generar una tabla en memoria llamada medxcat que contenga todos los medicamentos de esa categoría.
La tabla debe tener la misma estructura que el archivo original.
Suponer que la tabla tiene como máximo 200 registros y entra en memoria.
Mostrar por pantalla los medicamentos de medxcat cuyo stock_actual sea superior al stock promedio dentro de esa categoría.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
    int codigo;
    char categoria[25];
    char nombre_comercial[30];
    int stock_actual;
}t_medicamento;

typedef t_medicamento t_medicamentos[200];

void pedir_categoria(char categoria[]){

    printf("Ingrese el nombre de una categoria: ");
    fgets(categoria, 25, stdin);
    categoria[strcspn(categoria, "\n")] = '\0';

}

void generar_tabla(FILE *lista_medicamento, char categoria[25], t_medicamentos medxcat, int *ml){
    int i = 0;
    t_medicamento lector;

    fread(&lector, sizeof(t_medicamento),1,lista_medicamento);

    while(!feof(lista_medicamento) && (i<200)){
        if(strcmp(lector.categoria, categoria) == 0){
            medxcat[i].codigo = lector.codigo;
            strcpy(medxcat[i].categoria, lector.categoria);
            strcpy(medxcat[i].nombre_comercial, lector.nombre_comercial);
            medxcat[i].stock_actual = lector.stock_actual;

            i++;
        }

        fread(&lector, sizeof(t_medicamento), 1, lista_medicamento);
    }

    *ml = i;
}

int obtener_promedio_stock(t_medicamentos medxcat, int ml){
    int i=0;
    int suma_stock=0;

    if(ml != 0){
        for(i;i<ml;i++){
            suma_stock = suma_stock + medxcat[i].stock_actual;
        }
    }
    else{
        ml=1;
    }

    return suma_stock/ml;
}

void mostrar_tabla(t_medicamentos medxcat, int ml){
    int promedio_stock = obtener_promedio_stock(medxcat, ml);
    int i=0;

    printf("LISTADO DE MEDICAMENTOS CON STOCK MAYOR AL PROMEDIO\n");
    printf("Codigo\t Nombre\t Stock\t\n");
    for(i;i<ml;i++){
        if(medxcat[i].stock_actual > promedio_stock){
            printf("%i\t %s\t %i\n\n", medxcat[i].codigo, medxcat[i].nombre_comercial, medxcat[i].stock_actual);
        }
    }
}

int main(){
    int ml;
    t_medicamentos medxcat;
    FILE *medicamentos;
    char categoria[25];

    medicamentos = fopen("medicamentos.dat", "rb");

    if(medicamentos != NULL){
        pedir_categoria(categoria);

        generar_tabla(medicamentos, categoria, medxcat, &ml);

        mostrar_tabla(medxcat, ml);

        fclose(medicamentos);
    }
    else{
        printf("no se encontro archivo manito");
    }

    return 0;
}