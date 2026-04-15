## Declaracion de Funciones Lenguaje C
  
____
  
### Metodologia a utilizar
  
Programacion Estructurada  
Programacion Modular  
  
#### Debe cumplir las siguientes reglas:
##### En cuanto a diseño estructurado
- Diseño Modular
    Tomamos nuestro problema y lo dividimos en problemas mas pequeños.
    Descomponemos el programa en modulos independientes.
- Diseño Descendente sobre los modulos
    Subdividir sucesivamente los modulos hasta que cada modulo tenga solo una tarea especifica a ejecutar.

##### En cuanto al teorema del programa estructurado
- Cada modulo debe estar codificado utilizando la estructuras de control básicas:
    - Secuenciales
    - Selectivas
    - Iterativas


#### Tenian 2 objetivos
-  Reducir tiempo requerido para [escribir], [verificar], [depurar], [mantener] nuestros programas, siendo asi mas faciles adaptarlos.
-  Reutilizacion del codigo, permieitiendo evitar codigo redundante, algo que se ve en el mal diseño.

###### Se conocia como programación sin GOTO 
  
____
  
### Representacion graficas de modulos
  
Buscamos representar como van a ser nuestros modulos y como van a interactuar entre si, usualmente como cajas.  
  
Si tenemos por ejemplo   
\*----------------------\*  
|                      |<---->Razon Social  
| Solicitar Ingreso    |<---->CUIL  
| Datos Clientes       |<---->Email  
|                      |  
\*----------------------\*  
Seria un modulo que reciba estos datos del usuario, y devolver a quien corresponda estos mismo datos.  
  
Otro caso podria ser una aplicacion que calcule deudas con datos recibidos.  
                    \*----------------------\*  
                    |                      |  
Deuda Actualizada<--| Solicitar Ingreso    |<----Importes Adeudados  
                    | Datos Clientes       |<----Tasa de Interes  
                    |                      |  
                    \*----------------------\*  
  
Un ejemplo mas seria un modulo que muestre datos con cierta estetica  
  
\*----------------------\*  
|                      |<----Razon Social  
| Solicitar Ingreso    |<----CUIL  
| Datos Clientes       |<----Email  
|                      |  
\*----------------------\*  
  
Todas estas presentaciones simplifican como vemos nuestro problema y su complejidad, permitiendonos llegar a la solucion de forma mas ordenada.  
  
Como resultado final llegariamos a un Diagrama completo, donde tenemos una gran cantidad de representaciones de distintas funcionalidades con un estilo top-down (diseño mas general a uno mas especifico, que se va dividiendo hasta llegar a una utilidad especifica)  

____

## Funciones que ya conocemos y nos provee C

#### Funciones
- scanf  | Permite el ingreso de datos
- printf | Permite imprimir elementos
- strlen | Devuelve la longitud de una cadena
- strcpy | Permite asignar un nuevo valor a una cadena
- strcat | Permite concatenar valores a una cadena
- strcmp | Permite comparar 2 cadenas
- strstr | Busco una cadena en otra cadena

Todos estas son funciones que C ya trae y son usadas comunmente  


____

## Declaracion de Funciones en C

El formato para declarar una funcion en C:  
*Tipo* A Devolver *Nombre* ( *Lista de Parametros Formales* )  
{  
    ..........................  
    .......................... <--- Bloque de codigo de la funcion  
    ..........................  
    
    return *Valor a retornar* ----> Puede o no retornar valores, omitirse o retornar None  
}  

### Diferencia entre Formales y Actuales

- Un parametro formal es aquel que se definen en la funcion o en el () de la funcion
- Un parametro actual es aquel que se menciona cuando se llama a la funcion

#### Declarar Lista de Parametros Formales en ()

[tipo] [\*][identificador1], [tipo] [\*][identificador2], ..., [tipo] [\*][identificadorN]

## Pasaje de Parametros

####  Por Valor
- Se entrega una copia del valor del parametro actual
- Ambos parametros utilizan distintas posiciones de memoria
- Si se modifica el parametro formal, no afectara al parametro actual
- Puedo hacer lo que quiera sin alterar el original, asi que es bueno para mostrar datos
- No es eficiente para devolver los parametros modificados

####    Por Referencia
- Se le pasa la posicion de Memoria donde esta guardado el valor, asi que si se hace un cambio dentro de la funcion, este se va a ver reflejado en el parametro actual.
- Se entraga una referencia (la direccion de memoria) al parametro actual
- Parametro Actual y Parametro Formal utilizan la misma posicion de memoria
- Hay determinadas estructuras en C que siempre se pasan por referencia por su tipo de estructura y tamaño.

____

##  Ejemplo

void leer_AB (int *a, int *b){  
    ................;  
    return  
}  
  
int main()  
{  
    int num1, num2;  
    .............  
    leer_AB(&num1, &num2);  
}  
  
Si vieramos la memoria, las variables num1 y a, num2 y b, estan todas compartiendo el mismo espacio de memoria, y por lo tanto cualquier modificacion a estas tambien modificaran las variables iniciales.

int calcular_C (int a, int b){  
    ................;  
    return;
}  
  
int main()  
{  
    int num1, num2;  
    long resultado;  
    ..........  
    leer_AB(&num1, &num2);  
    ..........  
    resultado = calcular_C(num1, num2);  
    ..........  
    return(0);  
}  
  
Si vieramos la memoria en esta caso, a y b se guardan en un espacio temporal distinto a donde estan guardados los valores de num1 y num2, espacio que luego se libera al terminarse de usar la funcion donde se declaran estos 2.


____

##  Anotaciones de la clase

#### Primero pensamos la solucion y diseño, y luego lo aplicamos en nuestro programa. Dividimos nuestro programa en problemas mas pequeños, y luego achicamos esos problemas mas pequeños, y asi sucesivamente, hasta llegar a una solucion especifica para ese problema en particular.

#### Generar codigo no redundante y evitar codigo que se repita constantemente en el programa.

#### Se busca mejorar tiempos en los programas, en la construccion, depuracion, etc.

#### Evitamos variables globales porque son malas practicas, cualquiera podria llamar sin querer variables declaradas por otros. Para evitar estos problemas, no se recomienda el uso de variables globales.