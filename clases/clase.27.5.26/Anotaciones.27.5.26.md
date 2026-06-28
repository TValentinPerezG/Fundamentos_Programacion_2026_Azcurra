## Clase 27 de mayo de 2026 

- Repaso de tipos de datos vistos
- Arreglos
- Registros
- Tablas
- Bibliografia complementaria
- Preguntas

Tipos de Variables

Atomicas
Enteros, Reales, Caracteres, Definidos por el usuario/Enumerados, Booleanos

Estructuradas
- Arreglos
    - Unidimensionales (vectores)
    - multidimensionales (matrices)
- Cadena de caracteres (utiliza una libreria especial para comparaciones y ingresos, junto con un caracter especial para ver donde termina este)
- Registros
- Tablas
- Archivos
<br>
Los arreglos tienen un subindice que define su posicion y es numerado, inicia en 0 y se da por el lenguaje, y el tipo base que le da el usuario y que se mantiene para cada ingreso, y que conceptualmente debe ser lo mismo

El problema con esto es que si quiero almacenar la variedad de datos de, por ejemplo, un alumno, como todos los datos tienen que tener un tipo especifico y del datos del mismo concepto, tendriamos que hacer distintos vectores o matrices para el nombre, padron, email, notas, promedio, etc.

<br>

## Registro

Tambien llamada Records o Struct.
Nos permite crear una gran cantidad de campos todos relacionados con un solo alumno

Como trabajan:  
en c se llaman structs y se escriben de esta manera  
<br>
struct alumno{  
    char nombre[30];  
    int padron;  
    char email[50];  
    int notas[2];  
    float promedio;  
}  Alumno1 =  {
    "Miguel Lopez",
    23251,
    "mlopez@gmail.com",
    {8,7},
    7.5
};
para acceder a los campos de mi estructura, tengo que utilizar el nombre de la variable y un punto con el nombre del campo, seria asi: Alumno1.nombre para el nombre  
En futuros ingresos, tengo que poner solo struct alumno ya que el formato ya lo definimos
<br>
seria de esta manera: struct alumno Alumno2
para ingresar en el alumno 2, podemos hacer ingresos normales en el caso de numeros como enteros o float, por ej: Alumno2.notas[0] = 6;  
en el caso de los strings, tendriamos que declararle un strcpy con el campo al que queremos guardar y el texto, de esta forma: strcpy(Alumno2.nombre, "Nombres Alumno2");  
<br>
Lo que se debe hacer es hacer un typedef con nuestra estructura, haciendo que no tengamos que poner el structu por cada ingreso, mejorando la sintaxis, quedando de esta manera:  
typedef struct{
    char nombre[30];  
    int padron;  
    char email[50];  
    int notas[2];  
    float promedio;  
} talumno;  
y aqui lo llamariamos alumno Alumno2;, sin utilizar el struct.  
<br>
Con esto, soluciono el tener 5 variables sueltas sobre lo mismo, pero esto es solo para el caso de un solo "alumno", por lo que los registros no alcanzan, se necesitan tablas:

## Tablas

Estas serian una especie de vector pero de alumnos, usando la misma estructura pero con arreglos, algo de esta manera: alumno Alumnos[3];  
Para llamar a cada alumno de manera distinta sse utilizaria Alumnos[0].nombre;
<br>
Asi como los vectores normales, se pueden enviar las tablas como elemento a una funcion, y se enviara como referencia.  

