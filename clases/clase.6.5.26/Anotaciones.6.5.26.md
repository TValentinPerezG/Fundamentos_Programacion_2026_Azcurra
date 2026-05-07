## Cadena de Caracteres en C

### Una cadena de caracteres en C, es un tipo particular de vector, que contiene elementos de tipo char, siendo el ultimo, el caracter '\0', que indica el final de nuestra cadena de caracteres
### Como hacemos con los arreglos en uno de los casos, podemos definir un maximo que definimos para la cadena de cuantos bytes reservamos para esta incluso si no los usamos. Uno de los bytes siempre debe ser \0
### El primer caracter siempre debe estar en la posicion 0

''|''|''|''|''|''|''|''|''|''

----

## Como declarar cadenas

hay varias formas  

- char cadena1[15] = "Hola Mundo 1";
reservamos 15 bytes, y le estamos indicando con comillas dobles la cadena inicial que queremos en nuestra cadena, y C le va a agregar el \0 luego del 1 por si mismo  

- char cadena2[] = "Hola Mundo 2";
en este caso no le damos un largo a la cadena, haciendo que el maximo se de por la cantidad de caracteres que le asignemos, que son la cantidad de caracteres que le asignamos, + un byte para el \0.  

- char cadena3[20];
en este caso lo hacemos sin asignacion, pero voy a tener que asignarlo de otra manera en el futuro.  

----

## Declaracion

supongamos que tenemos esta cadena y queremos ver su contenido:
char cadena[mf] = "Hola Mundo";

- Para ver toda la cadena, incluso espacios vacios  
for(i=0; i<\mf ;i++){  
    print("%c", cadena[i]);  
}  

- Para ver solo los espacios del vector con el texto de la cadena 
i = 0  
while (cadena[i] != \0){  
    printf("%c", cadena[i]);  
    i++;  
}  

(esto no accede a todos los caracteres, si luego agregamos un caracter a una posicion que estaba vacia en la declaracion no se tomara ya que este estara luego que \0).  

- Para solo ver la cadena sin revisar caracter por caracter:  
printf("%s", cadena);  


si no definimos un largo maximo y solo le damos un valor:
cadena2[] = "Hola Mundo";

y usamos un sizeof(cadena2), veremos que son exactamente 11 bytes, los visibles + \0

como ahora no tenemos un valor especifico para hacer de maximo, ahora lo que podemos usar es sizeof(cadena2)
for(i = 0; i < sizeof(cadena2); i++){
    printf("%c", cadena2[i]);
}

----

## fgets vs scanf

### En la catedra para leer/recibir una cadena, se va a pedir usar fgets
### se declara de la siguiente manera
fgets(variable, longitud(en entero), origen(siempre va a ser stdin));
se recomienda limpiar el buffer para evitar determinados inconvenientes
fflush(stdin);
fgets agrega un \n al final de los ingresos.

----

## Libreria string.h

- strlen: devuelve la longitud de una cadena
- strcpy: Permite asignar un valor nuevo a una cadena
- strcat: Permite concatenar valores a una cadena
- strcmp: Permite comparar 2 cadenas
- strstr: Busca una cadena dentro de otra cadena

la unica en la libreria que usamos generalmente es strcmp, las otras requieren la libreria string.h este declarada

se ejecutan de esta manera
- strlen(cadena1); (si es "hola" nos da un 4, incluso si tiene un maximo mayor)
- strcpy(cadena1, "nuevo contenido"); (el maximo debe poder contener este nuevo contenido)
- strcat(cadena1, cadena2) (si una tiene "hola" y la otra "mundo" nos da "hola mundo")
- strcmp(cadena1, cadena2) (da un valor segun el orden alfabetico de caracteres, si tienen el mismo contendio da 0, si cadena 1 esta antes alfabeticamente da >0, y si la cadena 2 esta antes da 0<)
- strstr(cadena1, cadena2) (nos devuelve un puntero si existe que va a apuntar a la parte luego de donde ocurre el comienzo de la subcadena, si no nos dara NULL)