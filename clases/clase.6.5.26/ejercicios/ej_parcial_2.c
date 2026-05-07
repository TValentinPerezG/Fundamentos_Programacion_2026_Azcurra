/* Dadas las siguientes declaraciones de constantes y tipos:
#define MAX 100
typedef int t_vector[MAX]

Desarrollar una funcion en lenguaje C que reciba tres parámetros, un vector del tipo t_vector ya cargado con datos que se encuentran en ORDEN ASCENDENTE, su máximo
lógico y un número entero que debe ser intercalado en el vector, de modo que siga ordenado.

Se espera que la funcion devuelva al módulo invocante true si pudo realizar lo solicitado y false si no pudo hacerlo.
Tanto el vector como el máximo lógico actualizados deben devolverse sobre los parámetros recibidos.

Se solicita resolver lo solicitado recorriendo una sola vez el vector y sin utilizar un arreglo auxiliar.
Esccribir un programa que invoque dicha funcion. */
#include <stdio.h>
#include <stdbool.h>

#define MAX 100
typedef int t_vector[MAX];

bool insertar_ent(int num, t_vector vec, int *ml){
    bool posible;
    int i=0;

    if(*ml == MAX){
        posible = false;
    }
    else if(vec[*ml - 1] <= num){
        vec[*ml] = num;
        *ml = *ml + 1;
    }
    else{
        while(num < vec[*ml - 1 -i] && (*ml - 1 - i) >= 0){
            vec[*ml - i] = vec[*ml -1 -i];
            vec[*ml - 1 - i] = num;
            i++;
        }
        *ml = *ml + 1;
    }

    return posible;
}



/*Desarrollar una función en lenguaje C que reciba como parámetro un número entero y devuelva al módulo invocante los siguientes valores:
El mayor dígito que compone al número entero recibido, y
La cantidad de veces que dicho digito máximo se encuentra en el número entero recibido.*/
// valor = num%10
// max = 0;
// if max<valor{
//     reemplazamos max y reseteamos contador a 1
// }

// else if max==valor{
//     aumento contador
// }

