## Anotaciones Clase 29 de Abril de 2026 Fundamentos de la Programacion

----

### Que vamos a ver hoy
- Repaso de tipos de datos vistos
- Arreglos (Arrays)
    - Arreglos bidimensionales (vectores) y tridimensionales (matrices)
- Sintaxis
- Ejercicios con arreglos
- Bibliografia complementaria
- Preguntas
- la proxima clase va a ser de cadenas y 

## Tipos de variables

#### Atomicas

guardan un solo valor  
algunas de estas son:  
- Enteros
- Reales
- Caracteres
- Booleanos
- Definidos por usuarios/Enumerados
en estos no se puede guardar mas de un valor en una variables, lo que los hace limitados para ejercicios mas complejos.  

Por ejemplo, si necesitaramos un sistema que tenga un valor por cada dia del mes, necesitariamos 30 o 31 variables  

### Estructuras

#### Arreglos

Son variables con una cantidad de elementos a los que puedo acceder individualmente a un subindice.  
- unidimensionales (vectores)  
- multidimensionales (matrices)  
Los arreglos tienen que ser de un mismo tipo de variable atomica, y comenzaran con un subindice de 0 siempre, y van subiendo.  

#### Cadena de Caracteres

#### Registros

#### Tablas

#### Archivos

En esta clase nos concentraremos en Arreglos

## Arreglos Unidimensionales

- La buena practica es utilizar un mismo arreglo para guardar cosas que sean conceptualmente lo mismo, asi, si tengo un arreglo de lluvia por area, no puedo usar un elemento de este para guardar la temperatura en una de esas areas.
- Tenemos un solo subindice para cada elemento dentro de nuestro vector, que define su posicion.

### Arreglos: Sintaxis

- Vamos a trabajar con la manera mas facil para tratar con vectores, ya que hay una mas rapida con punteros, pero esta la veremos mas adelante, vamos a trabajar con arreglos con [].

----

- Para declarar un array se hace de esta manera:
#### <tipo_base> nombre[cantidad]
donde:    
- tipo base es el tipo de elementos
- nombre es por lo que lo vamos a llamar
- cantidad es cuantos espacios/elementos que vamos a tener dentro de nuestro arreglo
ej: int vector[13] (empieza de 0 y va hasta 12)  

----

Si quiero trabajar con un valor especifico de mi vector, pongo entre los corchetes la posicion del vector con el que quiero trabajar, por ej:  
vector[1] = 6; (le dara el valor 6 a la posicion 1 del vector)  
printf("%d", vector[1]) (se va a imprimir este 6)  

----

Es importante destacar que el subindice puede ser una variable:  

#include <stdio.h>  

int main(int argc, char *argv[])  
{  
  int vector[4];  
  int i;  
  
  // Inicializo el vector  
  for(i=0; i<4; i++)  
    vector[i]=0;  
 
  // Imprimo al vector  
  printf("\nLos valores almacenados en el vector son:\n");  
  for(i=0; i<4; i++)  
    printf("vector[%d] = %d \n", i, vector[i]);  
  
  // Inicializo al vector  
  for(i=0; i<4; i++)  
    vector[i]=i*10;  
  
  // Imprimo al vector  
  printf("\nLos valores almacenados en el vector son:\n");  
  for(i=0; i<4; i++)  
    printf("vector[%d] = %d \n", i, vector[i]);  
  
  return EXIT_SUCCESS;  
}  
en este ejemplo vemos que primero le damos a todos los espacios valor de 0, y luego de mostrarlo de esta manera:   
vector[0] = 0  
vector[1] = 0  
vector[2] = 0  
vector[3] = 0  
y luego le va dando valores crecientes al vector y luego los vuelve a mostrar, de esta manera:  
vector[0] = 0  
vector[1] = 10  
vector[2] = 20  
vector[3] = 30  

----

- Podemos darle valores al declarar el vector de esta manera:
int vector[4] = {15,27,68,73};  
- tambien puedo declarar el vector con los corchetes vacios y darle valores, y el vector automaticamente tomara el largo segun la cantidad de valores que le cargue, de esta forma:
int vector[] = {15,27,68,73};  

----

Los vectores pueden ser del tipo de valor que yo quiera:
int vector_i[] = {15,27,68,73};  
float vector_f[] = {15.5,27.2,68.9,73.78};
char vector_c[] = {'A','?','m','*'};

----

Para no tener que ir cambiando el tamaño que usamos en nuestros for para ir revisando los valores de nuestro vector, podemos utilizar:  
int tamanio = sizeof(vec) / sizeof(vec[0]);
lo que nos divide nuestro vector por uno de sus elementos, dandonos su cantidad de elementos al momento.  
Si al mostrar un vector ponemos mas elementos de los que tiene, nos dara error o nos mostrar basura que hay en ese espacio, como si llamaramos una variable sin un valor dado.

### Pasar arreglos como parametros a una funcion

- En C los vectores siempre se pasan por referencia, no hay diferencia entre pasarlos por referencia y valor
- Lo que hice en la version local de la funcion con la variable se refleja en el main
- Esto ocurre porque llamar vector es como llamar &vector[0], basicamente siempre reemplazando el valor original si se lo altera en la funcion.

----

- Si queremos enviar un vector a una funcion, debemos enviarlo igual que lo hariamos con una variable comun: funcion(vector);
- Cuando estemos en la propia funcion, si tenemos que avisarle a la funcion que va a trabajar con un vector, de esta manera:
int funcion(vec[]){}  

## Aregglos Multidimensionales

- Tenemos 2 lineas, una de dias de la semana y otra de horas por ejemplo, y tenemos algo similar a una lista en estos.
- Como en el anterior, todos nuestros espacios deben tratar con el mismo concepto.

### Matrices: Sintaxis

Se declara similar a los vectores, con una pequeña diferencia:
#### <tipo_base> nombre[filas][columnas];
donde:    
- tipo base es el tipo de elementos
- nombre es por lo que lo vamos a llamar
- filas y columnas seran los espacios que tendremos y generaran espacios combinados
ej: int vector[3][2] (empezaria en 0,0 y seguiria hasta 2,1)
- Pueden tener mas dimensiones pero eso no se vera en la clase.

----

- Podemos darle valores al declarar el vector de esta manera:
int vector[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
    };  
- tambien puedo declarar el vector con los corchetes vacios y darle valores, y el vector automaticamente tomara el largo segun la cantidad de valores que le cargue, de esta forma:
int vector[][] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
    };

### Pasar matrices como parametros a una funcion

- similar a antes, se dice despues que es una matrices pero primero se pasa normalmente
- Lo que hice en la version local de la funcion con la variable se refleja en el main
- Esto ocurre porque llamar vector es como llamar &vector[0], basicamente siempre reemplazando el valor original si se lo altera en la funcion.

----

## Maximo fisico vs maximo logico

- Cuando se declara un vector
- Maximo fisico es el tamaño maximo que se va a reservar de memoria
- El maximo logico es el valor maximo de valores relevantes para lo que trabajaremos
- El maximo logico nunca va a ser mayor a un maximo fisico
- Estos datos los voy ingresando en un while

Por ejemplo, si tenemos un sistema que se pide que tome 100 valores, pero queremos que se detenga cuando se ingrese 0, entonces nuestro maximo fisico tendria que ser de 100, pero el maximo logico puede ser mucho menor o igual  

- De forma practica, usualmente yo le doy un maximo fisico a un sistema conociendo un valor, y ponemos un contador que acompañe el ingreso de notas.
    - Este caso tiene la ventaja de tener una cantidad ya definida en una variable de elementos en nuestra tabla, asi que es bueno para hacer uso de for o similares
    - Esta puede trabajar con while o for
- Si no, la otra forma de hacer de buscar maximo logico es tener un valor que haga que el sistema frene, por ejemplo, -1. Asi, el sistema sabe que 
    - Este caso tiene la ventaja de no tener que declarar una variable extra para contar.
    - Una desventaja de este metodo es que solo puede trabajar con while.
    - No siempre vamos a tener un valor que nos pueda indicar como termina, si trabajamos con un vector generico que toma cualquier numero entonces no tenemos ningun valor disponible fuera del rango.

----

## Recorrido

- Se tiene que ver, segun el ejercicio, si tenemos que hacer for, si es que hay que recorrerla toda, o un while, si solo tenemos que recorrer hasta cierto punto
- Si tratamos con una matrices, tendremos que ver las condiciones y considerar si es while while, while for, for for o for while si tenemos todo condicion, si hay que ver toda la fila pero no todas las columnas, etc.
- Se va a pedir seguido que se haga int si no se esta trabajando con un print

----

# Segunda Mitad de la clase

Se puede redifinir los tipos de datos 

typedef nos deja redefinir el tipo entero, asi, si por ejemplo hago esto:  

typedef int T_Padron;  

entonces a futuro, si mi variable padron cambia a futuro, cambio el typedef directamente  

#include <stdio.h>
#define MAX 7
#define PI 3.14
#define IVA 0.21

typedef int T_Padron;
typedef float T_precio;
typedef chat T_nota;
typedef int TVnum[MAX];  

int Mostrar(Tvnum Vec){}

int main(){
    nota Nota;
    TVnum vec;
    T_Padron padron;

    Mostrar(vec);
}

----

Memoria

Cuanto ocupa un vector?
Tamaño de Tipo Base * Cantidad de elementos del Indice
ej: 

----

TIPOS DE FUNCIONES

Una funcion es con tipo si su unico objetivo es devolver un valor   
Si tiene objetivo de interactuar con el usuario o algo mas, ya debe ser un void  
En las funciones tipadas (funcion que comienza con int, float, etc), tenemos que evitar que esta misma tenga mensajes y similares, son solo para devolver valores

Funciones void (Procedimientos): Realiza una accion que no sea devolver un valor, reciben y devuelven parametros, si reciben A, devuelven A, quiza cambiado, pero devuelven ese mismo


PASAJE DE PARAMETRO

Por Valor:
Pasamos una expresion, podemos pasar lo que queramos,
Por referencia:
Pasamos una variable, no podemos pasar un sistema de valores

Asi, una es cerrada, y si por ejemplo, a la misma variable, A, en el primer caso, la llamo por valor, entonces si le doy de valor A=9, en el main no se le cambiara el valor. En cambio, si se envia por referencia y le damos a A=1, entonces estamos alterando directamente el valor de A.