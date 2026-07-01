/*
Una libreria posee un archivo denominado Stock.dat, cuyos registros contienen el codigo del libro (entero), el titulo (30 caracteres), el stock actual de dicho libro (entero), 
el stock minimo de dicho libro (entero) y el precio unitario (real). Dicho archivo no esta ordenado y "NO ENTRA" en memoria en su totalidad. Se pide desarrollar un programa modular 
en lenguaje C que procese este archivo y que permita:
Generar una tabla llamada Ofertas que contenga solo los libros cuyo stock actual esta por encima del doble del stock minimo. Incluir en la tabla los siguientes campos:

El codigo del libro (entero)
El titulo del libro (30 caracteres).
La cantidad de libros a ofertar (entero, a lo sumo se pueden ofertar la mitad de los libros que estan por sobre el stock minimo).
El precio unitario de oferta (real, el descuento de la oferta es del 25%). Asumir que esta tabla tendra como maximo 100 registros y que cabe en memoria.
Ordenar la tabla Ofertas ascendentemenete por titulo del libro.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    int cantidad_ofertar;
    float precio_oferta;
}t_oferta;

typedef t_oferta t_ofertas[100];

void generar_tabla(FILE *archivo_stock, t_ofertas tabla, int *ml){
    t_stock stock_libros;
    int i=0;

    fread(&stock_libros,sizeof(t_stock),1,archivo_stock);
    
    while(!feof(archivo_stock) && i<100){
        if(stock_libros.stock_actual > 2*stock_libros.stock_minimo){
            tabla[i].codigo = stock_libros.codigo;
            strcpy(tabla[i].titulo,stock_libros.titulo);
            tabla[i].cantidad_ofertar = (stock_libros.stock_actual - stock_libros.stock_minimo)/2;
            tabla[i].precio_oferta = stock_libros.precio * 0.75;

            i++;    
        }

        fread(&stock_libros,sizeof(t_stock),1,archivo_stock);
    }

    *ml = i;
}

void ordenar_tabla_burbujeo(t_ofertas tabla, int ml){
    //hacemos por burbujeo optimizado
    int i, j;
    t_oferta aux;
    bool encontrado = true;
    i=1;

    while(i<ml && encontrado){
        encontrado=false;
        for(j=0;j<ml-i;j++){
            if(strcmp(tabla[j].titulo,tabla[j+1].titulo)>0){
                aux = tabla[j];
                tabla[j] = tabla[j+1];
                tabla[j+1] = aux;

                encontrado=true;
            }
        }
        i++;
    }
}

void ordenar_tabla_insercion(t_ofertas tabla, int ml){
    int k,i;
    t_oferta aux;

    for(k=1;k<ml;k++){
        i = k-1;
        aux = tabla[k];
        while((i>=0) && (strcmp(aux.titulo,tabla[i].titulo)>0)){
            tabla[i+1] = tabla[i];
            i--;
        }
        tabla[i+1] = aux;
    }
}

void ordenar_tabla_seleccion(t_ofertas tabla, int ml){
    int i, j, minimo;
    t_oferta aux;

    for(i=0;i<ml-1;i++){
        minimo = i;
        for(j=i+1;j<ml;j++){
            if(strcmp(tabla[j].titulo,tabla[minimo].titulo) <0 ){
                minimo = j;
            }
        }
        aux = tabla[i];
        tabla[i] = tabla[minimo];
        tabla[minimo] = aux;
    }

}

int main(){
    FILE *stock;
    t_ofertas tabla;
    int ml;

    stock = fopen("stock.dat", "rb");

    if(stock != NULL){

        generar_tabla(stock, tabla, &ml);

        ordenar_tabla_burbujeo(tabla, ml);

        fclose(stock);
    }
    return 0;
}