/*
 * Las funciones son  importantes porque ofrecen:
 * Modularizar
 * Reutilizacion
 * Independencia del codigo
 * Depuracion
 *
 */

/* 1º Instancia: Declaracion - Prototipo - Firma de la funcion
 *
 *	tipo_devuelto nombre (lista de parametros)
 *
 *	tipo_devuelto: int, char, float, void, double, etc.
 *	nombre: verbo + sustantivo
 *	lista de parametros: tipo + nombre de parametro
 *
 */
#include <stdio_ext.h>
#include <stdlib.h>

int sumarNumeros(int numeroUno, int numeroDos); //Parametros formales

int main (){

	int x;
	int y;
	int suma;
	int otraSuma;

	setbuf(stdout,NULL);
	printf("La direccion de memoria de un numero en el main es: %p\n",&x);

	printf("Ingrese un numero: ");
	scanf("%d",&x);

	printf("Ingrese otro numero: ");
	scanf("%d",&y);

	//3º Instancia: Llamada - Invocacion
	suma = sumarNumeros(x,y); // Parametros actuales
	printf("\nLa suma de los numeros es: %d", suma);

	otraSuma = sumarNumeros(18, 20);
	printf("\nLa otra suma de los numeros es: %d", otraSuma);

	return EXIT_SUECCESS;
}
//2º Instancia: Desarrollo - Implementacion - Logica
int sumarNumeros(int numeroUno, int numeroDos) //Parametros formales
{ // ambito o scope o alcance: Todo lo que se da en la implementacion de la funcion - Toda variable scope tiene alcanze en donde fue definida
	int resultado;

	printf("\nLa direccion de memoria de un numero en la funcion es:  %p\n",&numeroUno);

	resultado = numeroUno + numeroDos;

	return resultado;
}
