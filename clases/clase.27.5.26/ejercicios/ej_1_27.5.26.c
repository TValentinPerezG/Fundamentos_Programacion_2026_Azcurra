/* 
- Indicar el nombre de alumno con mejor promedio
- Indicar el promedio general en el primer parcial
- Ordenar ascendentemente el listado segun el padron 
- Ingresar por teclado un padron y que se muestren sus datos 
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TAMANIO 3

/* definimos una estructura alumno */
typedef struct  
{
     char nombre[30];
     int padron;
     char email[50];
     int notas[2] ;
     float promedio;
} struct_alumno;

typedef struct_alumno talumno[TAMANIO];

void cargar(talumno alum)
{
    int i;
    for(i=0;i<TAMANIO;i++)
    {
        printf("\nIngrese el Nombre:\n");
        scanf("%s",alum[i].nombre);

        printf("Ingrese el padron:\n");
        scanf("%d",&alum[i].padron);

        printf("Ingrese el email:\n");
        scanf("%s",alum[i].email);

        printf("Ingrese la nota del Parcial 1:\n");
        scanf("%d",&alum[i].notas[0]);

        printf("Ingrese la nota del Parcial 2:\n");
        scanf("%d",&alum[i].notas[1]);

	alum[i].promedio = (float)(alum[i].notas[0] + alum[i].notas[1])/2;
    }
}

int mejorPromedio(talumno alum){
    int pos_prom_mayor = 0;
    int i;
    float prom_mayor = 0;

    for(i=0;i<TAMANIO;i++){
        if(prom_mayor < alum[i].promedio){
            prom_mayor = alum[i].promedio;
            pos_prom_mayor = i;
        }
    }
    
    return pos_prom_mayor;
}

float obtenerPromGeneral(talumno alum){
    int i;
    float suma_1er_parcial=0;

    for(i=0;i<TAMANIO;i++){
        suma_1er_parcial = suma_1er_parcial + alum[i].notas[0];
    }

    return (float)suma_1er_parcial / TAMANIO;
}

void ordenamientoPorPadron(talumno alum){
    int i, j;
    struct_alumno auxiliar;
    for(i=0;i<TAMANIO;i++){
        for(j=0;j<TAMANIO-1-i;j++){
            if(alum[j].padron > alum[j+1].padron){
                auxiliar = alum[j];
                alum[j] = alum[j+1];
                alum[j+1] = auxiliar;
            }
        }
    }
}

int pedirPadron(){
    int padronBuscado;

    printf("\n\nIngrese el padron del alumno buscado: ");
    scanf("%i", &padronBuscado);

    return padronBuscado;
}

int busquedaOrdenadaPorPadron(talumno alum){
    int padron_buscado=pedirPadron();
    int devolucion = -1;
    int fin = TAMANIO;
    int inicio = 0;
    int centro;
    bool encontrado = false;

    while((inicio<fin) && !encontrado){
        centro = (inicio+fin)/2;
        if(alum[centro].padron == padron_buscado){
            encontrado=true;
        }
        else{
            if(alum[centro].padron < padron_buscado){ 
                inicio = centro + 1;
            }
            else{ 
                fin = centro - 1;
            }
        }
    }
    if(encontrado){ 
        devolucion = centro;
    }

    return devolucion;
}

void muestraBusqueda(talumno alum){
    int posicion = busquedaOrdenadaPorPadron(alum);

    if(posicion != -1){
    printf("\n\n Alumnos[%d]",posicion);
	printf("\n nombre: %s ", alum[posicion].nombre);
	printf("\n padron: %d ", alum[posicion].padron);	
	printf("\n email: %s ", alum[posicion].email);
	printf("\n Nota Parcial 1: %d Nota Parcial 2: %d", alum[posicion].notas[0],alum[posicion].notas[1]);
	printf("\n promedio Cd: %.2f ", alum[posicion].promedio);
    }
    else{
        printf("No se encontro el alumno.");
    }
}

void mostrar(talumno alum)
{
    int i;
    for(i=0;i<TAMANIO;i++)
    {
 	printf("\n\n Alumnos[%d]",i);
	printf("\n nombre: %s ", alum[i].nombre);
	printf("\n padron: %d ", alum[i].padron);	
	printf("\n email: %s ", alum[i].email);
	printf("\n Nota Parcial 1: %d Nota Parcial 2: %d", alum[i].notas[0],alum[i].notas[1]);
	printf("\n promedio Cd: %.2f ", alum[i].promedio);
    }
}

int main(void)
{
    talumno Alumnos;
    int mayor_prom_posi;
    float prom_gen;
    // cargo los elementos con funcion cargar
    cargar(Alumnos);

    ordenamientoPorPadron(Alumnos);
    muestraBusqueda(Alumnos);
 	/* Muestro datos del primer elemento de la tabla*/
    mostrar(Alumnos);
    mayor_prom_posi = mejorPromedio(Alumnos);
    printf("\n\nEl alumno con mayor promedio es: %s ", Alumnos[mayor_prom_posi].nombre);
    prom_gen = obtenerPromGeneral(Alumnos);
    printf("\nEl promedio entre los promedios es: %.2f", prom_gen);

	printf("\n\n");
	return 0;
}