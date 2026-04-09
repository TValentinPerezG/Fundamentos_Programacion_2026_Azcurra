#include <stdio.h>

/* Se tiene una lista de casos confirmados de coronavirus por cada pais */
/* Se pide:
    - Indicar cual es el promedio mundial
    - Cantidad de casos mundiales
    - Que cantidad de casos tiene el pais con menos casos
    - Que cantidad de casos tiene el pais con mas casos 
    
    -1 para terminar*/

int main(){
	int casos, prom, acum_casos=0, i=0, cant_menor, cant_mayor;
    
    printf("Ingrese la cantidad de casos del pais: ");
    scanf("%d", &casos);

    cant_menor = casos;
    cant_mayor = casos;

    while(casos != -1){
        acum_casos = acum_casos + casos;
        i++;

        if(cant_menor > casos){
            cant_menor = casos;
        }
        else if(cant_mayor < casos){
            cant_mayor = casos;
        }

        printf("Ingrese la cantidad de casos del pais: ");
        scanf("%d", &casos);    
    }
    
    if(i == 0){
        printf("No se ingreso ningun caso\n");
    }
    else{
        prom = acum_casos/i;

        printf("El total de casos es: %i\n", acum_casos);
        printf("El promedio de casos por pais es: %i\n", prom);
        printf("Los casos del pais con la mayor cantidad son: %i\n", cant_mayor);
        printf("Los casos del pais con la menor cantidad son: %i\n", cant_menor);
    }

    return 0;
}