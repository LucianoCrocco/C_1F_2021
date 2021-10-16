/*
 *	Luciano Crocco 1ºF
 *	Ejercicio 4-2
 *
 *	Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit, validando que las temperaturas ingresadas estén entre el punto de congelación y ebullición del agua para cada tipo de escala.
 *	Las validaciones se hacen en una biblioteca.
 *	Las funciones de transformación de fahrenheit a celsius y de celsius a fahrenheit se hacen en otra biblioteca.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include "Validaciones.h"


int main(void){

	char opcion;
	float temperatura;
	float temperaturaContraria;

	setbuf(stdout,NULL);

	opcion=pedirOpcion("¿En que escala desea calcular? Para Fahrenheit presione la \"F\" para Celcius presione la \"C\": ", "Error... Ingrese una escala valida - ¿En que escala desea calcular? Para Fahrenheit presione la \"F\" para Celcius presione la \"C\": ");

	switch(opcion){
		case 'C':
			temperatura = pedirTemperatura("Ingrese una temperatura valida de Celsius entre 0ºC y 100ºC: ", "Error en la validacion de la temperatura... ", 0, 100);
			temperaturaContraria = trasnformarTemperatura(opcion,temperatura);
			mostrarResultado("Usted utilizo la escala Celsius en este caso", "Fahrenheit", temperatura, temperaturaContraria);
			break;
		case 'F':
			temperatura = pedirTemperatura("Ingrese una temperatura valida de Fahrenheit entre 32ºC y 212ºC: ", "Error en la validacion de la temperatura... ", 32, 212);
			temperaturaContraria = trasnformarTemperatura(opcion,temperatura);
			mostrarResultado("Usted utilizo la escala Fahrenheit en este caso", "Celsius", temperatura, temperaturaContraria);
			break;
	}
	return EXIT_SUCCESS;
}

