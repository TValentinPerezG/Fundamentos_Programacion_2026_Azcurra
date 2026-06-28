#include <stdio.h>
#include <stdlib.h>

void ejemploRealloc() {
    // 1. Reservamos espacio inicial para 2 números enteros en el Heap
    int *elementos = malloc(2 * sizeof(*elementos));
    int *temporal;

    if (elementos == NULL) {
        printf("Error: No hay memoria suficiente.\n");
    }
    else{
        // Llenamos los primeros 2 elementos
        elementos[0] = 10;
        elementos[1] = 20;
        printf("Espacio inicial (2 elementos): %d y %d\n", elementos[0], elementos[1]);

        // 2. Agrandamos la memoria para albergar 3 enteros
        temporal = realloc(elementos, 3 * sizeof(*temporal));

        if (temporal == NULL) {
            printf("Error: No se pudo agrandar la memoria. La original sigue intacta.\n");
            // Si falla, debemos liberar la memoria original
        }
        else{
            // Si realloc tuvo éxito, actualizamos nuestro puntero principal
            elementos = temporal;

            // 3. Añadimos el nuevo elemento en el espacio extra
            elementos[2] = 30;

            // Mostramos todos los elementos agrandados
            printf("Nuevo espacio (3 elementos): %d, %d y %d\n", elementos[0], elementos[1], elementos[2]);

            
        } 
        // 4. Al terminar, liberamos la memoria
        free(elementos);
    }
}

int main() {

    ejemploRealloc();

    return 0;
}