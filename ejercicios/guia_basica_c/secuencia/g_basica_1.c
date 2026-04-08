#include <stdio.h>
#include <stdlib.h>

/*  Hallar la superficie de un tri�ngulo conociendo la base y la altura. Solicitarle los
datos de entrada al usuario. */
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float alt_tri, base_tri, sup_tri;
	
	printf("Ingrese la base de su triangulo: ");
	scanf("%f", &base_tri);
	
	printf("\nIngrese la altura de su triangulo: ");
	scanf("%f", &alt_tri);
	
	sup_tri = (base_tri * alt_tri) / 2;
	
	if(base_tri <= 0 || alt_tri <= 0){
		printf("\nNo se puede sacar la superficie con estos valores");
	}
	else{
		printf("\nLa superficie de triangulo es %f", sup_tri);
	}
	printf("\n\nPrograma finalizado");
	 
	return 0;
}
