/*
 * Luciano Crocco 1ºF
 * Ejercicio 8-1
 *
	Crear la estructura Jugador (nombre, goles metidos, partidos jugados, promedio de goles).
	Crear una función que permita cargar los datos de un jugador y otra que los muestre.
	Una tercer función calculará el promedio de goles.


 */


#include <stdio_ext.h>
#include <stdlib.h>
#include "Funciones.h"



int main (void){

	eJugador jugadorUno;

	setbuf(stdout,NULL);

	jugadorUno = pedirDatos();

	mostrarJugador(jugadorUno);


	return EXIT_SUCCESS;
}


