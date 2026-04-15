#include <stdio.h>

/* Leer un numero y indicar si es capicua */
/* Si invertimos  */

int main(){
	int num, invert, aux;
    
    printf("Ingrese un numero para ver si es capicua: ");
    scanf("%d", &num);

    aux = num; 
    invert = aux%10;

    while(aux>9){
        aux = aux/10;
        invert = (invert * 10) + aux%10;
    }
	
    if(num == invert){
        printf("El numero %d es capicua\n", num);
    }
    else{
        printf("El numero %d no es capicua\n", num);
    }

    return 0;
}