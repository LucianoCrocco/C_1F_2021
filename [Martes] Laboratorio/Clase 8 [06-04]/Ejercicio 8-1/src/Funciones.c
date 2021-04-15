/*
 * funciones.c
 *
 *  Created on: 12 abr. 2021
 *      Author: luciano
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "Funciones.h"

eJugador pedirDatos(void){

	eJugador miJugador;

	printf("Ingrese el nombre del jugador: ");
	__fpurge(stdin);
	scanf("%[^\n]",miJugador.nombre);

	printf("Ingrese la cantidad de goles: ");
	scanf("%d",&miJugador.goles);

	printf("Ingrese la cantidad de partidos: ");
	scanf("%d",&miJugador.partidosJugados);

	miJugador.promedioDeGoles = calcularPromedio(miJugador);


	return miJugador;
}

float calcularPromedio(eJugador miJugador){

	float promedio;

	promedio =(float) miJugador.goles / miJugador.partidosJugados;

	return promedio;


}

void mostrarJugador(eJugador miJugador){
	printf("Nombre del jugador: %s\n", miJugador.nombre);
	printf("Cantidad de goles: %d\n",miJugador.goles);
	printf("Cantidad de partidos: %d\n",miJugador.partidosJugados);
	printf("Promedio de goles: %.2f\n",miJugador.promedioDeGoles);
}
