/*
Una libreria posee un archivo denominado Stock.dat, cuyos registros contienen el codigo del libro (entero), el titulo (30 caracteres), el stock actual de dicho libro (entero), el stock minimo de dicho libro (entero) y el precio unitario (real). Dicho archivo no esta ordenado y "NO ENTRA" en memoria en su totalidad. Se pide desarrollar un programa modular en lenguaje C que procese este archivo y que permita:
Generar una tabla llamada Ofertas que contenga solo los libros cuyo stock actual esta por encima del doble del stock minimo. Incluir en la tabla los siguientes campos:

El codigo del libro (entero)
El titulo del libro (30 caracteres).
La cantidad de libros a ofertar (entero, a lo sumo se pueden ofertar la mitad de los libros que estan por sobre el stock minimo).
El precio unitario de oferta (real, el descuento de la oferta es del 30%). Asumir que esta tabla tendra como maximo 100 registros y que cabe en memoria.
Ordenar la tabla Ofertas ascendentemenete por titulo del libro.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TABLAMAX 100

typedef struct{
    int codigo;
    char titulo[30];
    int stock_actual;
    int stock_minimo;
    float precio;
}t_stock;

typedef struct{
    int codigo;
    char titulo[30];
    int cant_oferta;
    float precio_descuento;
}t_oferta;

typedef t_oferta t_ofertas[TABLAMAX];

void crear_tabla(FILE *stock, t_ofertas tabla, int *ml){
    t_stock registro;
    int i=0;

    fread(&registro, sizeof(t_stock), 1, stock);

    while(!feof(stock) && i<TABLAMAX){
        if(registro.stock_actual > (registro.stock_minimo*2)){
            tabla[i].codigo = registro.codigo;
            strcpy(tabla[i].titulo, registro.titulo);
            tabla[i].cant_oferta = (registro.stock_actual-registro.stock_minimo)/2;
            tabla[i].precio_descuento = registro.precio*0.7;
            
            i++;
        }

        fread(&registro, sizeof(t_stock), 1, stock);
    }

    *ml = i;
}

void ordenar_tabla(t_ofertas tabla, int ml){
    int i,j;
    t_oferta aux;
    bool encontrado = true;
    i=1;
    while(encontrado && i<ml){
        encontrado=false;
        for(j=0;j<ml-i;j++){
            if(strcmp(tabla[j].titulo,tabla[j+1].titulo) > 0){
                aux = tabla[j];
                tabla[j] = tabla[j+1];
                tabla[j+1] = aux;
                encontrado=true;
            }
        }
        i++;
    }

}

int main(){
    int ml;
    t_ofertas tabla;
    FILE *stock;

    stock = fopen("stock.dat", "rb");

    if(stock != NULL){
        crear_tabla(stock, tabla, &ml);

        ordenar_tabla(tabla, ml);

        fclose(stock);
    }
    else{
        printf("no funco el archivo");
    }

    return 0;
}
