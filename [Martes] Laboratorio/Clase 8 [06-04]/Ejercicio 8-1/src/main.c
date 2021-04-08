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
#define LENGHT_STRING 100

typedef struct {

	char nombre[LENGHT_STRING];
	int goles;
	int partidosJugados;
	float promedioDeGoles;

}eJugador;

eJugador pedirDatos(void);

float calcularPromedio(eJugador miJugador);

void mostrarJugador(eJugador);


int main (void){

	eJugador jugadorUno;

	setbuf(stdout,NULL);

	jugadorUno = pedirDatos();

	mostrarJugador(jugadorUno);

	return EXIT_SUCCESS;
}

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
