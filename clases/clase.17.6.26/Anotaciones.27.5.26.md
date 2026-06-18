# Clase 17 de Junio de 2026 Fundamentos de Programacion

## Agenda

- Repaso conceptos
- Pila de ejecucion
- Recursividad
- Bibliografia y preguntas

## Tema nuevo que entra siempre en finales

1 de recursividad
1 de memoria dinamica

Hasta ahora, trabajamos con variables estaticas, que tenian cierta posicion de memoria que podiamos trabajar con los punteros.

la memoria tiene 5 partes
- Pila(Stack), que se administra automaticamente por el sistema
- Memoria Libre
- Monticulo(Heap), que se administra manualmente
<br>
Estas 3 son dinamicas, y tanto el stack como el heap envian hacia la memoria libre, lo que si no tenemos memoria libre puede llevar al conocido stack overflow.

En esta clase nos vamos a concentrar en el stack y como funciona, y la clase siguiente veremos el Heap. Con el stack vamos a poder ver despues lo de la recursividad.
<br>

- Segmente de Datos
- Segmentos de Codigo

<br>

## Pila de Ejecucion

Es una estructura dinamica de datos LIFO (Last In, First Out), donde se guarda la informacion sobre las funciones que se estan ejecutando en cada momento.
Como vamos a ver mas adelante en el debugger, en C se administra automaticamente y -en realidad- la estamos utilizando desde que comenzamos a modularizar
<br>
Cada vez que se invoca una funciona, en "la pila" se almacena:
 - Variables locales de la funcion
 - Direccion de retorno
 - Parametros de invocacion
Se van apilando, asi, si una funcion llama a otra funcion, esta queda apilada sobre la primer funcion, y se van apilando de esta forma continuamente.

<br>
Lo que ocurre con la pila es que registra los valores de las variables, incluyendo si tienen valor basura.

## Recursividad

Muy util y practica para realizar procesos, pero consume mucha memoria.
- La recursividad (recursion en algunos textos) es una tecnica de programacion en el cual una funcion se invoca a si misma repetidamente.
- Es una alternativa diferente para implementar soluciones iterativas (estructuras de repeticion o ciclos)
<br>
Es muy peligrosa, pero en algunas situaciones soluciona muchos problemas.
<br>

### Componenets

Las funciones recursivas se componen de:

- Caso base: Una solucion simple para un caso particular (puede haber mas de un caso base).
- Caso recursivo: Una solucion que involucra volver a utlizar la funcion original, pero con parametros que se van acercando al caso base, ya que queres convenger a este mismo.

<br>

### Ejemplo

Escribir un programa que calcule el factorial (!) de un entero no negativo. Ejemplo  
0! = 1, 1! = 1, 2! = 2, 3! = 6, 4! = 24, 5! = 120, etc.  

Una funcion factorial iterativa seria asi:  

int factorial_iterativo(int num){  
    int i, fact = 1;  
    for (i=1;i<=num;i++){  
        fact = i * fact;   
    }  
    return fact;  
}  
<br>
El tema, es que la definicion matematica de factorial es la siguiente: N! es 1 si N=0 (caso base) o N*(N-1)! si N>0 (recursiva)  
  
Podemos pensarlo de esta manera:  
2! = 2x1!, 3! = 3x2!, 4! = 4x3!, etc  
<br>
si hacemos esta version recursiva, quedaria asi:  
int factorial(int numero){  
    if(numero == 0){  
        return 1;  
    }  
    return numero * factorial(numero - 1);  
  }
<br>
Esto nos lleva a casos con varios return, donde algunos nos devuelve al programa, y otro nos soluciona nuestro caso base.
Osea, no resuelve ninguno de los llamados hasta llegar al caso base, y asi con este caso base va solucionando uno a uno cada llamado previo.
<br>
El problema con esto es que debe utilizarse para tamaño pequeños, porque llena muchisimo el stack y consume muchos mas recursos.

### Beneficios


<br>
Un ejemplo es la serie de Fibonacci, la sucesion infinita de numeros de los 2 numeros anteriores.  
La recursiva es muy facil y elegante, y la recursiva es mucho mas facil, por la naturaleza recursiva de esta serie matematica

### Comparacion Recursividad y Iteracion

- Repeticion
    - Iteracion: ciclo explicito (se expresa claramente)
    - Recursividad: repetidas invocaciones de la funcion
- Terminacion
    - Iteracion: terminar el ciclo
    - Recursividad: se reconoce el caso base

#### Cuando conviene ser recursivo
- Para simplificar codigo
- Cuando la estructura de datos es recursiva, por ej: recorrido de arboles
#### Cuando no conviene ser recursivo
- Cuando los metodos usen arreglos largos
- Cuando el metodo cambia de manera impredecible de campos.
- Cuando las iteraciones sean la mejor opcion.

## En general, se debe usar la solucion recursiva solo cuando no exista una solucion iterativa simple. En el parcial se va a distinguir cual es el ejercicio en el que se va a evaluar la recursividad.