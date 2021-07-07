/*
 * main.c
 *
 *  Created on: 14 may. 2021
 *      Author: luciano
 */


#include <stdio_ext.h>
#include <stdlib.h>
#include "testing.h"


int main (void){
	setbuf(stdout,NULL);

	char string[STRING_LENGHT];

	if(get_String(string,"Ingrese un string: ", "Error... El maximo de caracteres permitidos es: ", 3, STRING_LENGHT)){
		printf("String: %s\n", string);
	} else {
		puts("\nError String\n");
	}

	char caracter;

	if(get_Char(&caracter, "Ingrese un caracter: ", "Error... El caracter ingresado es invalido: ", 32, 126, 3)){
		printf("Caracter: %c\n", caracter);
	} else {
		puts("\nError Caracter\n");
	}
/*
	int TEST;
	if(get_NumberInteger(&TEST, "Ingrese un numero: ", "Error..", 3)){
		printf("TEST");
	}
*/
	return EXIT_SUCCESS;
}
