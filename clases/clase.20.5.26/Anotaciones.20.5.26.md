# Metodos de Ordenamiento de arreglos

## Burbujeo - Burbujeo Optimizado

### Objetivo:  
Ordenar los elementos de vector, comparando en pasadas sucesivas, aquellos elementos que son adyacentes  

- paso 1
Supongamos que tenemos el vector 23, 10, 31, 9
Empezamos y se hace un intercambio de elementos en las posicion 0 y 1
pasa a ser 10, 23, 31, 9
hacemos otra revision ahora entre 1 y 2, como ya estan ordenados no intercambiabos  
ahora hacemos comparacion entre 2 y 3, vemos que estan al reves, asi que los intercambiamos
pasa a ser 10, 23, 9, 31 (vector resultado)
con la primer pasada el elemento mas grande (31) pasa a estar en la ultima posicion
- paso 2
obtenemos una sub lista de nuestro arreglo con la posicion del 0 al 2 solamente, al ya tener al 31 en su lugar
al hacer el mismo proceso, el 0 y el 1 no cambian porque 10 es menor a 23
comparando 1 y 2 vemos que 23 es mayor que 9 y se hace el intercambio
pasa a ser 10, 9, 23 (vector resultado 2)
el 23 pasa a ser elemento ordenado tambien junto con 31.  
- paso 3
nos queda un sub arreglo solo con los elementos de la posicion 0 y 1
hacemos la comparacion, como 10 es mayor a 9, hacemos el intercambio
obtenemos 9, 10, 23, 31, (ya siendo este vector ordenado).  

como tenemos un vector de 4 elementos, hacemos 3 pasos de 3 comparaciones, luego de 2 comparaciones, y luego 1 comparacion.  

#### Resumen: 
Para un vector con N elementos a ordenar, seran necesarios N - 1 pasos.  
y la cantidad de comparaciones en el paso sera igual a N - el Nro del paso.  

- Se puede optimizar

si tenemos un caso en el que por ejemplo tenemos este vector en el segundo paso
9, 10, 23, 31.  
no tendria sentido hacer luego de este el tercer paso porque ya tenemos todos los valores ordenados, por lo que nos gustaria optimizarlo.  
para esto, nos gustaria usar un while en el lugar de los pasos, no para las comparaciones.  
Para ver si hubo cambios o no, nos conviene usar una variable booleana que tiene 2 estados, o hubo un intercambio o no.  

## Seleccion

### Objetivo:

Ordenar los elementos del vector, buscando el minimo elemento entre una posicion i y la posicion final, e intercambiar el minimo con el elemento de la posicion i.  
<br>
A diferencia del anterior donde obteniamos el mayor en la ultima de las posicion, en este metodo obtenemos el menor de los elementos en la primera posicion, el siguiente mas pequeño en la segunda y asi sucesivamente.
<br>
si tomamos el mismo vector inicial {23, 10, 31, 9}

- paso 1

Establezco la posicion 0 como el minimo y comparo con los siguientes
comparo la posicion 0 con la 1, como 10 es menor a 23, vario la posicion del minimo, y voy haciendo esa comparacion continuamente hasta llegar al mayor mas minima, siendo 9, y hago el intercambio entre la posicion del 9 y la inicial.  

## Insercion

### Objetivo:

Ordenar los elementos del vector, tomando un elemento y comparandolo contra los anteriores ya ordenados, deteniendose cuando se cuentra uno menor y entonces es alli donde se inserta, desplazando el resto de los elementos mayores  
Partimos de un arreglo con un solo elemento en la posicion 0, y el siguiente que iria a la posicion 1, y intento agregarlo a ese sub arreglo con solo la posicion 0, comparandolo con los menores en ese sub arreglo que suponemos ya esta ordenado.  
<br>
si tomamos el mismo vector inicial {23, 10, 31, 9}  

- paso 1
creo un sub arreglo solo con la primer posicion, en este caso tomo 23

- paso 2
agarro el primer elemento a insertar y lo preservo por separado hacia atras  
comparo el elemento de la posicion 1 con las anteriores, o sea en este momento 0
como 10 es menor a 23 y no hay mas elementos a comparar, pongo al 23 en la posicion del 10, y en la posicion del 23 pongo el 10 que preserve previamente  
si no fuera el principio del arreglo, seguiria comparando el 10

- paso 3
agarro el nuevo elemento en la posicion 2 y lo comparo con el mas alto del sub arreglo que se esta ordenado, como el 31 no es menor al 23, me detengo en la primera posicion y no desplazo nada

- paso 4
agarro el elemento de la posicion 2 y lo preservo, y lo empiezo a comparar desde atras, como 9 es menor a 31, desplazo el 31 a la posicion del 9
comparo el 9 con el 23, como el nueve es menor, desplazo el 23 a la posicion del 31
finalmente comparo 9 a 10, como de nuevo es menor, muevo el 10 a la posicion del 23
como llegue al limite inferior de posiciones, agrego el 9 a la ultima posicion del arreglo ordenado.

### Algoritmo

- Vamos a recorrer todo el vector A comenzando desde la posicion inicial del vector + 1 porque el primero ya lo consideramos ordenado, esto hasta la ultima posicion
- Para cada elemento A[i], se trata de ubicar en el lugar correcto el elemento A[i] en cuestion, entre los elementos anteriores: A[i-1], A[i-2], ..., A[inicial].  
- Dada la posicion actual i, el algoritmo se basa en que los elementos A[inicial], ..., A[i-2], A[i-1] ya estan ordenados

-----

# Busqueda simple o lineal

## Busqueda simple o lineal

Si tenemos este arreglo {10, 15, 6, 8, 23, 32}  
La forma mas basica seria utilizar un while con una flag y empezar a revisar el vector desde la posicion inicial hasta que encontremos este numero o se termine el vector, y luego devolver ya sea el numero o la posicion o lo que sea necesario para el ejercicio.
<br>
Esta es la manera mas basica

## Que pasa si tengo un arreglo ordenado?

## Busqueda binaria

Agrega mucha eficiencia y elimina muchas busquedas innecesarias
<br>
Para estas, establezco un elemento central, si no hay un centro exacto tomamos un elemento que esta a una posicion del centro, por ejemplo, en este caso {6, 8,10, 15, 23, 32} tomariamos al 10 como centro.

El metodo consiste en comparar el elemento central con el valor que busco, y pregunto si coincide con el elemento central, y si no lo hace, vemos si es mayor o menor a este elemento central, y asi sabremos si buscar solo en los mayores o solo en los menores.  
Asi, si buscamos por ejemplo el 32, sabemos que tenemos que buscar un elemento en una posicion mayor al 10. 
Repetimos este proceso, ahora desde busco los valores con el elemento central entre los elementos que quedan, osea 15, 23, 32, siendo el central el 32, y asi vemos si es igual, mayor o menor al 23. Como es mayor, repetimos el proceso, y ahi encontramos que solo nos queda 32 como opcion, asi, en vez de revisar los 6 elementos, podemos encontrar el 32 en solo 3 busquedas.  
<br>
Tambien es mas eficiente con elementos que no estan en nuestro arreglo, ya que en vez de buscar todos los lugares, los va rompiendo para encontrar el grupo y llega a que no esta mas rapido
