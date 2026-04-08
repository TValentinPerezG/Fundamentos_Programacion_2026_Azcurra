#include <stdio.h>
#include <stdlib.h>

/* Ingresar el radio de una esfera y calcular el volumen. */
#define PI 3.14159

int main(int argc, char *argv[]) {
	float rad_esf, volu_esf;
	
	printf("Ingrese el radio de la esfera: ");
	scanf("%f", &rad_esf);
	
	
	volu_esf =  ((4 * PI) / 3) * (rad_esf * rad_esf * rad_esf);
	

	printf("\nLa esfera de radio %f \nTiene el siguiente volumen: %f", rad_esf, volu_esf);
	
	printf("\n\nPrograma finalizado");
	
	
	return 0;
}