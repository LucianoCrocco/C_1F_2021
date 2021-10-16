/******************************************************************************

Luciano Crocco 1ºF
Introduccion Memoria Dinamcia, Malloc y Calloc

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
		for(i=0;i<5;i++){
			mostrarUnElementoProductos(pUnProducto);
		}
    }

    return EXIT_SUCCESS;
}

