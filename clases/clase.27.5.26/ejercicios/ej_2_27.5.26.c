/* 
Una librería desea llevar el control de los libros disponibles en stock utilizando un vector de estructuras.

Cada libro posee la siguiente información:

Código numérico
Título
Autor
Precio
Cantidad en stock
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXIMOSISTEMA 100

typedef struct
{
    int codigo;
    char titulo[30];
    char autor[20];
    float precio;
    int stock;
}tlibro;

typedef tlibro tlibros[MAXIMOSISTEMA];

typedef struct{
    int codigo;
    int stock;
    char titulo[30];
}tpedido;

typedef tpedido tpedidos[MAXIMOSISTEMA];

void cargarLibros(tlibros libros, int *ml){
    *ml=0;
    int ingreso_codigo;
    printf("\nIngrese el codigo (0 para terminar): ");
    scanf("%i", &ingreso_codigo);

    while(*ml < MAXIMOSISTEMA && ingreso_codigo != 0){
        getchar();
        libros[*ml].codigo = ingreso_codigo;
        printf("Ingrese el titulo del libro: ");
        fgets(libros[*ml].titulo, 20, stdin);
        libros[*ml].titulo[strcspn(libros[*ml].titulo, "\n")] = '\0';
        fflush(stdin);
        printf("Ingrese el autor del libro: ");
        fgets(libros[*ml].autor, 20, stdin);
        libros[*ml].autor[strcspn(libros[*ml].autor, "\n")] = '\0';
        fflush(stdin);
        printf("Ingrese el precio del libro: ");
        scanf("%f", &libros[*ml].precio);
        printf("Ingrese el stock disponible del libro: ");
        scanf("%i", &libros[*ml].stock);
        *ml = *ml + 1;

        printf("\nIngrese el codigo (0 para terminar): ");
        scanf("%i", &ingreso_codigo);
    }

}

void mostrarLibro(tlibro libro){
    printf("%i | %s | %s | $%.2f | %i\n", libro.codigo, libro.titulo, libro.autor, libro.precio, libro.stock);
}

void mostrarTablaLibros(tlibros libros, int ml){
    int posi;

    printf(" Todos los Libros");
    printf("*---------------------------------------------------------------*\n");
    printf(" Codigo | Titulo | Autor | Precio | Stock\n\n");
    for(posi=0;posi<ml;posi++){
        mostrarLibro(libros[posi]);
        printf("\n");
    }
    printf("*---------------------------------------------------------------*\n\n");
}

void mostrarLibrosStockStockMenorCinco(tlibros libros, int ml){
    int posi;

    printf(" Libros con stock de menos de 5 unidades\n");
    printf("*---------------------------------------------------------------*\n");
    printf(" Codigo | Titulo | Autor | Precio | Stock\n\n");
    for(posi=0;posi<ml;posi++){
        if(libros[posi].stock < 5){
            mostrarLibro(libros[posi]);
        }
    }
    printf("*---------------------------------------------------------------*\n\n");
}

void llenarTablaPedidos(tlibros libros, int ml, tpedidos pedidos, int *ml_pedidos){
    int posi;
    *ml_pedidos = 0;

    for(posi=0;posi<ml;posi++){
        if(libros[posi].stock < 5){
            pedidos[*ml_pedidos].codigo = libros[posi].codigo;
            pedidos[*ml_pedidos].stock = libros[posi].stock;
            strcpy(pedidos[*ml_pedidos].titulo, libros[posi].titulo);
            *ml_pedidos = *ml_pedidos + 1;
        }
    }
}

void mostrarPedido(tpedido pedido){
    printf("\n %i | %i | %s", pedido.codigo, pedido.stock, pedido.titulo);
}

void mostrarTablaPedidos(tpedidos pedidos, int ml_pedidos){
    int posi;

    printf(" Todos los pedidos \n");
    printf("*---------------------------------------------------------------*\n");
    printf(" Codigo | Stock\n");
    for(posi=0;posi<ml_pedidos;posi++){
        mostrarPedido(pedidos[posi]);
        printf("\n\n");
    }
    printf("*---------------------------------------------------------------*\n\n");
}

int main(){
    tlibros libros;
    tpedidos pedidos;
    int maximo_log_libros, maximo_log_pedidos;

    cargarLibros(libros, &maximo_log_libros);

    mostrarTablaLibros(libros, maximo_log_libros);

    mostrarLibrosStockStockMenorCinco(libros, maximo_log_libros);

    llenarTablaPedidos(libros, maximo_log_libros, pedidos, &maximo_log_pedidos);

    mostrarTablaPedidos(pedidos, maximo_log_pedidos);

    return 0;
}