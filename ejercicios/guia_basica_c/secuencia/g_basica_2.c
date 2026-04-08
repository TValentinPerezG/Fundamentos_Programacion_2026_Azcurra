#include <stdio.h>
#include <stdlib.h>

/*Calcular el sueldo de un operario ingresando por teclado la cantidad de horas que
trabajo en el mes y el valor de la hora. Mostrarle el resultado al usuario con un
mensaje adecuado.*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float hrs_trabajadas, valor_hrs, sueldo_mes;
	
	printf("Ingrese cuantas horas trabajo el operario este mes: ");
	scanf("%f", &hrs_trabajadas);
	
	printf("\nIngrese el valor de las horas: ");
	scanf("%f", &valor_hrs);
	
	sueldo_mes = (hrs_trabajadas * valor_hrs) / 2;
	

	printf("\nEl operador trabajo %f horas \nEl valor actual de las horas es %f \nPor lo que su sueldo es %f", hrs_trabajadas, valor_hrs, sueldo_mes);
	
	printf("\n\nPrograma finalizado");
	
	
	return 0;
}
