/*
realizar 2 programas. Uno que permita guardar todos los alumnos que se encuentren
inscriptos en las carreras de informacion de FIUBA (DNI, Nombre, Email, Sede),
y otro que permita msotrar los alumnos
*/

// CARGAR
#include <stdio.h>
#include <string.h>
#define MAX_NOM 100

typedef char String[MAX_NOM];

typedef struct  {
   int DNI;
   String Nombre;
   String Email; 
   int Sede;
} TRegistro;

void cargar(FILE *carga_archivo){
    TRegistro alumnos;

    carga_archivo = fopen("estudiantes.dat", "wb");

    printf("Ingrese el DNI del alumno (0 para parar): ");
    scanf("%i", &alumnos.DNI);
    getchar();

    while(alumnos.DNI != 0){
        printf("Ingrese el nombre del alumno: ");
        fgets(alumnos.Nombre, MAX_NOM, stdin);
        fflush(stdin);

        printf("Ingrese el email del alumno: ");
        fgets(alumnos.Email, MAX_NOM, stdin);
        fflush(stdin);

        printf("Ingrese el numero de la sede: ");
        scanf("%i", &alumnos.Sede);
        getchar();

        fwrite(&alumnos, sizeof(alumnos), 1, carga_archivo);

        printf("Ingrese el DNI del alumno (0 para parar): ");
        scanf("%i", &alumnos.DNI);
        getchar();
    }

    fclose(carga_archivo);

}

void Mostrar(FILE *Archivo){
    TRegistro rAlumnos;
      
    Archivo = fopen("estudiantes.dat", "rb");
    
    if(Archivo == NULL){
        printf("No se pudo abrir el archivo\n");
    } 
    else {   
        printf("\nDNI \tNombre \t Email \tSede\n");
        fread(&rAlumnos, sizeof(TRegistro), 1, Archivo);
        while(!feof(Archivo)){
            printf("\n %i \t %s \t%s \t %i \n",rAlumnos.DNI, rAlumnos.Nombre, rAlumnos.Email, rAlumnos.Sede);
            fread(&rAlumnos, sizeof(TRegistro), 1, Archivo);
        }
        fclose(Archivo);
    }
}

int main( ) {
    FILE *Archivo;

    cargar(Archivo);

    return 0;
}