#include <stdio.h>
#include <stdlib.h>

/* Calcular y mostrar la suma de los n primeros números naturales. Siendo n un
número ingresado por el usuario. Usar fórmula [ n.(n+1) ] / 2 */

int main(int argc, char *argv[]) {
	int num_nat, sum_num_nat;
	
    printf("Este programa suma los primeros n numeros naturales\n");
	printf("Ingrese cuantos numeros naturales quiere sumar: ");
	scanf("%d", &num_nat);
	
	
    sum_num_nat =  (num_nat * (num_nat + 1)) / 2;
	

	printf("\nLa suma de los primeros %d numeros naturales da como resultado %d", num_nat, sum_num_nat);
	
	printf("\n\nPrograma finalizado");
	
	
	return 0;
}