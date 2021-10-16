/******************************************************************************

Luciano Crocco 1ºF
El uso de getters y setters permite encapsular.
Encapsular es cuando un elemento, un objeto. Oculta al exterior(otro objeto) como esta implementado.

La implementacion de estos conceptos nos va a permitir dejar de utilizar el ->
Es recomendable, por que se usa en el cuatri siguiente, usar this en vez de miProducto.

Los getters, salvo en una cadena, deben devolver el dato que buscamos. Lo dispuso la catedra.
Igual podemos usar esa forma, esta bien segun German.

*******************************************************************************/
#include <stdio_ext.h>
#include <stdlib.h>
#include "eProducto.h"


int main()
{
	eProducto* pUnProducto;

	int i;

    setbuf(stdout,NULL);

    pUnProducto = cargarProductoConParametros(1,"Coca Cola", 150.5, OCUPADO);

    if(pUnProducto != NULL){
		mostrarUnElementoProductos(pUnProducto);
    }

    return EXIT_SUCCESS;
}

