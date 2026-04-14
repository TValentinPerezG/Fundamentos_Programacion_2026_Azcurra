#include <stdio.h>

int main(){
	int num, cubo;
    
    printf("Ingrese numeros");
    scanf("%d", &num);

	while(num != 0){
    	cubo = num * num * num;
		printf("El cuadrado del numero ingresado es %d\n", cubo);
		
        printf("Ingrese el siguiente numero: ");
        scanf("%d", &num);
	}

    return 0;
}