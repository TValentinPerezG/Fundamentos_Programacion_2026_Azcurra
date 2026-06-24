Introduccion a la materia Fundamentos de Programacion Catedra Azcurra 2026 1er Cuatrimestre en progreso...
_____

# Buenas Practicas  
_____  

## General
- #### Armar modelo de respuesta teorico antes de comenzar a escribir codigo
- #### Intentar extenderse en cosas no pedidas por el ejercicio
- #### Declarar las variables a usar al inicio de nuestro main
- #### Los nombres de nuestras variables deben ser explicitos a lo que hacen, pero no demasiado extensas
- #### No usar breaks fuera de los switch
- #### No usar mas de un return en el main, solo return o return 0 al final
- #### Tener cuidado de no utilizar variables globales
- #### Evitar darle valor inicial a variables que no lo requieran
- #### Darle valor inicial a variables que se usen en condiciones o cuentas para no usar basura
- #### En el parcial, insertar las bibliotecas necesarias para el ejercicio
<br>

## Condicionales  
- #### Si estan relacionados, entonces es conveninente usar un if anidado para ahorrar pases en su interior  
- #### Agregar un valor inicial a las variables si se usan en condicional para no utilizar basura
- #### 
<br>

## Ciclos
- #### No usar un contador y un i del for a la vez, es redundante
- #### Si tenemos una cantidad de ciclos ya definida, utilizar for
- #### Si no sabemos cuantos ciclos usara el usuario, utilizar while
- #### Do while solo se recomienda para validar
- #### Si se trabaja con while o do while, tener cuidado de no hacer un ciclo infinito
<br>

## Funciones
- #### Declarar las variables al inicio del main
- #### No usar más de un return dentro de nuestra funcion, solo 1 al final
- #### Intentar separar tu programa en cada accion relevante para crear una funcion por cada accion, haciendolas reusables
- #### No hacer cuentas o condicionales innecesarias en funciones int o booleanas, puede hacer la condicion en el return
<br>

## Arreglos
- #### Declarar siempre el valor de maximo fisico en un typedef de nuestro vector/matriz
- #### En matrices, distinguir si este caso es de while-while, for-for, while-for o for-while segun la consigna
- #### Revisar si conviene revisar el arreglo de inicio a final o de final a inicio
<br>

## Ordenamiento y Busqueda
- #### Si se tiene una tabla ordenada, siempre utilizar busqueda binaria que es mucho mas eficiente
<br>

## Structs
- #### Utilizar el struct siempre como typedef
- #### Si se trabaja con tablas, hacer un segundo typedef conteniendo el anterior
<br>

## Archivos
- #### Parametros de FILEs siempre en el main, no dentro de la funcion.
- #### Abrir y cerrar los fclose y fopen en el misma lugar, ambos en la funcion, ambos en el main, etc.
- #### Para archivos de texto usar para la carga mayormente fprintf

## Memoria Dinamica
- #### Si tengo una memoria reservada con malloc, calloc o relloc, siempre ponerle un free luego en algun momento en cuanto se sabe que ya no se utilizaran.
- #### No hacer 2 frees del mismo espacio para no bloquear este espacio.
- #### Utilizar el sizeof para determinar el tamaño de una estructura.
- #### Cuando se utiliza malloc, validar que el puntero no sea Null, y poner un else para este caso.
- #### No hacer referencia a una memoria ya liberada por un free.
