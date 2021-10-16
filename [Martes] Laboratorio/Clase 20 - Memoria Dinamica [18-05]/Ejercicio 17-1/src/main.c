/******************************************************************************

Luciano Crocco 1ºF
Ejercicio 17-1

Realizar una función que retorne un puntero a eProducto.
Dentro de esta función deberá crear un producto hardcodeado, un puntero y se apuntará ese puntero al producto.
Mostrar el producto cargado 5 veces desde el main. Observar el comportamiento del programa.


*******************************************************************************/
#include <stdio_ext.h>
#include <stdlib.h>
#include "eProducto.h"


int main()
{
	eProducto unProducto;
	eProducto* pUnProducto;
	pUnProducto = &unProducto;

	int i;

    setbuf(stdout,NULL);

    pUnProducto = crearProductoHardcodeado();

    for(i=0;i<5;i++){
    	mostrarUnElementoProductos(pUnProducto);
    }

    return EXIT_SUCCESS;
}

