#include <stdio.h>
#include <string.h>

/* Dada la siguiente estructura:

typedef struct{
	int padron;
	char ape_nom[30];
	float nota;
}t_regAlumno;

Escriba un programa modular que permita dar de alta registros de tipo t_regAlumno.
El usuario debe poder continuar ingresando datos hasta que ingrese un padron igual a 0.
Asuma que el archivo es inexistente.
Deberá subir el archivo generado, con al menos 5 datos de alumnos.
 */

typedef struct{
	int padron;
	char ape_nom[30];
	float nota;
}t_regAlumno;

void ingresar_usuarios(FILE *alumnos){
    t_regAlumno ing_alumnos;

    printf("Padron de alumno (0 para terminar): ");
    scanf("%i", &ing_alumnos.padron);
    getchar();

    while( ing_alumnos.padron != 0){

        printf("Apellido y nombre: ");
        fgets(ing_alumnos.ape_nom, sizeof(ing_alumnos.ape_nom), stdin);

        printf("Nota: ");
        scanf("%f", &ing_alumnos.nota);

        fwrite(&ing_alumnos, sizeof(ing_alumnos), 1, alumnos);

        printf("\nPadron de alumno (0 para terminar): ");
        scanf("%i", &ing_alumnos.padron);
        getchar();
    }

}

void mostrar_ingresos(FILE *alumnos){
    t_regAlumno mostrar_alumnos;

    fread(&mostrar_alumnos, sizeof(mostrar_alumnos),1,alumnos);

    printf("\nCodigo \tDescripcion \t\tCantidad\n");

    while(!feof(alumnos)){
        printf("\n %d \t %-30s %8.2f",mostrar_alumnos.padron,mostrar_alumnos.ape_nom,mostrar_alumnos.nota);
        fread(&mostrar_alumnos, sizeof(mostrar_alumnos),1,alumnos);
        
    }

}

int main(){
    FILE *archivo_ejemplo;

    archivo_ejemplo = fopen("alumnos.dat", "rb");

    if(archivo_ejemplo == NULL){
        printf("\nNo se pudo abrir el archivo\n");
    }    
    else{
        ingresar_usuarios(archivo_ejemplo);
        mostrar_ingresos(archivo_ejemplo);
        fclose(archivo_ejemplo);
    }


}