# Archivos

## Que son

Los archivos son a  

## Tipos

## Clasificacion segun modalidad de acceso

### Directo o Aleatorio
<br>
Nos permite a acceder a un elemento si sabemos su direccion en el archivo.
<br>

### Secuenciales
<br>
Estos son los unicos que vamos a trabajar en la materia.  
En estos, se trata con el archivo de elemento a elemento, empezando del puntero y ir leyendo los elementos de forma sucesiva hasta encontrar el fin de archivo.
<br>

- Tratamiento elemento a elemento
- Se debe comenzar por el primero de los elementos
- Solo podemos agregar elementos al final del archivo
- Los elementos existentes no los podemos alterar

### Codigo para archivos

- Declaracion de un puntero a una estrctura FILE: FILE *nom_var_punt
ej: File *archivo
<br>

- Apertura de archivo: fopen (ruta_y_archivo, modo_apertura(r, r+, w, a, b)) (el b es un acompañamiento)
ej: archivo = fopen("c:\datos\productos.dat","r+");
<br>

- Lectura de archivo: fread (puntero, tamaño, cantidad, dir_archivo)
ej: fred (&registro, sizeof(registro), 1, archivo)
<br>

- Escritura de archivo: fwrite (puntero, tamaño, cantidad, dir_archivo)
ej: fwrite (&registro, sizeof(registro), 1, archivo)
<br>

- Control de fin de archivo: int feof(FILE *fichero)
ej: while(!feof(archivo))
<br>

- Cierre de archivo. int fclose (File *fichero)
ej: fclose(archivo)  
<br>
se recomienda abrir y cerrar el archivo solo una vez por sistema.

## Archivos de texto

Son muy similares a los binarios, solo que no usan la b al abrir el archivo, y trabaja distinto en los casos de escribir y leer, dando 3 opciones para cada uno:

- lectura
    - fgetc (puntero al archivo), muestra cada caracter, es la mejor para mostrar literalmente el texto
    - fgets (cadena destino, cantidad de bytes, puntero al archivo), muestra por cadenas de cierto tamaño, para grupos de texto
    - fscanf (puntero al archivo, cadena destino) muestra con separaciones entre cada cadena de palabras separadas por un espacio
- escritura
    - fputc (caracter, puntero al archivo), va agregando caracter por caracter hasta el ingreso de uno especifico, agrega un \n al inicio por o que sigue una fila luego.
    - fputs (cadena, puntero al archivo), intenta ingresar toda una cadena a la vez, y luego devuelve si fue exitoso o no, lo agrega como va sin \n por lo que se pone justo al lado de lo previo.
    - fprintf (puntero al archivo, cadena), devuelve tambien la cantidad de caracteres que se ingresaron, pone un \n al inicio y al final.
<br>
en escritura se recomienda el fprintf

