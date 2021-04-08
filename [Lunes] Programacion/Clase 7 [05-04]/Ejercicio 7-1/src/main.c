/*
 * Luciano Crocco 1ºF
 * Ejercicio 7-1
 *
Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
1 -> idProducto (numerico)
2 -> descripcion (alfanumérico)
3 -> nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
4 -> tipo (numérico, por el momento utilizaremos un define:  MAC - IPHONE - IPAD - ACCESORIOS)
5 -> precio (numérico decimal)

Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:

1 -> ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
2 -> BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
3 -> MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá modificar el precio o el tipo.
4 -> LISTADO Productos.
5 -> LISTADO ordenado por precio.
6 -> LISTADO ordenado por descripción.


 */

#include <stdio_ext.h>
#include <stdlib.h>

int main (void){

	setbuf(stdout, NULL);

	return EXIT_SUCCESS;
}

