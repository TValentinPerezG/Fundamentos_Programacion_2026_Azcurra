#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Solicitar al usuario el ingreso de una temperatura (puede tener decimales por
ejemplo 24.5) y la unidad en la que se encuentra (siendo solo un carácter F ó C).
Luego el programa debe mostrar la temperatura ingresada, convertida en la otra
unidad.
La relación entre temperaturas Celsius y Fahrenheit está dada por la fórmula:
C=5.0 / 9.0 * (F − 32) */

int main() {
	float temp_actual, conversion;
	char unidades;
	
	printf("\nIngrese C si es Celsius o F si es Fahrenheit: ");
	scanf("%c", &unidades);
	
	printf("Ingrese una temperatura: ");
	scanf("%f", &temp_actual);
	
	if(unidades == 'F'){
		conversion = (temp_actual - 32) * 5 / 9;
		printf("\nIngreso una temperatura en Fahrenheit, pasada a Celsius esta seria %f", conversion);
	}
	else if(unidades == 'C'){
		conversion = (temp_actual * 9 / 5) + 32;
		printf("\nIngreso una temperatura en Celsius, pasada a Fahrenheit esta seria %f", conversion);
	}
	else{
		printf("\nNo se ingreso un caracter admisible.");
	}
	
	printf("\n\nPrograma finalizado");
	
	
	return 0;
}