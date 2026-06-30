/*
Una farmacia dispone de un archivo binario llamado medicamentos.dat, cuyos registros tienen la siguiente estructura:

código (entero)
categoría (cadena de hasta 25 caracteres, ej. "analgésicos", "antibióticos", etc.)
nombre_comercial (cadena de hasta 30 caracteres)
stock_actual (entero) El archivo no está ordenado y no entra completamente en memoria.
Desarrollar un programa modular que permita:

Solicitar al usuario una categoría.
Generar una tabla en memoria llamada medxcat que contenga todos los medicamentos de esa categoría.
La tabla debe tener la misma estructura que el archivo original.
Suponer que la tabla tiene como máximo 200 registros y entra en memoria.
Mostrar por pantalla los medicamentos de medxcat cuyo stock_actual sea superior al stock promedio dentro de esa categoría.
*/