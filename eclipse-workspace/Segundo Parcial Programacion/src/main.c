/******************************************************************************

Alumno: Luciano Agustin Crocco
Divison: F
Fecha: 28/07/2021

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "cafetera.h"

int main()
{
    setbuf(stdout,NULL);

    eCafetera* newCafetera;
	eCafetera* newCafeteraLectura;

	//FUNCION 1
    newCafetera = cafetera_newParametros(1, "Pepito", 1);

    if(newCafetera != NULL){
    	if(guardarBinario("cafetera.dab", newCafetera) == 0){
    		printf("\n\nError al guardar el archivo");
    	} else {
    		printf("\n\nArchivo guardado correctamente");
    	}
    }

    //FUNCION 2
    newCafeteraLectura = cafetera_new();

    if(newCafeteraLectura != NULL){
    	if(cargarYMostrarBinario("cafetera.dab", newCafeteraLectura) == 0){
    		printf("\n\nError al cargar el archivo");
    	} else {
    		printf("\n\nArchivo cargado correctamente");
    	}
    }

    return EXIT_SUCCESS;
}


